#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M;
    std::cin >> M;
    unsigned int N = 0;

    for (int i = 0; i < M; i++) {
        std::string command;
        unsigned int x;
        std::cin >> command;
        if (command == "all") {
            N = ~(~0 << 20);
        }
        else if (command == "empty") {
            N = 0;
        }
        else {
            std::cin >> x;
            if (command == "add") {
                N = N | (1 << (x-1));
            }
            else if (command == "remove") {
                N = N & ~(1 << (x-1));
            }
            else if (command == "toggle") {
                N = N ^ (1 << (x-1));
            }
            else if (command == "check") {
                if (N & (1 << (x-1))) {
                    std::cout << 1 << "\n";
                }
                else    std::cout << 0 << "\n";
            }
        }
    } 
    return 0;
}