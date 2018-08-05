#include "DynamicArray.h"

DynamicArray::DynamicArray() : pData(nullptr), capacity(0), length(0)
{
}

DynamicArray::DynamicArray(const DynamicArray& other) : pData(nullptr)
{
    this->copyFrom(other);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& rhs)
{
    if (this != &rhs)
    {
        this->clear();
        this->copyFrom(rhs);
    }

    return *this;
}


DynamicArray::~DynamicArray()
{
    this->clear();
}

DynamicArray DynamicArray::operator+(const DynamicArray& rhs) const
{
    DynamicArray temp(*this);

    for (size_t i = 0; i < rhs.getLength(); i++)
    {
        temp.add(rhs.getAt(i));
    }

    return temp;
}

DynamicArrayElementProxy DynamicArray::operator[](size_t index)
{
    return DynamicArrayElementProxy(this, index);
}

const DynamicArrayElementProxy DynamicArray::operator[](size_t index) const
{
    return DynamicArrayElementProxy(const_cast<DynamicArray*>(this), index);
}

void DynamicArray::add(int element)
{
    if (this->length >= this->capacity)
    {
        size_t newCapacity = (this->capacity == 0 ? 2 : this->capacity * 2);
        this->resize(newCapacity);
    }

    this->pData[this->length++] = element;
}

int DynamicArray::getAt(size_t index) const
{
    if (index >= this->length)
    {
        throw std::out_of_range("index out of range!");
    }

    return this->pData[index];
}

void DynamicArray::setAt(size_t index, int element) const
{
    if (index >= this->length)
    {
        throw std::out_of_range("index out of range!");
    }

    this->pData[index] = element;
}

size_t DynamicArray::getCapacity() const
{
    return this->capacity;
}

size_t DynamicArray::getLength() const
{
    return this->length;
}

void DynamicArray::print() const
{
    std::cout
            << "Dynamic Array at " << this
            << ", buffer at " << this->pData
            << ", size (" << this->length << " / " << this->capacity << ")\n";

    if (this->length > 0)
    {
        std::cout << "Elements: [ ";
        for (size_t i = 0; i < length; i++)
        {
            std::cout << this->pData[i] << " ";
        }

        std::cout << "]\n";
    }
}

void DynamicArray::copyFrom(const DynamicArray& other)
{
    this->pData = new int[other.capacity];
    for (int i = 0; i < other.length; i++)
    {
        pData[i] = other.pData[i];
    }

    this->capacity = other.capacity;
    this->length = other.length;
}

void DynamicArray::clear()
{
    delete[] this->pData;
    this->pData = nullptr;
    this->capacity = 0;
    this->length = 0;
}

void DynamicArray::resize(size_t newCapacity)
{
    int* pTemp = new int[newCapacity];

    for (size_t i = 0; i < this->capacity; i++)
    {
        pTemp[i] = this->pData[i];
    }

    delete[] this->pData;
    this->pData = pTemp;
    this->capacity = newCapacity;
}


// ========================================================================

DynamicArrayElementProxy::DynamicArrayElementProxy(DynamicArray* arr, size_t index) :
        pParent(arr), index(index)
{
}

DynamicArrayElementProxy::operator int() const
{
    this->pParent->getAt(index);
}

DynamicArrayElementProxy& DynamicArrayElementProxy::operator=(int value)
{
    this->pParent->setAt(this->index, value);

    return *this;
}