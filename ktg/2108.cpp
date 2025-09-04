#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


int main(){
    // 산술평균
    // 중앙값
    // 최빈값 (여러개 있을 때는 최빈 값 중 두 번째로 작은 값을 출력)
    // 범위

    // 4,000 * 500,000 = 2,000,000,000

    // 합을 받는 변수는 int로 충분함.

    // 범위는 최댓값과 최솟값을 필요로함.

    // 최빈값은 맵을 써야함
    // { 빈도수 : [숫자, ] } 이형태로하면 빈도가 늘어날때마다 찾아서 없애고, 다음 키의 값에 추가하는 작업이 필요함
    // 최대 빈도 값을 관리하는 리스트를 둔다.
    // 이 리스트안에 있는 값중 하나가 있으면, 최대 빈도 값 리스트는 초기화 된다.

    // 중앙값은 어떻게 하지? 
    // 모든 수를 둘것인가? 메모리가 되나 4바이트 * 500,000개 메모리는 충분하네

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, totalSum, temp;
    int currentMostFrequents = 0;

    vector<int> values;
    map<int, int> frequency;

    vector<int> mostFrequents;

    cin >> N;
    totalSum = 0;

    for(int i = 0; i < N; i++){
        cin >> temp;
        totalSum += temp;
        
        if(find(values.begin(), values.end(), temp) == values.end()){
            //없으면
            frequency.insert({temp, 1});
        }

        else{
            // 있으면
            frequency[temp] = frequency[temp] + 1;
            
        }
        values.push_back(temp);

        if (frequency[temp] == currentMostFrequents) mostFrequents.push_back(temp);
        else if(frequency[temp] > currentMostFrequents) {
            mostFrequents = {temp,};
            currentMostFrequents = frequency[temp];
        }
        
    }

    sort(values.begin(), values.end());
    sort(mostFrequents.begin(), mostFrequents.end());

    cout << floor((double)totalSum / (double)N + 0.5)<< endl;
    cout << values[(N-1)/2] << endl;

    if(mostFrequents.size() == 1){
        cout << mostFrequents[0] << endl;
    }
    else{
        cout << mostFrequents[1] << endl;
    }
    
    cout << values[N-1] - values[0] << endl;

}