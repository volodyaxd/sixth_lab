#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>

int main() {
    // Настройка кодировки консоли, если необходимо
    std::setlocale(LC_ALL, ""); // Устанавливаем локаль по умолчанию

    std::wstring text;
    std::set<wchar_t> firstLetters; // Множество для хранения уникальных первых букв

    std::wcout << L"Введите текст на русском языке: ";
    std::getline(std::wcin, text); // Считываем весь текст

    std::wistringstream stream(text);
    std::wstring word;

    // Разбиваем текст на слова
    while (stream >> word) {
        // Находим первую букву слова
        wchar_t firstChar = word[0];

        // Проверяем, является ли символ буквой
        if (std::iswalpha(firstChar)) {
            // Приводим к нижнему регистру для уникальности
            firstLetters.insert(std::towlower(firstChar));
        }
    }

    // Выводим уникальные буквы
    std::wcout << L"С каких букв начинаются слова: ";
    for (wchar_t letter : firstLetters) {
        std::wcout << letter << L" ";
    }
    std::wcout << std::endl;

    return 0;
}
