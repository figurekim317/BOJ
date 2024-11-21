#include <iostream>
using namespace std;

int main()
{
    int N;
    int A[1000];
    cin >> N;

    for(int i=0; i < N; i++){
        cin >> A[i];
    }
    long sum = 0;
    long max = 0;

    for(int i; i<N; i++){
        if(A[i] > max){
            max = A[i];
        }
    sum = sum + A[i];
    }


double result = sum*100.0 / max/N;
cout << result << "\n";
}


// 시험을 본 과목의 수
// 과목 데이터 저장
// for{ 최고점 점수 판별 저장 총점 계산

}