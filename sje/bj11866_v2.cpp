#include <iostream>
#include <queue>
#include <vector>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::queue<int> circle;
    std::vector<int> result;
    int count = 0;
    for (int i = 1; i < N + 1; i++) {
        circle.push(i);
    }
    while (true) {
        for (int i = 0; i < K; i++) {
            int extracted = circle.front();
            circle.pop();
            if (i != K - 1) circle.push(extracted);
            else    result.push_back(extracted);
        }
        if (result.size() == N)  break; 
    }

    std::cout << "<";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i != result.size() - 1) std::cout << ", ";
    }
    std::cout << ">";

    return 0;
}