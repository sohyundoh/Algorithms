#include <iostream>

using namespace std;

int P;
void step(int tc, int* height){
    int flag = 0;
    for(int i = 0; i< 20; i++){
        for(int j = 0; j<i; j++){
            if(height[j] > height[i]) flag ++;
        }
    }
    cout<< tc <<" "<<flag<<"\n";
}
int main(){
    cin >> P;
    for(int i = 0; i< P; i++){
        int tc;
        int* height = new int[20];
        cin >> tc;
        for(int j = 0; j<20; j++){
            cin>> height[j];
        }
        step(tc, height);
    }
    return 0;
}
