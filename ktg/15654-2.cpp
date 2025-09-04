#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int n, m;
vector<int> a;          // 입력 수열(정렬됨)
vector<int> pick;       // 현재까지 고른 수
vector<char> used;      // 사용 여부
ostringstream out;      // 출력 버퍼

void dfs(int depth){
    if (depth == m){
        for (int i = 0; i < m; ++i){
            out << pick[i] << (i + 1 == m ? '\n' : ' ');
        }
        return;
    }
    for (int i = 0; i < n; ++i){
        if (used[i]) continue;
        used[i] = 1;
        pick.push_back(a[i]);
        dfs(depth + 1);
        pick.pop_back();
        used[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    used.assign(n, 0);
    dfs(0);

    cout << out.str();
    return 0;
}
