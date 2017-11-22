Упражнение 6
============

[Binary Heap (a.k.a Priority Queue)](https://en.wikipedia.org/wiki/Binary_heap)
------------------------------------

![](images/heap.png)

Източници:

- [статията в Wikipedia](https://en.wikipedia.org/wiki/Binary_heap)
- [The Algorithm Design Manual (S. Skiena), pages 83 & 109](https://edisciplinas.usp.br/pluginfile.php/1995283/mod_resource/content/1/Skiena.-.TheAlgorithmDesignManual.pdf)

  - **3.5 Priority Queues**, page 83
  - **4.3 Heapsort: Fast Sorting via Data Structures**, page 111

- [Algorithms, R. Sedgewick](https://github.com/haseebr/competitive-programming/blob/master/Materials/Algorithhms%204th%20Edition%20by%20Robert%20Sedgewick%2C%20Kevin%20Wayne.pdf)
  - **2.4 Priority Queues**, page 308

**def.** **Min**-heap е двоична пирамида,
при която всеки връх в нея е **по-малък** от децата си.

**def.** **Max**-heap е двоична пирамида,
при която всеки връх в нея е **по-голям** от децата си.

Задачи
------

1. Реализирайте приоритетна опашка, като наследите класа `PriorityQueue`
и използвате двоична пирамида като логическа структура.
В следващите задачи ще работим с тази реализация, която можем да наречем `BinaryHeap`.
Имате избор между **min** и **max**-heap. Направете първо **min**-heap. A защо не и двете? :smiley:

2. Реализирайте предиката `void isMinHeap(const BinaryHeap& heap)`,
който проверява дали двоичната пирамида `heap` е **min-heap**,
тоест, че на върха винаги седи минималният елемент.
Може предикатът да е член-функция на вашата структура двоична пирамида, за да използвате физическите данни.
