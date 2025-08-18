#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<int> my_deck(N);
    for (int i = 0; i < N; i++) {
        std::cin >> my_deck[i];
    }
    std::sort(my_deck.begin(), my_deck.end());

    int M;
    std::cin >> M;

    for (int i = 0; i < M; i++) {
        int y;
        std::cin >> y;
        auto lower = std::lower_bound(my_deck.begin(), my_deck.end(), y);
        auto upper = std::upper_bound(my_deck.begin(), my_deck.end(), y);
        
        int count = std::distance(lower, upper);
        std::cout << count << " ";
    }
    return 0;
}