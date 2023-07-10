#include <iostream>

using namespace std;
int fibonacci[46] = {0,1,1};
int main(){
    int n;
    cin >> n;
    for(int i =3; i<= n;i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    cout << fibonacci[n];
    return 0;
}
