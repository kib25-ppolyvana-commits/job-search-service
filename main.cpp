#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "Structures.h"

void showMenu() {
    std::cout << "=== СЕРВІС ПОШУКУ РОБОТИ ===\n";
    std::cout << "1. Переглянути всі вакансії\n";
    std::cout << "2. Пошук вакансій за зарплатою\n";
    std::cout << "3. Вихід\n";
    std::cout << "Оберіть дію: ";
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Створюємо початкову базу вакансій для демонстрації
    std::vector<Vacancy> vacancies;

    vacancies.push_back({ 1, "C++ Developer", "SoftServe", "Розробка системного ПЗ, знання ООП", 45000.0 });
    vacancies.push_back({ 2, "Python QA Engineer", "EPAM", "Автоматизація тестування, написання скриптів", 35000.0 });
    vacancies.push_back({ 3, "Cybersecurity Analyst", "CyberGuard", "Моніторинг безпеки мереж, аналіз логів", 50000.0 });

    int choice = 0;
    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 3) {
            std::cout << "Дякуємо за використання сервісу!\n";
            break;
        }

        switch (choice) {
        case 1: {
            std::cout << "\n--- СПИСОК ВСІХ ВАКАНСІЙ ---\n";
            for (size_t i = 0; i < vacancies.size(); ++i) {
                std::cout << "ID: " << vacancies[i].id << "\n";
                std::cout << "Посада: " << vacancies[i].title << "\n";
                std::cout << "Компанія: " << vacancies[i].companyName << "\n";
                std::cout << "Опис: " << vacancies[i].description << "\n";
                std::cout << "Зарплата: " << vacancies[i].salary << " грн\n";
                std::cout << "-----------------------\n";
            }
            std::cout << "\n";
            break;
        }
        case 2: {
            double minSalary = 0;
            std::cout << "\nВведіть мінімальну заробітну плату для пошуку: ";
            std::cin >> minSalary;

            std::cout << "\n--- РЕЗУЛЬТАТИ ПОШУКУ ---\n";
            bool found = false;
            for (size_t i = 0; i < vacancies.size(); ++i) {
                if (vacancies[i].salary >= minSalary) {
                    std::cout << "ID: " << vacancies[i].id << "\n";
                    std::cout << "Посада: " << vacancies[i].title << "\n";
                    std::cout << "Компанія: " << vacancies[i].companyName << "\n";
                    std::cout << "Зарплата: " << vacancies[i].salary << " грн\n";
                    std::cout << "-----------------------\n";
                    found = true;
                }
            }
            if (!found) {
                std::cout << "Вакансій із такою або більшою зарплатою не знайдено.\n";
            }
            std::cout << "\n";
            break;
        }
        default:
            std::cout << "\nНеправильний вибір. Спробуйте ще раз.\n\n";
            break;
        }
    }
    return 0;
}