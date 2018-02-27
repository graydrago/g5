# How to build

```sh
g++ -std=c++11 main.cpp
```

# Possible output

```
$ ./a.out 

1. Work with numbers (int)

1.1. Add 20 random numbers in the range between 0 and 100
[36, 81, 45, 58, 45, 100, 70, 37, 73, 11, 18, 17, 84, 94, 74, 18, 25, 6, 78, 75]

1.2. Sort in ascending order
[6, 11, 17, 18, 18, 25, 36, 37, 45, 45, 58, 70, 73, 74, 75, 78, 81, 84, 94, 100]

1.3. Remove every second element
[6, 17, 18, 36, 45, 58, 73, 75, 81, 94]

1.4. Insert 20 random numbers (in the range between 0 and 100) into random places
[6, 22, 93, 17, 76, 87, 73, 58, 97, 18, 68, 11, 93, 36, 78, 78, 51, 82, 11, 63, 45, 42, 58, 7, 2, 73, 75, 35, 81, 94]

1.4. Clear the array
[]


2. Work with strings (std::string)

2.1. Add 15 random words
[scrub, trace, scrub, care, cute, market, free, cute, serve, empty, snatch, permit, shy, moldy, market]

2.2. Sort in ascending order
[care, cute, cute, empty, free, market, market, moldy, permit, scrub, scrub, serve, shy, snatch, trace]

2.3. Remove all words which contain a, b, c, d or e character
[shy]

2.4. Insert 3 random words into random places
[unkempt, idiotic, shy, free]
```
