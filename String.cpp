#include "String.h"
#include <iostream>
#include <string.h>
using namespace std;
String::String() : data(nullptr), size(0), capacity(0) {}

String::String(const char* str) {
    size = strlen(str);
    capacity = size + 1;
    data = new char[capacity];
    strcpy(data, str);
}

String::String(const String& self) {
    size = self.size;
    capacity = self.capacity;
    data = new char[capacity];
    strcpy(data, self.data);
}

String::~String() { delete[] data; data = nullptr;}

size_t String::length() const { return size; }

bool String::empty() const { return size == 0; }

void String::insert(const size_t pos, const String& subStr) {
    if (pos > size) return;

    const size_t _size = size + subStr.size;
    resize(_size);

    for (size_t i = size; i > pos; --i) {
        data[i + subStr.size - 1] = data[i - 1];
    }

    for (size_t i = 0; i < subStr.size; ++i) {
        data[pos + i] = subStr.data[i];
    }
    size = _size;
}

void String::erase(const size_t pos, const size_t count) {
    if (pos + count > size) return;
    for (size_t i = pos; i < size - count; ++i) {
        data[i] = data[i + count];
    }
    size -= count;
}

void String::replace(const size_t pos, const size_t count, const String& subStr) {
    erase(pos, count);
    insert(pos, subStr);
}

void String::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

void String::concatenate(const String& self) {
    const size_t _size = size + self.size;
    resize(_size);

    strcpy(data + size, self.data);
    size = _size;
}

String String::substr(const size_t start, const size_t len) const {
    if (start >= size) return {""};

    const size_t alen = (start + len > size) ? size - start : len;
    String subStr;
    subStr.resize(alen);

    for (size_t i = 0; i < alen; ++i) {
        subStr.data[i] = data[start + i];
    }
    return subStr;
}

void String::resize(const size_t _size) {
    if (_size > capacity) {
        capacity = _size + 1;
        auto _data = new char[capacity];
        if (data != nullptr) {
            strcpy(_data, data);
            delete[] data;
        }
        data = _data;
    }
}

void String::print() const { cout << data << endl; }

String String::operator+(const String& self) const {
    const size_t _size = size + self.size;
    String result;
    result.resize(_size);

    strcpy(result.data, data);
    strcpy(result.data + size, self.data);

    result.size = _size;
    return result;
}

bool String::operator==(const String& self) const {
    if (size != self.size) { return false; }
    return strcmp(data, self.data) == 0;
}

bool String::operator!=(const String& self) const { return !(*this == self); }

bool String::operator<(const String& self) const { return strcmp(data, self.data) < 0; }

bool String::operator<=(const String& self) const { return strcmp(data, self.data) <= 0; }

bool String::operator>(const String& self) const { return strcmp(data, self.data) > 0; }

bool String::operator>=(const String& self) const { return strcmp(data, self.data) >= 0; }