#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>


using namespace std;

int main(){
    // DP로 풀 수 있을 것 같은데
    // I 번째 색상을 선택할 때는 I-1번째 색상만 빼고 진행하면 된다.
    // 어찌 됐던 자기 직전의 2개 값을 더한걸 비교해서 작은걸 선택하면 되는것 아닌가?


    int N;
    int R, G, B;
    vector<int> state(3); // 현재 상태
    vector<int> temp_state(3); // 입력받는 용
    vector<int> old_state(3); // 이전 상태

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    cin >> state[0] >> state[1] >> state[2];

    for (int i = 1; i < N; i++){
        
        cin >> temp_state[0] >> temp_state[1] >> temp_state[2];
        
        for(int j = 0; j < 3; j++){
            int other1 = (j + 1) % 3;
            int other2 = (j + 2) % 3;
            
            old_state[j] = (state[other1] < state[other2]) ? state[other1] + temp_state[j] : state[other2] + temp_state[j];
        }

        copy(old_state.begin(), old_state.end(), state.begin());

    }

    cout << min({state[0], state[1], state[2]}) << endl;

}