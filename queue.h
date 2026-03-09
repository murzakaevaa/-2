// FIX_ME: Запрещено using namespace std 
// using namespace std;

struct PNode {
  int data;
  PNode* next;

  // FIX_ME: Добавлен конструктор для инициализации узла
  PNode(int value);
};

// FIX_ME: Переименовано в TQueue (по заданию), поля head/tail (по заданию)
struct TQueue {
  PNode* head; // Указатель на начало очереди (P1)
  PNode* tail; // Указатель на конец очереди (P2)

  TQueue();
};

// Функция для добавления элемента в очередь
// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
void enqueue(TQueue& queue, int value);

// Функция для извлечения элемента из очереди
// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
int dequeue(TQueue& queue);


