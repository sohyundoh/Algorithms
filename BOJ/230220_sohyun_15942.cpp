#include <iostream>
#include <algorithm>


using namespace std;
typedef long long ll;

int heap[200001]; //1-based -> 부모 idx 를 i 라고 하면 자식은 2i 와 2i+1 이다.
int n,k,p; //노드 수, heap[p]에 k가 와야한다.
int upnum, downnum; //k의 조상노드의 숫자 중 min, k의 자손 노드의 숫자 중 max
int heapnum=0; 

void dfs(int idx){ //k의 자손 채우기
    downnum++;
    if(downnum>n){ 
        cout<<-1;
        exit(0);
    }
    heap[idx]=downnum;
    if(idx*2 <=n) dfs(idx*2);
    if(idx*2+1 <= n) dfs(idx*2+1);
}
void flip(int idx){ //flip
    while(idx>1){
        if(heap[idx]<heap[idx/2]) swap(heap[idx], heap[idx/2]);
        idx/=2;
    }
}
void insert(int idx){ //k의 조상,자손 말고 나머지 채우기
    heapnum++;
    if(heapnum==upnum) heapnum=downnum+1;
    heap[idx]=heapnum;
    flip(idx); //조상에 나보다 더 큰 수 있으면 flip
    if(idx*2 <=n) insert(idx*2);
    if(idx*2+1 <=n) insert(idx*2+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k>>p;

    // k 있는곳의 부모, 자식 채우고, 사용한 숫자의 최소값upnum 최대값downnum 저장
    downnum=k-1;
    dfs(p); // heap[p]=k; 자손 채우기
    upnum=k;
    while(p/2>0){ // k의 조상 채우기
        p/=2, upnum--;
        heap[p]=upnum;
    }
    if(upnum<=0){ //예외처리
        cout<<-1;
        return 0;
    }

    // 배열순회하면서 안채워진곳(0인곳)을 1부터 heapnum++하며 채워준다.
    // 근데 그수가 최소값이나 최대값이면 다른수로. 그리고 필요시 flip처리
    for(int i=1; i<=n; i++){
        if(heap[i]) continue; //이미 채워져있으면 패스(k의 조상or자손인 경우)
        insert(i); //heap[i]와 그 노드의 자손들을 다 채워오자
    }

    //출력
    for(int i=1; i<=n; i++) cout<<heap[i]<<'\n';
    return 0;
}
