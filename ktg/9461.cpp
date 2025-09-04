#include <iostream>
#include <vector>

using namespace std;

int main(){
//4번째 삼각형의 변의 길이는 1번째 + 3번째 삼각형
//5번째 삼각형의 변의 길이는 4번째 삼각형의 길이

//6번째 삼각형의 변의 길이는 1번째 + 5번째
//7번째 삼각형의 변의 길이는 2번째 + 6번째
//8번째 삼각형의 변의 길이는 3번째 + 7번째
//9번째 삼각형의 변의 길이는 4번째 + 8번째
//10번째 삼각형의 변의 길이는 5번째 + 9번째
//11번째 삼각형의 변의 길이는 6번째 + 10번째
//12번째 삼각형의 변의 길이는 7번째 + 11번째


    vector<long long> padovan = {1,1,1,2,2};
    for(int i = 0 ; i< 100; i++){
        padovan.push_back(padovan[i] + padovan[i+4]);
    }
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int M;
        cin >> M;
        cout << padovan[M-1] << endl;
    }
    


}