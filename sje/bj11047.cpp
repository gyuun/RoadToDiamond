#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> wallet(N);
    for (int i = 0; i < N; i++) {
        std::cin >> wallet[i];
    }
    auto it = std::find_if(wallet.begin(), wallet.end(), [&](const int& coin){
        return coin > K;
    });
    wallet.erase(it, wallet.end());
    int total_count = 0;
    for (auto it = wallet.rbegin(); it != wallet.rend(); it++) {
        int count = K / *it;
        total_count += count;
        K -= (*it) * count;
    }
    std::cout << total_count;
    return 0;
}