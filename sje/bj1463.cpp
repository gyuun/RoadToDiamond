#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> dp(N+1, 0);

    for (int i = 2; i < N+1; i++) {
        
        dp[i] = dp[i-1] + 1;
        
        if (i % 2 == 0) {
            dp[i] = std::min(dp[i], dp[i/2] + 1);
        }

        if (i % 3 == 0) {
            dp[i] = std::min(dp[i], dp[i/3] + 1);
        }
    }

    std::cout << dp[N];
    
    return 0;
}