#include "queue.h"
#include <iostream>

// FIX_ME: Добавлен конструктор для инициализации узла
PNode::PNode(int value) : data(value), next(nullptr) {}

// FIX_ME: Конструктор TQueue
TQueue::TQueue() : head(nullptr), tail(nullptr) {}

// Функция для добавления элемента в очередь
void enqueue(TQueue& queue, int value) {
  PNode* new_node = new PNode(value);
  if (queue.tail) {
    queue.tail->next = new_node;
  }
  else {
    queue.head = new_node;
  }
  queue.tail = new_node;
}

// Функция для извлечения элемента из очереди
int dequeue(TQueue& queue) {
  // FIX_ME: Добавлена проверка на пустую очередь
  if (queue.head == nullptr) {
    std::cout << "Ошибка: очередь пуста!" << std::endl;
    return -1;
  }

  PNode* temp = queue.head;
  int value = temp->data;
  queue.head = queue.head->next;

  if (queue.head == nullptr) {
    queue.tail = nullptr;
  }

  delete temp;
  return value;
}