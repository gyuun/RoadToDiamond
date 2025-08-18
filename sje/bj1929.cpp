#include <iostream>
#include <vector>
#include <numeric>

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int M, N;
    std::cin >> M >> N;
    std::vector<int> vec(N - M + 1);
    std::iota(vec.begin(), vec.end(), M);
    for (int &num : vec) {
        if (is_prime(num)) {
            std::cout << num << "\n";
        }
    }
    return 0;
}