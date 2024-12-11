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
    std::list<int> L;
    int n, value;

    std::cout << "Введите количество элементов в списке: ";
    std::cin >> n;

    std::cout << "Введите " << n << " элементов:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        L.push_back(value);
    }

    keepFirstOccurrences(L);

    
    std::cout << "Список после удаления дубликатов: ";
    for (int x : L) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
