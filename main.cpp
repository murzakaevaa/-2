/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)


 Дан дек D с нечетным количеством элементов N (≥ 5). Добавить в начало дека пять
его средних элементов в исходном порядке. Использовать один вызов функции-члена insert. */

#include "deque_utils.h"

int main() {
    setlocale(LC_ALL, "ru");
    int choice;

    std::cout << "Выберите метод ввода данных:\n"
        << " 1.Ввод с клавиатуры  \n"
        << " 2.Случайные числа \n"
        << " 3.Чтение из файла\n"
        << std::endl;

    // FIX_ME: Добавлена проверка на корректный ввод выбора
    //cin >> choice;
    choice = safe_input("");

    std::deque<int> deque;

    try {
        switch (choice) {
        case 1:
            deque = func_keyboard();
            break;
        case 2: {
            int count;
            std::cout << "Введите количество чисел (нечетное и >= 5): ";
            // FIX_ME: Заменен прямой cin на безопасный ввод
            //cin >> count;
            count = safe_input("");
            while (count < 5 || count % 2 == 0) {
                std::cout
                    << "Кол-во должно быть нечетным и >= 5. Повторите ввод: ";
                // FIX_ME: Заменен прямой cin на безопасный ввод
                //cin >> count;
                count = safe_input("");
            }
            deque = func_random(count);
            break;
        }
        case 3: {
            deque = func_file();
            break;
        }
        default:
            std::cerr << "Некорректный выбор." << std::endl;
            return 1;
        }

        std::cout << "Исходный дек: ";
        for (const auto& elem : deque) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;


        // FIX_ME: Добавлен вывод в обратном порядке с обратными итераторами
        std::cout << "Исходный дек в обратном порядке: ";
        for (auto rit = deque.rbegin(); rit != deque.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;

        func_insert(deque);

        std::cout << "Дек после вставки: ";
        for (const auto& elem : deque) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}