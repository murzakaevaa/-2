#include <iostream>
#include <deque>
#include <fstream>
#include <cstdlib>
#include <ctime>
// FIX_ME: Добавлен для очистки буфера
#include <limits>

// FIX_ME: Запрещено using namespace std 
// using namespace std;

// FIX_ME: Добавлена функция для безопасного ввода целого числа
int safe_input(const std::string& prompt);

// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
// void FuncInsert(deque<int>& D) {
void func_insert(std::deque<int>& deque);

// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
// deque<int> FuncKeyboard() {
std::deque<int> func_keyboard();

// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
// deque<int> FuncRandom(int count) {
std::deque<int> func_random(int count);

// FIX_ME: Имена функций должны быть в lower_case_with_underscores 
// deque<int> FuncFile() {
std::deque<int> func_file();


