#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <locale>
#include <codecvt>
#include <algorithm>

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

void first() {
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


}

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void add(int d) {
        Node* newNode = new Node(d);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void remove(int d) {
        Node* temp = head;
        while (temp) {
            if (temp->data == d) {
                if (temp->prev) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next; 
                }
                if (temp->next) {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void swapNeighborsIfNeeded(int E) {
        Node* current = head;
        while (current) {
            if (current->data == E) {
                if (current->prev && current->next && (current->prev->data != current->next->data)) {
                    int temp = current->prev->data;
                    current->prev->data = current->next->data;
                    current->next->data = temp;
                }
            }
            current = current->next;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void second() {
    DoublyLinkedList dll;
    int n, value;

    std::cout << "Введите количество элементов в списке: ";
    std::cin >> n;

    std::cout << "Введите элементы списка:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        dll.add(value);
    }

    std::cout << "Исходный список: ";
    dll.printList();

    std::cout << "Введите значение элемента для замены соседей: ";
    std::cin >> value;
    
    dll.swapNeighborsIfNeeded(value);
    
    std::cout << "Список после замены соседей элемента со значением " << value << ": ";
    dll.printList();


}

void third() {
    int n; 
    int m; 

    std::cout << "Введите количество работников: ";
    std::cin >> n;

    std::cout << "Введите количество языков: ";
    std::cin >> m;

    
    std::vector<std::string> languages(m);
    for (int i = 0; i < m; ++i) {
        std::cout << "Введите язык " << i + 1 << ": ";
        std::cin >> languages[i];
    }

    
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


}

void fourth() {
    
    std::setlocale(LC_ALL, ""); 

    std::wstring text;
    std::set<wchar_t> firstLetters; 

    std::wcout << L"Введите текст на русском языке: ";
    std::getline(std::wcin, text); 

    std::wistringstream stream(text);
    std::wstring word;

    
    while (stream >> word) {
        
        wchar_t firstChar = word[0];

        
        if (std::iswalpha(firstChar)) {
            
            firstLetters.insert(std::towlower(firstChar));
        }
    }

    
    std::wcout << L"С каких букв начинаются слова: ";
    for (wchar_t letter : firstLetters) {
        std::wcout << letter << L" ";
    }
    std::wcout << std::endl;


}

struct Student {
    std::string lastName;
    std::string firstName;
    int score;
};

void fifth() {
    std::vector<Student> students;
    int numberOfStudents;

    std::cout << "Введите количество учеников: ";
    std::cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; ++i) {
        Student student;
        std::string school;

        std::cout << "Введите фамилию, имя, школу и балл ученика " << (i + 1) << ": ";
        std::cin >> student.lastName >> student.firstName >> school >> student.score;

        if (school == "50") {
            students.push_back(student);
        }
    }

    
    if (students.empty()) {
        std::cout << "Нет учеников из школы № 50." << std::endl;

    }

    
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score; 
    });

   
    int maxScore = students[0].score;
    int countMaxScore = 0;

    
    for (const auto& student : students) {
        if (student.score == maxScore) {
            countMaxScore++;
        }
    }

    
    if (countMaxScore > 2) {
        std::cout << "Количество учеников с наивысшим баллом: " << countMaxScore << std::endl;
    } else if (countMaxScore == 1) {
        std::cout << "Лучший ученик: " << students[0].lastName << " " << students[0].firstName << std::endl;
    } else {
        std::cout << "Лучшие ученики:" << std::endl;
        for (int i = 0; i < countMaxScore; ++i) {
            std::cout << students[i].lastName << " " << students[i].firstName << std::endl;
        }
    }


}

int main() {
    int choice;

    do {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. first\n";
        std::cout << "2. second\n";
        std::cout << "3. third\n";
        std::cout << "4. fourth\n";
        std::cout << "5. fifth\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                first();
                break;
            case 2:
                second();
                break;
            case 3:
                third();
                break;
            case 4:
                fourth();
                break;
            case 5:
                fifth();
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор, попробуйте снова." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
