#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시작시간 기준 정렬한 다음 회의시간이 짧은것 pick
/*
 * 회의시간이 짧다는 것 :
 * 회의가 빨리 끝난다.
 * 회의가 적게 걸린다.
 */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int>> time;
    vector<pair<int, int>> time_table;
    int N;
    cin >> N;

    for(int i = 0; i< N; i++){
        int s,e;
        cin >> s >> e;
        time.push_back({s,e});
    }
    sort(time.begin(), time.end());
    // 정렬 : cmp 함수 없이 sort(v.begin(), v.end())로 해주면, first를 기준으로 정렬된다.

    time_table.push_back({time[0].first, time[0].second});
    int end_time = time[0].second;

    for(int i = 1; i< N; i++){
        if(time[i].second < end_time){
            end_time = time[i].second;
            // 만약 이 회의가 더 빨리 끝날 경우 => 이 회의로 지정.
            time_table.pop_back();
            time_table.push_back({time[i].first,time[i].second});
            continue;
        }
        if(time[i].first >= end_time) {
            end_time = time[i].second;
            time_table.push_back({time[i].first,time[i].second});
        }
    }
    cout << time_table.size();
    return 0;
}
