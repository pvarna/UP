# Рекурсия

## Задача 1:
Да се състави програма, която прочита **N** числа и ги извежда в обратен ред, използвайки рекурсия.

*Вход:*     
6   
1 2 3 4 5 6     

*Изход:*    
6 5 4 3 2 1

## Задача 2:
Функцията `strlen` връща дължината на символен масив. Да се реализира рекурсивна имплементация на функцията.

```
size_t strlen(const char *text)
{
    size_t len = 0;

    while (text[len])
    {
        ++len;
    }

    return len;
}
```

*Вход:*     
potop  

*Изход:*    
5

## Задача 3:
Да се състави програма, която въвежда от клавиатурата цяло положително число **N** и извежда на екрана сбора от цифрите му. Решението да се реализира чрез рекурсия.

*Вход:*     
12345  

*Изход:*    
15

## Задача 4. 
Напишете програма, която рекурсивно намира най-големия елемент в даден масив

*Вход:*     
7   
3 1 2 9 22 4 5 6     

*Изход:*    
22

## Задача 5:
Да се състави програма, която прочита от клавиатурата дума и проверява дали тази дума е палиндром (от ляво на дясно и от дясно на ляво се чете еднакво). Решението да се реализира чрез рекурсия.

*Вход:*     
potop 

*Изход:*    
YES     

## Задача 6:
Да се състави програма на C++, чрез която се извежда триъгълник от букви. Първият ред на триъгълника започва с А и завършва с въведената главна латинска буква. Във всеки следващ ред крайният знак е с 1 по-малък (по ASCII код). Използвайте рекурсия.

*Вход:*     
D

*Изход:*    
A B C D     
A B C   
A B      
A   

## Задача 7: <!-- https://www.geeksforgeeks.org/generate-binary-strings-without-consecutive-1s/ -->
Да се състави програма, която прочита от клавиатурата число **N** и отпечатва всички възможни последователности от 0 и 1 с дължина **N**, които не съдържат съседни 1-ци. Решението да се реализира чрез рекурсия.

*Вход 1:*     
3 

*Изход 1:*    
000     
001     
010     
100     
101     

(011, 110, 111 са изпуснати)

*Вход:*     
4 

*Изход:*    
0000    
0001    
0010    
0100    
0101    
1000    
1001    
1010    
    
(0011, 0110, 0111, 1011, 1100, 1101, 1110, 1111 са изпуснати)

## Задача 8:
Въведете матрица от символи, сходна на тази от долу. По избрана клетка и нов символ, подобно на кофичката в paint сменете всички съседни символи, от същият тип с новите. Вероятно се досещата вече, че това с тoва с рекурсия.

*Вход:* 
```
4 4
* * * *
* * + +
+ - - *
+ - - *
0 0
@
```

*Изход:*
```
@ @ @ @
@ @ + +
+ - - *
+ - - *
```