#pragma once

#include <iostream>

class DynamicArrayElementProxy;

class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& rhs);
    ~DynamicArray();

    DynamicArray operator+(const DynamicArray& rhs) const;
    DynamicArrayElementProxy operator[](size_t);
    const DynamicArrayElementProxy operator[](size_t) const;

    void add(int element);

    int getAt(size_t index) const;
    void setAt(size_t index, int element) const;

    size_t getCapacity() const;
    size_t getLength() const;

    void print() const;
private:
    void resize(size_t newSize);

    void clear();
    void copyFrom(const DynamicArray& other);

private:
    int* pData;
    size_t capacity;
    size_t length;
};

class DynamicArrayElementProxy
{
public:
    DynamicArrayElementProxy(DynamicArray* pParent, size_t index);

    operator int() const;

    DynamicArrayElementProxy& operator=(int);
private:
    DynamicArray* pParent;
    size_t index;
};