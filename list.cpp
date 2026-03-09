#include "list.h"

// Конструктор Node
Node::Node(int value) : data(value), next(nullptr) {}

// Конструктор LinkedList
LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::add(int value) {
  Node* newNode = new Node(value);
  if (head == nullptr) {
    head = newNode;
  }
  else {
    Node* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }
}

// Метод для вставки значения M перед каждым вторым элементом
// FIX_ME: Имена методов должны быть в lower_case_with_underscores 
// void insertBeforeEverySecond(int M) {
void LinkedList::insert_before_every_second(int M) {

  // FIX_ME: Добавлена проверка на пустой список
  if (head == nullptr) return;

  Node* current = head;
  int position = 1;                  // Счетчик для отслеживания позиции

  while (current != nullptr && current->next != nullptr) {
    if (position % 2 == 1) {       // Если текущий элемент — первый в паре
      Node* newNode = new Node(M); // Создаем новый узел со значением M
      newNode->next = current->next; // Новый узел указывает на следующий элемент
      current->next = newNode; // Текущий узел указывает на новый узел
      current = newNode->next; // Переходим к следующему элементу
      position += 2;
    }
    else {
      current = current->next;
    }
    // FIX_ME: Исправлен счетчик для корректной работы
    // count++
    position++;
  }
}

void LinkedList::print() const {
  // FIX_ME: Добавлена проверка на пустой список при выводе
  if (head == nullptr) {
    std::cout << "Список пуст" << std::endl;
    return;
  }
  Node* current = head;           // Начинаем с головы списка
  while (current != nullptr) {    // Пока не дойдем до конца списка
    std::cout << current->data << " "; // Выводим данные текущего узла
    current = current->next;    // Переходим к следующему узлу
  }
  std::cout << std::endl;        // Переход на новую строку после вывода
}

// Метод для получения указателя на последний элемент списка
// FIX_ME: Имена методов должны быть в lower_case_with_underscores 
// Node* getLastNode() {
Node* LinkedList::get_last_node() const {
  // FIX_ME: Добавлена проверка на пустой список
  if (head == nullptr) return nullptr;

  Node* current = head;           // Начинаем с головы списка
  while (current != nullptr && current->next != nullptr) { // Идем до последнего узла
    current = current->next;
  }
  return current;                 // Возвращаем указатель на последний узел
}

// FIX_ME: Имена методов должны быть в lower_case_with_underscores
// void clearList() {
void LinkedList::clear_list() {
  while (head != nullptr) {       // Пока список не пуст
    Node* temp = head;          // Сохраняем текущую голову
    head = head->next;          // Перемещаем голову на следующий узел
    delete temp;                // Удаляем узел
  }
  std::cout << "Список очищен." << std::endl;
}

// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
void insert_before_every_second(LinkedList& list, int M) {
  list.insert_before_every_second(M);
}

// Функция для безопасного ввода целого числа
// FIX_ME: Добавлена функция для безопасного ввода целого числа
// Старый код: прямой cin без проверок
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

// Функция для безопасного ввода положительного числа
// FIX_ME: Добавлена функция для безопасного ввода положительного числа
int safe_positive_input(const std::string& prompt) {
  int value;
  while (true) {
    value = safe_input(prompt);
    if (value > 0) {
      return value;
    }
    else {
      std::cout << "Ошибка: число должно быть положительным!" << std::endl;
    }
  }
}