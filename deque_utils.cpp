#include "deque_utils.h"

// FIX_ME: Добавлена функция для безопасного ввода целого числа
int safe_input(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        }
        else {
            std::cout << "Ошибка: введите целое число!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
// void FuncInsert(deque<int>& D) {
void func_insert(std::deque<int>& deque) {
    size_t size = deque.size();

    // Вычисляем индекс среднего элемента
    size_t middle_index = size / 2;

    // Получаем пять средних элементов

    //FIX_ME: Использован конструктор дека с итераторами (вместо цикла for)
    /**deque<int> MiddleElements;
    for (size_t i = MiddleIndex - 2; i <= MiddleIndex + 2; ++i)
    {
        MiddleElements.push_back(D[i]);
    }*/

    std::deque<int> middle_elements(
        deque.begin() + (middle_index - 2),
        deque.begin() + (middle_index + 3));

    // Вставляем пять средних элементов в начало дека
    deque.insert(deque.begin(), middle_elements.begin(), middle_elements.end());
}

// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
// deque<int> FuncKeyboard() {
std::deque<int> func_keyboard() {
    int count;
    // FIX_ME: Заменен прямой cin на безопасный ввод
    /*cout << "Введите количество целых чисел (нечетное и >= 5): ";
    cin >> count;*/
    count = safe_input("Введите количество целых чисел (нечетное и >= 5): ");

    while (count < 5 || count % 2 == 0) {
        std::cout << "Количество должно быть нечетным и >= 5. Повторите ввод: ";
        // FIX_ME: Заменен прямой cin на безопасный ввод
        //cin >> count;
        count = safe_input("");
    }

    std::deque<int> deque;
    std::cout << "Введите " << count << " целых чисел:" << std::endl;
    for (int i = 0; i < count; ++i) {
        int number;
        // FIX_ME: Заменен прямой cin на безопасный ввод
        //cin >> number;
        number = safe_input("");
        deque.push_back(number);
    }

    return deque;
}

// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
// deque<int> FuncRandom(int count) {
std::deque<int> func_random(int count) {
    // FIX_ME: Гарантируем нечетное количество
    if (count % 2 == 0) {
        count++;
        std::cout << "Количество изменено на " << count << " (для нечетности)"
            << std::endl;
    }
    std::deque<int> deque;
    std::srand(static_cast<unsigned>(std::time(0)));

    for (int i = 0; i < count; ++i) {
        deque.push_back(std::rand() % 100);
    }

    return deque;
}

// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
// deque<int> FuncFile() {
std::deque<int> func_file() {
    std::deque<int> deque;
    std::ifstream infile("a.txt");
    int number;

    if (!infile.is_open()) {
        throw std::runtime_error("Не удалось открыть файл.");
    }

    while (infile >> number) {
        deque.push_back(number);
    }

    if (deque.size() < 5 || deque.size() % 2 == 0) {
        throw std::invalid_argument("Кол-во чисел в файле должно быть нечетным и >= 5.");
    }

    return deque;
}