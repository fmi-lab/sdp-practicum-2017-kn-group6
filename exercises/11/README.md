Упражнение 11
=============

Задачи
------

0. Прочетете за структурата от данни
[std::unordered_map](http://en.cppreference.com/w/cpp/container/unordered_map).
Какви сложности имат основните операции?

`using namespace std;`

Rand Set
Create a data structure that will represent a collection supporting the following operations:

Insert integer - O(1)
Remove integer - O(1)
Check if an integer is present in the collection - O(1)
Get random integer from the collection - O(1)

1. Създайте структура от данни `Random set` със следните операции:

* `insert(x)` - вмъква елемент `x` със сложност O(1)
* `delete(x)` - изтриване на елемент `x` със сложност O(1)
* `contains(x)` - проверка дали елемент `x` присъства със сложност O(1)
* `rand()` - взимане на произволен елемент със сложност O(1)

2. Реализирайте функция `int hash(std::string s)`, която хешира символния низ `s`.
Каква сложност има вашия алгоритъм?

3. Дадена ви е функция, която намира N-тото число от редицата на Фибоначи:

```cpp
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
```

Каква сложност по време и памет има функцията `fib`?

Можем ли да я подобрим? Реализирайте `fib` чрез **мемоизация**.

4. Имплементирайте клас `Person`, който има следните член данни:

   - първо име
   - фамилия
   - възраст
   - адрес

Реализирайте функция `int hash(const Person& person)`, която хешира `person`.
