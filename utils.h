#ifndef __UTILS__
#define __UTILS__

#include <iostream>

#include "CArray.h"


template <typename T>
void partial(
    CArray<T>& array,
    long lo,
    long hi
  )
{
    if (lo >= hi) return;

    T p = array[(hi + lo) / 2];
    auto i = lo;
    auto j = hi;

    while (i <= j)
    {
        while (array[i] < p) i++;
        while (array[j] > p) j--;
        if (i <= j)
        {
            auto tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    }

    partial(array, lo, i - 1);
    partial(array, i, hi);
}


// Быстрая сортировка
template <typename T>
void quick_sort(
    T & array
  )
{
    partial(array, 0, array.size() - 1);
}

template<typename T>
void print(
    T & _data
  )
{
    std::cout << _data << std::endl;
}


template<typename T>
void print(
    T && _data
  )
{
    std::cout << _data << std::endl;
}


void br()
{
    std::cout << std::endl;
}


CArray<std::string> get_list_of_words()
{
    CArray<std::string> list;
    list.push_back("pushereward");
    list.push_back("thick");
    list.push_back("dog");
    list.push_back("second");
    list.push_back("attract");
    list.push_back("warm");
    list.push_back("trees");
    list.push_back("serve");
    list.push_back("unadvised");
    list.push_back("tasty");
    list.push_back("trace");
    list.push_back("scrub");
    list.push_back("empty");
    list.push_back("woman");
    list.push_back("moldy");
    list.push_back("tie");
    list.push_back("market");
    list.push_back("representative");
    list.push_back("relation");
    list.push_back("longing");
    list.push_back("unkempt");
    list.push_back("snatch");
    list.push_back("work");
    list.push_back("permit");
    list.push_back("enchanted");
    list.push_back("dinner");
    list.push_back("care");
    list.push_back("energetic");
    list.push_back("idiotic");
    list.push_back("calculate");
    list.push_back("abject");
    list.push_back("time");
    list.push_back("wealth");
    list.push_back("fear");
    list.push_back("black");
    list.push_back("free");
    list.push_back("shy");
    list.push_back("foolish");
    list.push_back("tiger");
    list.push_back("cute");

    return list;
}

#endif // __UTILS__

