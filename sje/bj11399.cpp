#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> time_list(N);
    for (int i = 0; i < N; i++) {
        std::cin >> time_list[i];
    }
    std::sort(time_list.begin(), time_list.end());
    int formal_total = 0;
    int current_total = 0;
    for (const auto& time : time_list) {
        formal_total += time;
        current_total += formal_total;
    }
    std::cout << current_total;
    return 0;
}