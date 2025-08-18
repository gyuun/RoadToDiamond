#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    
    queue<int> q;
    vector<int> result;
    stringstream ss;

    for(int i = 1; i < N+1; i++){
        q.push(i);
    }

    int count = 0;

    while(!(q.empty())){
        int temp = q.front();
        q.pop();
        count ++;
        if(count >= K) {
            result.push_back(temp);
            count = 0;
        }
        else q.push(temp);
        
    }
    
    ss << "<";
    for(int i = 0; i < result.size() - 1; i++){
        ss << result[i] << ", ";
    } ss << result[result.size() - 1] << ">";

    cout << ss.str() << endl;
}