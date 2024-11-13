#include <iostream>
#include <string>

class ElectronicLock {
private:
    bool isLocked;      // Статус блокировки
    bool isPowered;     // Питание
    int attemptCount;   // Счетчик неудачных попыток
    const int maxAttempts = 3; // Максимум попыток до блокировки

publi:
    // Конструктор по умолчанию
    ElectronicLock() : isLocked(true), isPowered(false), attemptCount(0) {}

    // Конструктор с параметрами
    ElectronicLock(bool locked, bool powered) : isLocked(locked), isPowered(powered), attemptCount(0) {}

    // Метод включения питания
    void powerOn() {
        if (!isPowered) {
            isPowered = true;
            std::cout << "Замок включен.\n";
        } else {
            std::cout << "Замок уже включен.\n";
        }
    }

    // Метод выключения питания
    void powerOff() {
        if (isPowered) {
            isPowered = false;
            std::cout << "Замок выключен.\n";
        } else {
            std::cout << "Замок уже выключен.\n";
        }
    }

    // Метод для блокировки
    void lock() {
        if (isPowered) {
            isLocked = true;
            std::cout << "Замок заблокирован.\n";
        } else {
            std::cout << "Включите питание перед блокировкой.\n";
        }
    }

    // Метод для разблокировки с проверкой попыток
    void tryUnlock(const std::string& code) {
        if (!isPowered) {
            std::cout << "Включите питание перед разблокировкой.\n";
            return;
        }

        if (attemptCount >= maxAttempts) {
            std::cout << "Превышено количество попыток. Замок временно заблокирован.\n";
            return;
        }

        std::string correctCode = "1234"; // Правильный код

        if (code == correctCode) {
            isLocked = false;
            attemptCount = 0;
            std::cout << "Замок успешно разблокирован.\n";
        } else {
            attemptCount++;
            std::cout << "Неверный код. Осталось попыток: " << maxAttempts - attemptCount << "\n";
        }
    }

    // Метод для сброса попыток
    void resetAttempts() {
        attemptCount = 0;
        std::cout << "Счетчик попыток сброшен.\n";
    }

    // Метод отображения текущего состояния
    void displayStatus() const {
        std::cout << "Статус замка: " << (isLocked ? "Заблокирован" : "Разблокирован") << "\n";
        std::cout << "Питание: " << (isPowered ? "Включено" : "Выключено") << "\n";
        std::cout << "Неудачные попытки: " << attemptCount << "\n";
    }
};
int main() {
    ElectronicLock lock;
    int choice;
    std::string code;

    do {
        std::cout << "\n--- Меню замка ---\n";
        std::cout << "1. Включить замок\n";
        std::cout << "2. Выключить замок\n";
        std::cout << "3. Заблокировать замок\n";
        std::cout << "4. Разблокировать замок\n";
        std::cout << "5. Сбросить счетчик попыток\n";
        std::cout << "6. Показать состояние замка\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                lock.powerOn();
                break;
            case 2:
                lock.powerOff();
                break;
            case 3:
                lock.lock();
                break;
            case 4:
                std::cout << "Введите код для разблокировки: ";
                std::cin >> code;
                lock.tryUnlock(code);
                break;
            case 5:
                lock.resetAttempts();
                break;
            case 6:
                lock.displayStatus();
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}

