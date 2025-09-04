#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>


using namespace std;

void dfs(int n, int m, vector<int> current_index, vector<int> current, vector<int> vec){
    // base case
    // 배열의 길이가 m과 같다면 출력하고 끝
    if(current.size() == m){
        for(int num : current){
            cout << num << " ";
        }
        cout << endl;
    }
    
    // body

    // recur case
    // 인덱스로 push back 후 재귀 호출
    else{
        for(int i = 0; i < n; i++){
            auto res = find_if(current_index.begin(), current_index.end(), [i](int num){return num ==i;});
            
            if(res == current_index.end()){
                vector<int> new_current_index = current_index;
                new_current_index.push_back(i);
                vector<int> new_current = current;
                new_current.push_back(vec[i]);
                dfs(n, m, new_current_index, new_current, vec);
                
            }
            
            

        }
    }


}


int main(){
    // 1 <= m <= n <= 8
    // m은 벡터위를 뛰노는 말이다. n 이 8, m이 4라고 하면
    // O O O O
    // 1 2 3 4 5 6 7 8

    // 가장 끝 O가 움직인다. 그리고 출력

    // O O O   O
    // O O O     O
    // O O O       O
    // O O O         O

    // 마지막 O 가 끝에 도달하면 세번째 O가 움직이며 마지막의 O는 세번째 O의 옆에서 다시 시작한다.

    // O O   O O

    // 앞에 중복되는 숫자가 많다. DP로 해결해야한다.
    // 1,2,3, 4  | 1,2,3, 5 | 1,2,3, 6
    // 1,2,4, 5 | 1,2,4, 6
    // 1,2,5, 6
    // 1,3,4, 5 | 1,3,4, 6
    // 1,3,5, 6
    // 1,4,5, 6
    // 2,3,4, 5 | 2,3,4, 6
    // 


    // M - 1 개를 고정 시켜두고 남은 자리의 숫자를 바꾼다. 
    // M - 1 개를 가져오는 로직 하나와 마지막 자리를 바꾸는 로직 하나로 구성되어야한다.
    // M - 1 개를 가져와서 -> 마지막 자리 채우는 로직을 수행
    // 헌데, M - 1 개를 가져오는 로직은 M - 2개를 가져오는 로직과 또 M - 1번째 자리를 채우는 로직으로 구성된다.
    // 재귀의 냄새가 난다.
    // DFS다.
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    vector<int> empty;
    dfs(n, m, {}, empty, vec);

    

}