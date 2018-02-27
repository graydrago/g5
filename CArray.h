#ifndef __CARRAY__
#define __CARRAY__

#include <exception>
#include <ostream>
#include <algorithm>

// ===== Declararion part =====

struct CArrayOutOfRangeException : public std::exception {};
struct CArrayMemoryAllocationException : public std::exception {};


template <typename TData>
class CArray
{
public: // Interface
    // Конструктор по умолчанию
    CArray();

    // Копирующий конструктор
    CArray(
        const CArray & _array
    );

    // Деструктор
    ~CArray();

    // Добавить элемент в конец массива
    void push_back(
        const TData & _value
    );

    // Добавить элемент в массив по заданному индексу
    void insert(
        unsigned int _index,
        const TData & _value
    );

    // Удалить элемент массива по заданному индексу
    void erase(
        unsigned int _index
    );

    // Очистить массив
    void clear();

    // Получить размер массива
    unsigned int size() const;

    // Получить элемент массива по заданному индексу
    TData & operator[](
        unsigned int _index
    );

    CArray<TData> & operator=(
        CArray<TData> & _array
    );

protected: // Attributes
    TData *m_data;
    unsigned int m_capacity;
    unsigned int m_cursor;

    static const unsigned int DEFAULT_CAPACITY;

    void increase_capacity();
    void resize_capacity(const unsigned int _new_capacity);

};


// Размер буфера по умолчанию
template <typename TData>
const unsigned int CArray<TData>::DEFAULT_CAPACITY = 10;


// Отправка в поток вывода
template <typename TData>
std::ostream& operator <<(
    std::ostream & os,
    CArray<TData> & a
);


// ===== Implementation part =====

// Конструктор по умолчанию
template <typename TData>
CArray<TData>::CArray()
  : m_data(new TData[DEFAULT_CAPACITY]),
    m_capacity(DEFAULT_CAPACITY),
    m_cursor(0)
{
}


// Копирующий конструктор
template <typename TData>
CArray<TData>::CArray(
    const CArray & _array
  )
{
    if (this == &_array) return;
    m_cursor = _array.m_cursor;
    m_capacity = _array.m_capacity;
    m_data = new TData[_array.m_capacity];
    std::copy(
        _array.m_data,
        _array.m_data + _array.m_capacity,
        m_data);
}


// Деструктор
template <typename TData>
CArray<TData>::~CArray()
{
    if (m_data != nullptr)
    {
        delete [] m_data;
    }
}


// Добавить элемент в конец массива
template <typename TData>
void CArray<TData>::push_back(
    const TData & _value
  )
{
    if (m_cursor + 1 > m_capacity)
    {
        increase_capacity();
    }
    m_data[m_cursor] = _value;
    ++m_cursor;
}


// Добавить элемент в массив по заданному индексу
template <typename TData>
void CArray<TData>::insert(
    unsigned int _index,
    const TData & _value
  )
{
    if (_index > m_cursor) throw CArrayOutOfRangeException();

    if (size() + 1 > m_capacity)
    {
        increase_capacity();
    }

    if (_index < m_cursor)
    {
        std::copy_backward(
            m_data + _index,
            m_data + m_cursor,
            m_data + m_cursor + 1);
    }
    m_data[_index] = _value;
    m_cursor++;
}


// Удалить элемент массива по заданному индексу
template <typename TData>
void CArray<TData>::erase(
    unsigned int _index
  )
{
    if (_index >= m_cursor) throw CArrayOutOfRangeException();

    if (_index < m_cursor)
    {
        std::copy(
            m_data + _index,
            m_data + m_capacity,
            m_data + _index - 1
        );
    }
    m_cursor--;
}


// Очистить массив
template <typename TData>
void CArray<TData>::clear()
{
    m_cursor = 0;
}


// Получить размер массива
template <typename TData>
unsigned int CArray<TData>::size() const
{
    return m_cursor;
}


// Получить элемент массива по заданному индексу
template <typename TData>
TData & CArray<TData>::operator[](
    unsigned int _index
  )
{
    if (_index >= m_cursor) throw CArrayOutOfRangeException();
    return m_data[_index];
}


template <typename TData>
void CArray<TData>::increase_capacity()
{
    resize_capacity(m_capacity * 2);
}


template <typename TData>
void CArray<TData>::resize_capacity(
    const unsigned int _new_capacity
  )
{
    auto tmp_data = new TData[_new_capacity];
    if (tmp_data == nullptr) throw CArrayMemoryAllocationException();

    std::copy(m_data, m_data + m_capacity, tmp_data);
    if (m_data != nullptr)
    {
        delete [] m_data;
    }
    m_data = tmp_data;
    m_capacity = _new_capacity;
}


template <typename TData>
std::ostream& operator <<(
    std::ostream & _os,
    CArray<TData> & _array
  )
{
    auto size = _array.size();
    _os << '[';
    for (unsigned int i = 0; i < size; ++i)
    {
        _os << _array[i];
        if (i < size - 1)
        {
            _os << ", ";
        }
    }
    _os << ']';
    return _os;
}


template <typename TData>
CArray<TData> & CArray<TData>::operator=(
    CArray<TData> & _array
  )
{
    if (this != &_array)
    {

        m_cursor = _array.m_cursor;
        m_capacity = _array.m_capacity;
        delete [] m_data;
        m_data = new TData[_array.m_capacity];
        std::copy(
            _array.m_data,
            _array.m_data + _array.m_capacity,
            m_data);
    }
    return *this;
}

#endif // __CARRAY__
