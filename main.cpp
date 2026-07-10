
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
    std::cout << "4. [Роботодавець] Додати нову вакансію\n";
    std::cout << "5. [Кандидат] Відгукнутися на вакансію\n";
    std::cout << "6. [Роботодавець] Переглянути отримані резюме\n";
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
            case 4:
            addVacancyByEmployer(vacancies);
            break;
        case 5: {
            static std::vector<Application> applications; // Вектор для збереження відгуків
            applyForVacancy(applications);
            break;
        }
        case 6: {
            static std::vector<Application> applications; 
            viewApplications(applications);
            break;
        }
        default:
            std::cout << "\nНеправильний вибір. Спробуйте ще раз.\n\n";
            break;
        }
    }
    return 0;
}
// Виконано: Полівана Поліна

void addVacancyByEmployer(std::vector<Vacancy>& vacancies) {
    Vacancy newVacancy;
    newVacancy.id = vacancies.size() + 1;

    std::cin.ignore(); 
    std::cout << "\n--- РЕЖИМ РОБОТОДАВЦЯ: СТВОРЕННЯ ВАКАНСІЇ ---\n";
    std::cout << "Введіть назву посади: ";
    std::getline(std::cin, newVacancy.title);

    std::cout << "Введіть назву компанії: ";
    std::getline(std::cin, newVacancy.companyName);

    std::cout << "Введіть опис вакансії: ";
    std::getline(std::cin, newVacancy.description);

    std::cout << "Введіть заробітну плату (грн): ";
    std::cin >> newVacancy.salary;

    vacancies.push_back(newVacancy);
    std::cout << "\n[Система] Вакансію успішно додано роботодавцем!\n\n";
}

void applyForVacancy(std::vector<Application>& applications) {
    Application newApp;
    
    std::cout << "\n--- ВІДГУК НА ВАКАНСІЮ ---\n";
    std::cout << "Введіть ID вакансії, яка вас зацікавила: ";
    std::cin >> newApp.vacancyId;
    
    std::cin.ignore(); 
    std::cout << "Введіть ваше повне ім'я: ";
    std::getline(std::cin, newApp.candidateName);
    
    std::cout << "Введіть текст вашого резюме / супровідний лист: ";
    std::getline(std::cin, newApp.resumeText);
    
    newApp.status = "На розгляді"; 
    
    applications.push_back(newApp);
    std::cout << "\n[Система] Ваш відгук успішно надіслано роботодавцю!\n\n";
}

void viewApplications(const std::vector<Application>& applications) {
    std::cout << "\n--- СПИСОК ОТРИМАНИХ ВІДГУКІВ (РЕЗЮМЕ) ---\n";
    if (applications.empty()) {
        std::cout << "Наразі немає жодного відгуку від кандидатів.\n\n";
        return;
    }
    
    for (size_t i = 0; i < applications.size(); ++i) {
        std::cout << "Відгук №" << i + 1 << "\n";
        std::cout << "ID вакансії: " << applications[i].vacancyId << "\n";
        std::cout << "Кандидат: " << applications[i].candidateName << "\n";
        std::cout << "Резюме / Лист: " << applications[i].resumeText << "\n";
        std::cout << "Статус: " << applications[i].status << "\n";
        std::cout << "-----------------------\n";
    }
    std::cout << "\n";
}
// Додано: Камєнєнко Анастасія

