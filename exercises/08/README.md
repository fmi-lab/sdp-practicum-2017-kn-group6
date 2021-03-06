Упражнение 8
============

# Pouring Glasses

Дадени са 3 чаши.
Всяка чаша има капацитет `C` и в нея е налята вода с количество `W`.
Количеството вода `W` в чашата задължително е по-малко или равно от капацитета `C` на чашата, за да не прелее.

Позволено ви е да преливате вода от една чаша в друга, докато
чашата, от която преливате стане празна, или
чашата, в която вливате стане пълна. Чашата не трябва да се препълва.

Трите чаши имат капацитети съответно `C1`, `C2`, `C3`, а
първоначалното количество вода във всяка от тях е съответно `W1`, `W2`, `W3`.

Целта е да достигнете количество `G` в някоя от чашите.
Освен това, намерете минималния брой преливания,
за да достигнете целевото количество `G`, така че да намалите риска от разливане на вода извън чашите.

## Вход

На първия ред на стандартния вход ще има 3 цели числа `C1`, `C2`, `C3` - капацитетите на трите чаши.
На втория ред ще има още 3 цели числа `W1`, `W2`, `W3` - първоначалните количества вода в чашите.
На третия ред ще бъде целевото количество `G`, която е цяло число.

## Изход

На първия ред на стандартния изход отпечатайте минималния брой преливания,
които трябва да направите, за да постигнете целевото количество вода `G` в някоя от чашите.

На следващите редове отпечатайте преливанията, които се направили, за да стигнете до целта.
За всяко преливане отпечатайте на един ред номера на чашата, от която преливате,
последван от номера на чашата, в която вливате.

## Ограничения на входа

```
1 <= C,W,G <= 30
```

## Пример

Вход:

```
4 7 6
2 5 4
1
```

Изход:

```
2
2 1
2 3
```
