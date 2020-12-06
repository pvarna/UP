#include <iostream>

int main ()
{
    int num1, num2, selection;

    std::cout << "Number1: ";
	std::cin >> num1;
	std::cout << "Number2: ";
	std::cin >> num2;

    do
    {
        std::cout <<"Please make a selection: \n";
        std::cout << "1) Bitwise AND\n";
        std::cout << "2) Bitwise OR\n";
        std::cout << "3) Bitwise XOR\n";
        std::cout << "4) Left shift\n";
        std::cout << "5) Right shift\n";

        std::cin >> selection;
    } while (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5);

    int res;

    switch (selection)
    {
        case 1:
            res = (num1 & num2);
            break;
        case 2:
            res = (num1 | num2);
            break;
        case 3:
            res = (num1 ^ num2);
            break;
        case 4:
            res = (num1 << num2);
            break;
        case 5:
            res = (num1 >> num2);
            break;
    }

    std::cout << "Result: " << res << std::endl;

    return 0;
}