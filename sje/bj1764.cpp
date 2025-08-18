#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::unordered_map<std::string, int> not_heard;

    for (int i = 0; i < N; i++) {
        std::string person;
        std::cin >> person;
        not_heard[person]++;
    }

    std::vector<std::string> not_heard_seen;

    for (int i = 0; i < M; i++) {
        std::string person;
        std::cin >> person;
        if (not_heard.find(person) != not_heard.end()) {
            not_heard_seen.push_back(person);
        }
    }
    
    std::sort(not_heard_seen.begin(), not_heard_seen.end());

    std::cout << not_heard_seen.size() << "\n";

    for (std::string& person : not_heard_seen) {
        std::cout << person << "\n";
    }
    
    return 0;
}