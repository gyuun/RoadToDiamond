#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

int main(){
    int N, line, start, end;
    map<int, vector<int>> network;

    cin >> N >> line;

    for(int i = 0; i < N; i++){
        network.insert({i+1, {}});
    }

    for(int i = 0; i < line; i++){
        cin >> start >> end;
        network[start].push_back(end);
        network[end].push_back(start);
    }

    //bfs 오랜만에 한번 해보자

    queue<int> bfs_queue;
    set<int> visited;

    bfs_queue.push(1);
    visited.insert(1);

    while(!bfs_queue.empty()){

        int q = bfs_queue.front();
        bfs_queue.pop();

        for(const auto& p : network[q]){
            if(visited.find(p) == visited.end()){
                //방문한게 아니면
                bfs_queue.push(p);
                visited.insert(p);
            }
        }
    }



    cout << visited.size() - 1<< endl;

}