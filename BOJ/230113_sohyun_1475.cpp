#include <iostream>
#include <cmath>
#define MAX 6
using namespace std;

int numOfDigit = 1;
int digit[MAX] = {0,};
void numToArray(int N){
    if(N / 100000 > 0){
        numOfDigit = 6;
    }else if(N/10000 > 0){
        numOfDigit = 5;
    }else if(N/1000>0){
        numOfDigit = 4;
    }else if(N/100>0){
        numOfDigit = 3;
    }else if(N/10>0){
        numOfDigit = 2;
    }
    for( int i = numOfDigit-1; i>=0;i--){
        digit[i] = N/(int)pow(10,i);
        N %= (int)pow(10,i);
        /*cout<< digit[i] << " ";*/
    }
    /*cout<< "\n";*/
}
int stickerNum(){
    int sticker[10] = {0, 0, 0, };
    int num = 1;
    for(int i = 0; i<numOfDigit;i++){
        /*for(int j = 0; j<10; j++){
            cout<<sticker[j]<<" ";
        }
        cout<<"\n";
        cout<<num<<endl;*/
        if((digit[i] == 6) && (sticker[digit[i]] == 1) && sticker[9] == 0) {
            sticker[9] = 1;
            continue;
        }else if((digit[i] == 6) && (sticker[digit[i]] == 1) && sticker[9] == 1){
            for(int j = 0; j<10;j++){
                sticker[j] = 0;
            }
            sticker[6] = 1;
            num ++;
            continue;
        }
        if((digit[i] == 9) && (sticker[digit[i]] == 1) && sticker[6] == 0){
            sticker[6] = 1;
            continue;
        }else if((digit[i] == 9) && (sticker[digit[i]] == 1) && sticker[6] == 1){
            for(int j = 0; j<10;j++){
                sticker[j] = 0;
            }
            sticker[9] = 1;
            num ++;
            continue;
        }
        if(sticker[digit[i]] == 1){
            for(int j = 0; j<10;j++){
                sticker[j] = 0;
            }
            sticker[digit[i]] = 1;
            num ++;
        }else{
            sticker[digit[i]] = 1;
        }
    }
    return num;
}
int main(){
    int N;
    cin>>N;
    numToArray(N);
    cout<<stickerNum();
    return 0;
}
