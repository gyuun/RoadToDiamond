#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    
    vector<int> vec(N);
    vector<int> result;
    stringstream ss;

    std::iota(vec.begin(), vec.end(), 1);

    //러너가 한칸씩 움직여야 하나??

    int runner = 0;
    int runner_count = 1;
    for(int i = 0; i < N; i++){
        while(runner_count < K){
            runner++;
            if(runner == N) runner = 0;

            if(vec[runner] > 0) runner_count++;
        }
        runner_count = 0;
        result.push_back(vec[runner]);
        vec[runner] = -1;
    }
    
    ss << "<";
    for(int i = 0; i < result.size() - 1; i++){
        ss << result[i] << ", ";
    } ss << result[result.size() - 1] << ">";

    cout << ss.str() << endl;
}