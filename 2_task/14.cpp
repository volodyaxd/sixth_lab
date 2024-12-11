#include <iostream>

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
                    head = temp->next; // Если удаляется голова
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

int main() {
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

    return 0;
}
