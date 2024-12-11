#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

struct Student {
    std::string lastName;
    std::string firstName;
    int score;
};

int main() {
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

    // Если нет учеников из школы № 50
    if (students.empty()) {
        std::cout << "Нет учеников из школы № 50." << std::endl;
        return 0;
    }

    // Сортируем учеников по баллам
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score; 
    });

    // Определяем наивысший балл
    int maxScore = students[0].score;
    int countMaxScore = 0;

    // Считаем количество учеников с наивысшим баллом
    for (const auto& student : students) {
        if (student.score == maxScore) {
            countMaxScore++;
        }
    }

    // Выводим результаты в зависимости от количества учеников с наивысшим баллом
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

    return 0;
}
