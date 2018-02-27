#include <iostream>
#include <random>

#include "CArray.h"
#include "utils.h"


std::random_device rd;
std::uniform_real_distribution<float> random_float(0, 1);


void work_with_digits();
void work_with_strings();


int main()
{
    work_with_digits();
    work_with_strings();
    
    return 0;
}


void work_with_digits()
{
    std::uniform_int_distribution<int> random_int(0, 100);

    br();
    print("1. Work with numbers (int)");
    br();
    CArray<int> a;

    print("1.1. Add 20 random numbers in the range between 0 and 100");
    for (int i = 0; i < 20; i++)
    {
        a.push_back(random_int(rd));
    }
    print(a); br();

    print("1.2. Sort in ascenging order");
    quick_sort(a);
    print(a); br();


    print("1.3. Remove every second element");
    {
        CArray<int> tmp;
        int size = a.size();
        for (int i = 0; i < size; i += 2)
        {
            tmp.push_back(a[i]);
        }
        a = tmp;
    }
    print(a); br();

    print("1.4. Insert 20 random numbers (in the range between 0 and 100) into random places");
    for (int i = 0; i < 20; ++i)
    {
        auto num = random_int(rd);
        auto place = static_cast<int>(static_cast<float>(a.size() - 1) * random_float(rd));
        a.insert(place, num);
    }
    print(a); br();


    print("1.4. Clear the array");
    a.clear();
    print(a); br();
}


void work_with_strings()
{
    auto word_list = get_list_of_words();
    std::uniform_int_distribution<int> random_int(0, word_list.size() - 1);

    br();
    print("2. Work with strings (std::string)");
    br();
    CArray<std::string> a;

    print("2.1. Add 15 random words");
    for (int i = 0; i < 15; ++i)
    {
        a.push_back(word_list[random_int(rd)]);
    }
    print(a); br();

    print("2.2. Sort in ascenging order");
    quick_sort(a);
    print(a); br();

    print("2.3. Remove all words which contains a, b, c, d or e character");
    {
        CArray<std::string> tmp;
        int size = a.size();
        for (int i = 0; i < size; ++i)
        {
            bool found = false;
            for (char c = 'a'; c <= 'e'; c++)
            {
                if (a[i].find(c) != std::string::npos)
                {
                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                tmp.push_back(a[i]);
            }
        }
        a = tmp;
    }
    print(a); br();

    print("2.4. Insert 3 random words into random places");
    for (int i = 0; i < 3; ++i)
    {
        auto word = word_list[random_int(rd)];
        auto place = static_cast<int>(static_cast<float>(a.size()+1) * random_float(rd));
        a.insert(place, word);
    }
    print(a); br();
}


