#include <iostream>
#include <stack>
#include <random>

using namespace std;

// Функція для виведення стеку на екран
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Функція для упорядкування стеку за зростанням значень елементів
void sortStack(stack<int>& s) {
    stack<int> tempStack;
    while (!s.empty()) {
        int temp = s.top();
        s.pop();
        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> originalStack;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    // Заповнення стеку випадковими числами
    for (int i = 0; i < 10; i++) {
        originalStack.push(dis(gen));
    }

    // Виведення початкового стеку
    cout << "Початковий стек: ";
    printStack(originalStack);

    // Упорядкування стеку
    sortStack(originalStack);

    // Виведення стеку після упорядкування
    cout << "Стек після упорядкування: ";
    printStack(originalStack);

    return 0;
}
