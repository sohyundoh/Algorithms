#include <iostream>
#include <string>
using namespace std;
int main(){
    string input;
    cin >> input;
    int result = 0;
    string num;
    bool minusFlag = false;
    for(int i = 0; i<=input.length();i++){
        if( input[i] == '+' || input[i] == '-' || i == input.size()){
           if(minusFlag){
                result -= stoi(num);
                num = "";
           }else{
                result += stoi(num);
                num = "";
           }
        }
        else{
            num += input[i];
        }
        if(input[i] == '-'){
            minusFlag = true;
        }
    }
    cout << result;
    return 0;
}
