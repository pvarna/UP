# Базови алгоритми върху масиви.

## Задача 1:
Имате предварително въведени стойности на елементи в двумерен масив - естествени числа от интервала `[0..100]`. Да се състави програма, чрез която се извеждат стойностите на елементите в двумерен масив след обръщането му на 90 градуса. 

*Вход:*
```
int input[N][N] = 
{
    { 1,  2,  3,  4}, 
    { 5,  6,  7,  8}, 
    { 9, 10, 11, 12}, 
    {13, 14, 15, 16}
};
```

*Изход:*
```
 4  8 12 16
 3  7 11 15
 2  6 10 14
 1  5  9 13
```

## Задача 2:
Да се въведат множество едноцифрени числа в едномерен масив. Въвеждането да приключи при подаване на символ **#** (да се ползва char за въвеждането). Въведените числа да се сортират низходящо използвайки Selection sort. Така полученият масив да се изведе на екрана.

*Вход:*     
1 4 5 3 2 9 #

*Изход:*    
9 5 4 3 2 1

## Задача 3: 
Напишете програма, която да трие елемент с индекс **k** от масив с **n** на брой положителни числа и да измества другите елементи, като в получилaтa се дупка сложите числото -1, което бележи, че e невалиднo поле. Входът се състои от числото **n**, последвано от **n** числа и накрая се въвежда **k**.

*Вход:*     
5   
3 7 23 5 1  
2 

*Изход:*    
3 7 5 1 -1  

## Задача 4: 
Да се намери най-често срещаният елемент в даден масив с **n** на брой елемента, които може да са измежду числата в интервала[0...5000]. Да се изведе кой е той и колко пъти се среща. Ако два или повече се срещат равен брой пъти, изведете единия.

*Вход:*     
11  
1 2 3 3 4 1 5 1 1 7 7   

*Изход:*  
1 - 4  

## Задача 5:
Да се състави програма, която прочита **N** битовете на число в двоична бройна система и отпечата стойността в осмична бройна система. Входът се състои от последователност от 0 и 1 с дължина **N** (N <= 20) и разделени с интервали.

*Вход:*     
10
0 1 0 0 0 0 1 0 1 0

*Изход:*    
412

*Обяснение:*    
0100001010<sub>2</sub> = 266<sub>10</sub> = 412<sub>8</sub>

## Задача 6:
Да се състави програма, която прочита буквите на парола с максимална дължина 10 символа и слага цифрите от 0 до 9 последователно между всеки две букви, за да увеличи силата на паролата. Реализацията на програмата трябва да използва масив, в който ще бъде получена новата парола.

*Вход:*     
4   
r i b a      

*Изход:*    
r0i1b2a