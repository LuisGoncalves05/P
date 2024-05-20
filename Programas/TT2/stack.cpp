#include "Stack.h"
#include <vector>

using namespace std;

template<typename T>
Stack<T>::Stack() {}

template<typename T>
size_t Stack<T>::size() const {
    return elements.size();
}

template<typename T>
bool Stack<T>::peek(T& elem) const {
    if (this->size() > 0) {
        elem = elements[elements.size() - 1];
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool Stack<T>::pop(T& elem) {
    if (this->size() > 0) {
        elem = elements.back();
        elements.pop_back();
        return true;
    } else {
        return false;
    }
}

template<typename T>
void Stack<T>::push(const T& elem) {
    elements.push_back(elem);
}