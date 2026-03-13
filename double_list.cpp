#include "double_list.h"
// FIX_ME: Добавлен недостающий заголовочный файл
#include <iostream>
// FIX_ME: Добавлен заголовочный файл для безопасного ввода
#include <limits>

DoubleList::Node::Node(int val) {
    data = val;
    next = nullptr;
    prev = nullptr;
}

DoubleList::DoubleList() {
    head = nullptr;
}

DoubleList::~DoubleList() {
    if (!head) return;

    Node* current = head;
    while (true) {
        Node* temp = current;
        current = current->next;
        delete temp;
        if (current == head) break;
    }
}

void DoubleList::push_back(int value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else {
        Node* tail = head->prev;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = head;
        head->prev = new_node;
    }
}

void DoubleList::print_list() const {
    // FIX_ME: Добавлена проверка на пустой список
    // Старый код: отсутствовала проверка
    if (!head) {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    Node* current = head;
    while (true) {
        std::cout << current->data << " ";
        current = current->next;
        if (current == head) break;
    }
    std::cout << std::endl;
}

DoubleList::Node* DoubleList::delete_node(Node* node) {
    if (!node) return nullptr;

    // Проверка на единственный узел в циклическом списке
    if (node->next == node && node->prev == node) {
        if (node == head) head = nullptr;
        delete node;
        return nullptr;
    }
    Node* next_node = node->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (node == head) head = next_node;

    delete node;
    return next_node;
}

DoubleList::Node* DoubleList::remove_sides() {
    if (!head) return nullptr;
    // FIX_ME: Имена переменных приведены к snake_case
    //bool anyDeletion = false;
    bool any_deletion = false;

    // FIX_ME: Удалена неиспользуемая переменная deletedSomething
    //bool deletedSomething = false;

    while (true) {
        any_deletion = false;

        if (!head || head->next == head) break;

        Node* start = head;
        Node* current = head;
        // FIX_ME: Имена переменных приведены к snake_case
        //bool completedCycle = false;
        bool completed_cycle = false;

        // FIX_ME: Имена переменных приведены к snake_case
        //while (!completed_cycle) {
        //int leftData = curr->prev->data;
        //int rightData = curr->next->data;
        while (!completed_cycle) {
            int left_data = current->prev->data;
            int right_data = current->next->data;

            if (left_data == right_data) {
                any_deletion = true;

                Node* next_node = current->next;

                if (current == head) head = next_node;
                current = delete_node(current);

                if (!current) return nullptr;
                start = head;
                continue;
            }
            else {
                current = current->next;
            }
            if (current == start) completed_cycle = true;
        }
        if (!any_deletion) break;
    }
    if (!head) return nullptr;
    Node* tail = head->prev;
    return tail;
}

int safe_input(const char* prompt) {
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

int safe_positive_input(const char* prompt) {
    int value;
    while (true) {
        value = safe_input(prompt);
        if (value > 0) {
            return value;
        }
        else {
            std::cout << "Ошибка: число должно быть положительным!"
                << std::endl;
        }
    }
}