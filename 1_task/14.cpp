#include <iostream>
#include <list>
#include <set>

void keepFirstOccurrences(std::list<int>& L) {
    std::set<int> seen;
    auto it = L.begin();
    while (it != L.end()) {
        if (!seen.insert(*it).second) {
            it = L.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
    std::list
    <int> L = {1, 2, 2, 3, 3, 4};
        keepFirstOccurrences(L);
        for (int x : L) std::cout << x << " ";
        return 0;
    }
