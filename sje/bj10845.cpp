#include <iostream>
#include <queue>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::cin.ignore();
    std::queue<int> queue;
    for (int i = 0; i < N; i++) {
        std::string command;
        std::cin >> command;
        if (command == "push") {
            int X;
            std::cin >> X;
            queue.push(X);
        }
        else if (command == "pop") {
            if (queue.empty())  std::cout << -1 << "\n";
            else {
                std::cout << queue.front() << "\n";
                queue.pop();
            }
        }
        else if (command == "size") {
            std::cout << queue.size() << "\n";
        }
        else if (command == "empty") {
            if (queue.empty())  std::cout << 1 << "\n";
            else    std::cout << 0 << "\n";
        }
        else if (command == "front") {
            if (queue.empty())  std::cout << -1 << "\n";
            else    std::cout << queue.front() << "\n";
        }
        else if (command == "back") {
            if (queue.empty())  std::cout << -1 << "\n";
            else    std::cout << queue.back() << "\n";
        }
    }
    return 0;
}