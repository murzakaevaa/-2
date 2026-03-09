#include <iostream>
// FIX_ME: Добавлен заголовочный файл для безопасного ввода
#include <limits>

// FIX_ME: Запрещено using namespace std 
// using namespace std;

class Node {
public:
  int data;
  Node* next;
  Node(int value);
};

class LinkedList {
private:
  Node* head;

public:

  LinkedList();
  void add(int value);

  // Метод для вставки значения M перед каждым вторым элементом
  // FIX_ME: Имена методов должны быть в lower_case_with_underscores 
  // void insertBeforeEverySecond(int M) {
  void insert_before_every_second(int M);

  void print() const;

  // Метод для получения указателя на последний элемент списка
  // FIX_ME: Имена методов должны быть в lower_case_with_underscores 
  // Node* getLastNode() {
  Node* get_last_node() const;

  // FIX_ME: Имена методов должны быть в lower_case_with_underscores
  // void clearList() {
  void clear_list();

  friend void insert_before_every_second(LinkedList& list, int M);
};

// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
void insert_before_every_second(LinkedList& list, int M);

// Функция для безопасного ввода целого числа
// FIX_ME: Добавлена функция для безопасного ввода целого числа
// Старый код: прямой cin без проверок
int safe_input(const std::string& prompt);

// Функция для безопасного ввода положительного числа
// FIX_ME: Добавлена функция для безопасного ввода положительного числа
int safe_positive_input(const std::string& prompt);

