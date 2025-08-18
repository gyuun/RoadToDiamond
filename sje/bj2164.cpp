#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::deque<int> card_list;
    for (int i = 1; i < N+1; i++) {
        card_list.push_back(i);
    }
    
    while (card_list.size() > 1) {
        card_list.pop_front();
        int put_in_card = card_list.front();
        card_list.pop_front();
        card_list.push_back(put_in_card);
    }
    std::cout << card_list.front();
    return 0;
}