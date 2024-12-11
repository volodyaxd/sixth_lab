#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    int n; // Количество работников
    int m; // Количество языков

    std::cout << "Введите количество работников: ";
    std::cin >> n;

    std::cout << "Введите количество языков: ";
    std::cin >> m;

    // Массив языков
    std::vector<std::string> languages(m);
    for (int i = 0; i < m; ++i) {
        std::cout << "Введите язык " << i + 1 << ": ";
        std::cin >> languages[i];
    }

    // Массив знаний языков для каждого работника
    std::map<std::string, std::vector<bool>> knowledge;
    for (int i = 0; i < n; ++i) {
        std::string name;
        std::cout << "Введите имя работника " << i + 1 << ": ";
        std::cin >> name;

        std::vector<bool> knows(m, false);
        for (int j = 0; j < m; ++j) {
            std::cout << "Знает ли " << name << " язык " << languages[j] << " (1 - да, 0 - нет)? ";
            int answer;
            std::cin >> answer;
            knows[j] = (answer == 1);
        }

        knowledge[name] = knows;
    }

    // Найдем работников, которые знают все языки, которые знает другой работник
    for (const auto& worker1 : knowledge) {
        for (const auto& worker2 : knowledge) {
            if (worker1.first == worker2.first) continue;

            bool knowsAll = true;
            for (int i = 0; i < m; ++i) {
                if (worker2.second[i] && !worker1.second[i]) {
                    knowsAll = false;
                    break;
                }
            }

            if (knowsAll) {
                std::cout << worker1.first << " знает все языки, которые знает " << worker2.first << std::endl;
            }
        }
    }

    return 0;
}
