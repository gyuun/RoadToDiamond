#include <iostream>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    
    std::unordered_map<int, int> counts;
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        counts[x]++;
    }

    int M;
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int y;
        std::cin >> y;
        if (counts.count(y)) {
            std::cout << counts[y] << " ";
        }
        else {
            std::cout << 0 << " ";
        }
    }
    return 0;
}