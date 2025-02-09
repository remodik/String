#ifndef STRING_H
#define STRING_H
#include <iostream>

class String {
    char* data;
    size_t size;
    size_t capacity;

    void resize(size_t _size);

public:
    String();
    String(const char* str);
    String(const String& self);
    ~String();

    size_t length() const;
    bool empty() const;
    void insert(size_t pos, const String& subStr);
    void erase(size_t pos, size_t count);
    void replace(size_t pos, size_t count, const String& subStr);
    void clear();
    void concatenate(const String& self);
    String substr(size_t start, size_t len) const;
    void print() const;

    String operator+(const String& self) const;
    bool operator==(const String& self) const;
    bool operator!=(const String& self) const;
    bool operator<(const String& self) const;
    bool operator<=(const String& self) const;
    bool operator>(const String& self) const;
    bool operator>=(const String& self) const;
};

#endif
