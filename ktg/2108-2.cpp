#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    // “입력되는 정수의 절댓값은 4000을 넘지 않는다”는 점
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, totalSum, temp;

    vector<int> values;
    vector<int> frequency(8001, 0); //0 은 0, 1은 -4000 , 2는 -3999, .. temp + 4000 + 1

    cin >> N;
    totalSum = 0;

    for(int i = 0; i < N; i++){
        cin >> temp;
        totalSum += temp;
        
        if(temp == 0) frequency[0]++;
        else frequency[temp+4001]++;

        values.push_back(temp);
    }

    int currentMostFrequents = 0;
    vector<int> mostFrequency;

    for(int i = 0; i < 8002; i++){
        if(frequency[i] > currentMostFrequents){
            if(i == 0) mostFrequency = {0,};
            else mostFrequency = {i-4001,};
            currentMostFrequents = frequency[i];
            
        }
        else if( frequency[i] == currentMostFrequents){
            if (i == 0) mostFrequency.push_back(0);
            else mostFrequency.push_back(i-4001);
        }
        else{
            continue;
        }
    }


    sort(values.begin(), values.end());
    sort(mostFrequency.begin(), mostFrequency.end());
    cout << floor((float)totalSum / (float)N + 0.5)<< endl;
    cout << values[(N-1)/2] << endl;

    if(mostFrequency.size() == 1){
        cout << mostFrequency[0] << endl;
    }
    else{
        cout << mostFrequency[1] << endl;
    }
    
    cout << values[N-1] - values[0] << endl;
}