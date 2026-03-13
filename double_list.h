class DoubleList {
public:
  struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val);
  };

  // FIX_ME: Добавлен спецификатор private для инкапсуляции поля head
  // Раньше head был в public секции, что позволяло напрямую изменять указатель 
private:
  Node* head;

public:
  DoubleList();
  // FIX_ME: Деструктор (имена переменных приведены к snake_case)
  // Node* curr = head; Node* tmp = curr;
  ~DoubleList();

  // Метод добавляет новый элемент в конец списка
  // FIX_ME: Имена переменных приведены к snake_case
  //Node* newNode = new Node(value);
  void push_back(int value);

  // Метод выводит все элементы списка на экран
  // FIX_ME: Имя метода изменено на print() (lower_case_with_underscores)
  // void printList() 
  void print_list() const;

  // Метод удаляет указанный узел и возвращает указатель на следующий   
  // FIX_ME: Имена методов должны быть в lower_case_with_underscores 
  // Node* deleteNode(Node* node) 
  Node* delete_node(Node* node);

  // Метод удаляет элементы, у которых левый и правый сосед совпадают
  // FIX_ME: Имена методов должны быть в lower_case_with_underscores 
  Node* remove_sides();
};

// Функция обеспечивает безопасный ввод целого числа с проверкой на ошибки
// FIX_ME: Добавлена функция для безопасного ввода целого числа
// Старый код: прямой cin без проверок
int safe_input(const char* prompt);

// Функция безопасный ввод положительного числа
// FIX_ME: Добавлена функция для безопасного ввода положительного числа
// Старый код: отсутствовала
int safe_positive_input(const char* prompt);

