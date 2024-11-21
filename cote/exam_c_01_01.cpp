#include <iostream>
using namespace std;

int main(){
    int N = 0;
    string numbers;
    cin >> N;
    cin >> numbers;

    int sum = 0;
    for(int i=0; i<numbers.length(); i++){
        sum += numbers[i] -'0';
    }
    cout << sum << "\n";
}