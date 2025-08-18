#include <iostream>
#include <vector>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<bool> visited(N+1, false);
    std::vector<int> result;
    int rotation = K;
    int count = 0;
    while (true) {
        for (int i = 1; i < N + 1; i++) {
            if (visited[i] == true) {
                continue;
            }
            else {
                count++;
            }
            if (count == rotation) {
                visited[i] = true;
                result.push_back(i);
                count = 0;
            }
        }
        if (result.size() == N) break;
    }
    std::cout << "<";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << ">";

    return 0;
}