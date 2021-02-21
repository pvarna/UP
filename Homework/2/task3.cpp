#include <iostream>

const int MAX_ARRAY_SIZE = 8192*2+1;

// my version of strLen
size_t myStrLen(char array[]);

// my version of strCpy
void myStrCpy(char array1[], char array2[]);

// reads a long number + validation, returns the size using "myStrLen" function
size_t readLongNumber(char array[], int index);

// removes leading zeroes and '+'
void removePlusAndZeroes(char array[], size_t &size);

// prints a long number (there is a option for brackets when there is a negative numbers after a sign for arithmetic operation)
void printLongNumber(char array[], size_t size, bool addBrackets);

// compares long numbers, returns 0 if they are equal, 1 if the first one is bigger or 2 if the second one is bigger
int compareLongNumbers(char array1[], char array2[], size_t size1, size_t size2);  

// sums two positive long numbers (the first must be bigger than the second) 
// helper function for the "sumLongNumbers" and "subtractLongNumbers" functions
void sumPositiveLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char sum[], size_t &sizeSum);

// subtracts smaller from bigger positive long number
// helper function for the "sumLongNumbers" and "subtractLongNumbers" functions
void subtractSmallerFromBiggerPositiveLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char difference[], size_t &sizeDifference);

// subtracts bigger from smaller positive long number
// helper function for the "sumLongNumbers" and "subtractLongNumbers" functions
void subtractBiggerFromSmallerPositiveLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char difference[], size_t &sizeDifference);

// sums two long numbers using the helper functions
void sumLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char sum[], size_t &sizeSum);

// subtracts two long numbers using the helper functions
void subtractLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char difference[], size_t &sizeDifference);

// multiplies a one-digit number with a multi-digit one
// helper function for the "multiplyLongNumbers" function
void multiplyOneDigitNumberWithMultiDigit(char digit, char array[], size_t size, char product[], size_t &sizeProduct);

// multiplies two long numbers using the helper function
void multiplyLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char product[], size_t &sizeProduct);

// devides two long numbers (integer division and remainder)
// the boolean variable shows if the division is successful
void divideLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char quotient[], char remainder[], size_t &sizeQuotient, size_t &sizeRemainder, bool &successfulDivision);

// reverses the order of the elements in an array
void reverseArray(char array[], size_t size);

// swaps two elements in an array
void swap(char array[], int pos1, int pos2);

// adds '-' on first position (makes the numbers negative)
void addMinus(char array[], size_t &size);

// removes the element on first position
void removeElementOnFirstPosition(char array[], size_t &size);

// adds a '0' on the last position
void addZeroOnLastPosition(char array[], size_t &size);

int main ()
{
    char firstNumber[MAX_ARRAY_SIZE], secondNumber[MAX_ARRAY_SIZE], sum[MAX_ARRAY_SIZE], 
         difference[MAX_ARRAY_SIZE], product[MAX_ARRAY_SIZE], quotient[MAX_ARRAY_SIZE], remainder[MAX_ARRAY_SIZE];
    size_t size1 = readLongNumber(firstNumber, 1), 
           size2 = readLongNumber(secondNumber, 2);
    size_t sizeSum, sizeDifference, sizeProduct, sizeQuotient, sizeRemainder;
    bool successfulDivision;

    removePlusAndZeroes(firstNumber, size1);
    removePlusAndZeroes(secondNumber, size2);

    // print
    printLongNumber(firstNumber, size1, false);
    std::cout << std::endl;
    printLongNumber(secondNumber, size2, false);
    std::cout << std::endl;


    // compare
    int comparison = compareLongNumbers(firstNumber, secondNumber, size1, size2);
    printLongNumber(firstNumber, size1, false);
    if (comparison == 0)
    {
        std::cout << " = ";;
    }
    else 
    {
        std::cout << " != ";;
    }
    printLongNumber(secondNumber, size2, false);
    std::cout << std::endl;

    if (comparison != 0)
    {
        printLongNumber(firstNumber, size1, false);
        if (comparison == 1)
        {
            std::cout << " > ";;
        }
        else 
        {
            std::cout << " < ";;
        }
        printLongNumber(secondNumber, size2, false);
        std::cout << std::endl;
    }


    // sum
    printLongNumber(firstNumber, size1, false);
    std::cout << " + ";
    printLongNumber(secondNumber, size2, true);
    std::cout << " = ";
    sumLongNumbers(firstNumber, secondNumber, size1, size2, sum, sizeSum);
    printLongNumber(sum, sizeSum, false);
    std::cout << std::endl;

    // subtract
    printLongNumber(firstNumber, size1, false);
    std::cout << " - ";
    printLongNumber(secondNumber, size2, true);
    std::cout << " = ";
    subtractLongNumbers(firstNumber, secondNumber, size1, size2, difference, sizeDifference);
    printLongNumber(difference, sizeDifference, false);
    std::cout << std::endl;

    // multiply
    printLongNumber(firstNumber, size1, false);
    std::cout << " * ";
    printLongNumber(secondNumber, size2, true);
    std::cout << " = ";
    multiplyLongNumbers(firstNumber, secondNumber, size1, size2, product, sizeProduct);
    printLongNumber(product, sizeProduct, false);
    std::cout << std::endl;

    // divide
    divideLongNumbers(firstNumber, secondNumber, size1, size2, quotient, remainder, sizeQuotient, sizeRemainder, successfulDivision);
    if (successfulDivision)
    {
        printLongNumber(firstNumber, size1, false);
        std::cout << " / ";
        printLongNumber(secondNumber, size2, true);
        std::cout << " = ";
        printLongNumber(quotient, sizeQuotient, false);
        std::cout << std::endl;
        printLongNumber(firstNumber, size1, false);
        std::cout << " % ";
        printLongNumber(secondNumber, size2, true);
        std::cout << " = ";
        printLongNumber(remainder, sizeRemainder, false);
        std::cout << std::endl;
    }
    else
    {
        std::cout << "You cannot divide by 0!" << std::endl;
    }
    
    return 0;
}

size_t myStrLen(char array[])
{
    int counter = 0;
    for (int i = 0; array[i] != '\0'; ++i)
    {
        ++counter;
    }

    return counter;
}

void myStrCpy(char array1[], char array2[])
{
    size_t size1 = myStrLen(array1);
    for (size_t i = 0; i < size1; ++i)
    {
        array2[i] = array1[i];
    }
    array2[size1] = '\0';
}

size_t readLongNumber(char array[], int index)
{
    bool validNumber = true;
    size_t size = 0;
    do
    {
        if (!validNumber)
        {
            std::cout << "Invalid output! Please enter a number containing the character '-', '+' or digit on first position and digit on all of the other positions." << std::endl;
        }

        validNumber = true;
        std::cout << "Enter number " << index << ": ";
        std::cin >> array;
        size = myStrLen(array);

        if (array[0] != '+' && array[0] != '-' && (array[0] < '0' || array[0] > '9')) // check if the first symbol is '-', '+' or a digit
        {
            validNumber = false;
        }

        if (validNumber)
        {
            for (int i = 1; i < size; ++i) // check if the other symbols are digits
            {
                if (array[i] < '0' || array[i] > '9')
                {
                    validNumber = false;
                    break;
                }
            }
        }
    } while (!validNumber);
    
    return size;
    
}

void removePlusAndZeroes(char array[], size_t &size)
{
    bool isThereMinus = false;
    if (array[0] == '-')
    {
        removeElementOnFirstPosition(array, size);
        isThereMinus = true;
    }

    while (array[0] == '0' || array[0] == '+')
    {
        if (size == 0)
        {
            break;
        }
        removeElementOnFirstPosition(array, size);
    }

    if (size > 0 && isThereMinus)
    {
        addMinus(array, size);
    }

    if (size == 0)
    {
        array[0] = '0';
        size = 1;
    }
}

void printLongNumber(char array[], size_t size, bool addBrackets)
{
    if (array[0] == '-' && addBrackets)
    {
        std::cout << '(';
    }

    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i];
    }

    if (array[0] == '-' && addBrackets)
    {
        std::cout << ')';
    }
}

int compareLongNumbers(char array1[], char array2[], size_t size1, size_t size2)
{
    // 1. Different signs (the one is negative and the other is positive or 0)
    if (array1[0] == '-' && array2[0] != '-') // if the first number is negative and the second is positive or 0
    {
        return 2;
    }
    else if (array1[0] != '-' && array2[0] == '-') // if the first number is positive or 0 and the second is negative
    {
        return 1;
    }

    // 2. Same signs, different size
    else if (size1 != size2)
    {
        if (array1[0] != '-') // if they are positive
        {
            return (size1 > size2) ? 1 : 2; // return the longer one
        }
        else // if they are negative
        {
            return (size1 < size2) ? 1 : 2; // return the shorter one
        }
        
    }

    // 3. Same signs, same size
    else if (array1[0] == '-') // if the numbers are negative
    {
        for (int i = 1; i < size1; ++i) // inspect the two numbers digit by digit
        {
            if (array1[i] != array2[i]) // if there is a difference 
            {
                return (array1[i] < array2[i]) ? 1 : 2; // return the number with the smaller digit 
            }
        }
    }
    else // if the numbers are positive
    {
        for (int i = 0; i < size1; ++i) // inspect the two numbers digit by digit
        {
            if (array1[i] != array2[i]) // if there is a difference 
            {
                return (array1[i] > array2[i]) ? 1 : 2; // return the number with the bigger digit
            }
        }
    }
    return 0; // if the function has reached this point, the numbers are equal
}

void sumPositiveLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char sum[], size_t& sizeSum)
{
    int differenceOfSizes = 0, maxSize, counter = 0;

    // gets the difference between the sizes of the two numbers and the bigger size
    if (size1 > size2)
    {
        differenceOfSizes = size1 - size2;
        maxSize = size1;
    }
    else
    {
        differenceOfSizes = size2 - size1;
        maxSize = size2;
    }

    int onMind = 0;
    for (int i = maxSize-1; i >= 0; --i)
    {
        if (i - differenceOfSizes >= 0) // if there is such position in both of the numbers
        {
            // sum the digits on the current position and the remainder
            int sumOfDigits = (size1 > size2) ? (array1[i]-'0')+(array2[i-differenceOfSizes]-'0')+onMind : (array2[i]-'0')+(array1[i-differenceOfSizes]-'0')+onMind;
            sum[counter] = (sumOfDigits % 10) + '0'; 
            // place the sum of the last digits of the numbers on the first position of the sum,
            //       the sum of the last but one digits of the numbers on the second position of the sum,
            // ...
            // later we will reverse the array
            onMind = sumOfDigits / 10; // remainder
            ++counter;
        }
        else // there is no such position in the smaller number
        {
            // sum the digit on the current position of the bigger number and the remainder
            int sumOfDigits = (size1 > size2) ? (array1[i]-'0')+onMind : (array2[i]-'0')+onMind;
            sum[counter] = (sumOfDigits % 10) + '0';
            onMind = sumOfDigits / 10;
            ++counter;
        }
    }

    // add the remainder on the last position if there is any
    if (onMind != 0)
    {
        sum[counter] = '0'+onMind;
        ++counter;
    }

    reverseArray(sum, counter);
    sizeSum = counter;
}

void subtractSmallerFromBiggerPositiveLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char difference[], size_t& sizeDifference)
{
    int differenceOfSizes = size1 - size2, counter = 0;
    char copyOfArray1[MAX_ARRAY_SIZE];
    myStrCpy(array1, copyOfArray1); 
    // we make a copy of the first array because we are going to make changes with it during the subtraction

    for (int i = size1-1; i >= 0; --i)
    {
        if (i - differenceOfSizes >= 0) // if there is such position in both of the numbers
        {
            int diffOfDigits;
            // calculate the difference of the digits on the current position
            if (copyOfArray1[i] >= array2[i-differenceOfSizes])
            {
                diffOfDigits = (copyOfArray1[i]-'0')-(array2[i-differenceOfSizes]-'0');
            }
            else
            {
                int index = i-1;
                // take 1 from the first digit to the left of the current one which is different from '0'
                while (copyOfArray1[index] == '0') 
                {
                    copyOfArray1[index] = '9'; // making the zeroes '9's
                    --index;
                }
                --copyOfArray1[index]; // we have take 1 from here
                diffOfDigits = 10+(copyOfArray1[i]-'0')-(array2[i-differenceOfSizes]-'0');
            }
            difference[counter] = '0' + diffOfDigits; 
            // place the difference of the last digits of the numbers on the first position of the difference,
            //       the difference of the last but one digits of the numbers on the second position of the difference,
            // ...
            // later we will reverse the array
            ++counter;
        }
        else // there is no such position in the smaller number
        {
            // just add the current digit of the bigger number to the difference
            difference[counter] = copyOfArray1[i];
            ++counter;
        }
    }
    reverseArray(difference, counter);
    sizeDifference = counter;

    removePlusAndZeroes(difference, sizeDifference); // removing the leading zeroes if there are any
}

void subtractBiggerFromSmallerPositiveLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char difference[], size_t& sizeDifference)
{
    // just adding a minus if the number isn't 0
    subtractSmallerFromBiggerPositiveLongNumbers(array2, array1, size2, size1, difference, sizeDifference);
    if (difference[0] != '0')
    {
        addMinus(difference, sizeDifference);
    }
}

void swap(char array[], int pos1, int pos2)
{
    char temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

void reverseArray(char array[], size_t size)
{
    for (int i = 0; i < size/2; ++i)
    {
        swap(array, i, size-1-i);
    }
}

void sumLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char sum[], size_t& sizeSum)
{
    // we will make positive copies (without the minus of these which are negative)
    // of both numbers and just use the helper functions with all possibilities
    char array1WithoutMinus[MAX_ARRAY_SIZE], array2WithoutMinus[MAX_ARRAY_SIZE];
    myStrCpy(array1, array1WithoutMinus);
    myStrCpy(array2, array2WithoutMinus);
    size_t copyOfSize1 = size1, copyOfSize2 = size2;

    if (array1[0] == '-')
    {
        removeElementOnFirstPosition(array1WithoutMinus, copyOfSize1);
    }
    if (array2[0] == '-')
    {
        removeElementOnFirstPosition(array2WithoutMinus, copyOfSize2);
    }

    int comparison = compareLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2);
    if (array1[0] != '-' && array2[0] != '-')
    {
        if (comparison == 1)
        {
            sumPositiveLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2, sum, sizeSum);
        }
        else
        {
            sumPositiveLongNumbers(array2WithoutMinus, array1WithoutMinus, copyOfSize2, copyOfSize1, sum, sizeSum);
        }
    }
    else if (array1[0] == '-' && array2[0] == '-')
    {
        if (comparison == 1)
        {
            sumPositiveLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2, sum, sizeSum);
            if (sum[0] != '0')
            {
                addMinus(sum, sizeSum);
            }
        }
        else
        {
            sumPositiveLongNumbers(array2WithoutMinus, array1WithoutMinus, copyOfSize2, copyOfSize1, sum, sizeSum);
            if (sum[0] != '0')
            {
                addMinus(sum, sizeSum);
            }
        }
    }
    else if (array1[0] == '-' && array2[0] != '-')
    {
        if (comparison == 1)
        {
            subtractBiggerFromSmallerPositiveLongNumbers(array2WithoutMinus, array1WithoutMinus, copyOfSize2, copyOfSize1, sum, sizeSum);
        }
        else
        {
            subtractSmallerFromBiggerPositiveLongNumbers(array2WithoutMinus, array1WithoutMinus, copyOfSize2, copyOfSize1, sum, sizeSum);
        }
    }
    else if (array1[0] != '-' && array2[0] == '-')
    {
        if (comparison == 1)
        {
            subtractSmallerFromBiggerPositiveLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2, sum, sizeSum);
        }
        else
        {
            subtractBiggerFromSmallerPositiveLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2, sum, sizeSum);
        }
        
    }
    
}
void subtractLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char difference[], size_t& sizeDifference)
{
    // we will make positive copies (without the minus of these which are negative)
    // of both numbers and just use the helper functions with all possibilities
    char array1WithoutMinus[MAX_ARRAY_SIZE], array2WithoutMinus[MAX_ARRAY_SIZE];
    myStrCpy(array1, array1WithoutMinus);
    myStrCpy(array2, array2WithoutMinus);
    size_t copyOfSize1 = size1, copyOfSize2 = size2;

    if (array1[0] == '-')
    {
        removeElementOnFirstPosition(array1WithoutMinus, copyOfSize1);
    }
    if (array2[0] == '-')
    {
        removeElementOnFirstPosition(array2WithoutMinus, copyOfSize2);
    }

    int comparison = compareLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2);
    if (array1[0] != '-' && array2[0] != '-')
    {
        if (comparison == 1)
        {
            subtractSmallerFromBiggerPositiveLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2, difference, sizeDifference);
        }
        else
        {
            subtractBiggerFromSmallerPositiveLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2, difference, sizeDifference);
        }
    }
    else if (array1[0] == '-' && array2[0] == '-')
    {
        if (comparison == 1)
        {
            subtractSmallerFromBiggerPositiveLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2, difference, sizeDifference);
            if (difference[0] != '0')
            {
                addMinus(difference, sizeDifference);
            }
        }
        else
        {
            subtractSmallerFromBiggerPositiveLongNumbers(array2WithoutMinus, array1WithoutMinus, copyOfSize2, copyOfSize1, difference, sizeDifference);
        }
    }
    else if (array1[0] == '-' && array2[0] != '-')
    {
        if (comparison == 1)
        {
            sumPositiveLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2, difference, sizeDifference);
            if (difference[0] != '0')
            {
                addMinus(difference, sizeDifference);
            }
        }
        else
        {
            sumPositiveLongNumbers(array2WithoutMinus, array1WithoutMinus, copyOfSize2, copyOfSize1, difference, sizeDifference);
            if (difference[0] != '0')
            {
                addMinus(difference, sizeDifference);
            }
        }
    }
    else if (array1[0] != '-' && array2[0] == '-')
    {
        if (comparison == 1)
        {
            sumPositiveLongNumbers(array1WithoutMinus, array2WithoutMinus, copyOfSize1, copyOfSize2, difference, sizeDifference);
        }
        else
        {
            sumPositiveLongNumbers(array2WithoutMinus, array1WithoutMinus, copyOfSize2, copyOfSize1, difference, sizeDifference);
        }
        
    }
}

void addMinus(char array[], size_t &size)
{
    for (int i = size; i >= 1; --i)
    {
        array[i] = array[i-1];
    }
    array[0] = '-';
    ++size;
}

void removeElementOnFirstPosition(char array[], size_t &size)
{
    for (int i = 0; i < size-1; ++i)
    {
        array[i] = array[i+1];
    }
    --size;
}

void multiplyOneDigitNumberWithMultiDigit(char digit, char array[], size_t size, char product[], size_t &sizeProduct)
{
    sizeProduct = 0;
    int onMind = 0;
    for (int i = size-1; i >= 0; --i)
    {
        // multiplying the current digit with the given digit and adding the remainder
        int productOfDigits = (digit - '0') * (array[i] - '0') + onMind;
        product[sizeProduct] = '0' + (productOfDigits % 10);
        // place the product of the last digit of the number and the given digit on the first position of the product,
        //       the product of the last but one digit of the number and the given digit on the second position of the product,
        // ...
        // later we will reverse the array
        onMind = productOfDigits / 10; // remainder
        ++sizeProduct;
    }
    if (onMind != 0) // add the remainder if there is any
    {
        product[sizeProduct] = '0' + onMind;
        onMind = 0;
        ++sizeProduct;
    }
    reverseArray(product, sizeProduct);
}

void multiplyLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char product[], size_t &sizeProduct)
{
    // the product is 0 if either of the two numbers is 0
    if ((size1 == 1 && array1[0] == '0') || (size1 == 1 && array1[0] == '0'))
    {
        product[0] = '0';
        sizeProduct = 1;
        return;
    }

    // we will make positive copies (without the minus of these which are negative) for easier work
    // and eventually we will add a minus at the end of the function
    char copyOfArray1[MAX_ARRAY_SIZE], copyOfArray2[MAX_ARRAY_SIZE];
    myStrCpy(array1, copyOfArray1);
    myStrCpy(array2, copyOfArray2);
    size_t copyOfSize1 = size1, copyOfSize2 = size2;

    if (array1[0] == '-')
    {
        removeElementOnFirstPosition(copyOfArray1, copyOfSize1);
    }
    if (array2[0] == '-')
    {
        removeElementOnFirstPosition(copyOfArray2, copyOfSize2);
    }

    char firstProduct[MAX_ARRAY_SIZE], secondProduct[MAX_ARRAY_SIZE];
    size_t count1 = 0, count2 = 0, countZeroes = 1;
    char sumOfProducts[MAX_ARRAY_SIZE];
    size_t sizeOfSumOfProducts = 0;

    // multiplying each of the digits of the second number with the first number    
    multiplyOneDigitNumberWithMultiDigit(copyOfArray2[copyOfSize2-1], copyOfArray1, copyOfSize1, firstProduct, count1);
    for (int i = copyOfSize2-2; i >=0; --i)
    {
        sizeOfSumOfProducts = 0;
        count2 = 0;
        multiplyOneDigitNumberWithMultiDigit(copyOfArray2[i], copyOfArray1, copyOfSize1, secondProduct, count2);
        // then sum up in pairs the products by adding zeroes to the second one 
        // (we studied this method in 3-4 grade, idk how it is in English :D)
        for (int j = 0; j < countZeroes; ++j)
        {
            addZeroOnLastPosition(secondProduct, count2);
        }
        ++countZeroes;
        sumLongNumbers(firstProduct, secondProduct, count1, count2, sumOfProducts, sizeOfSumOfProducts);
        myStrCpy(sumOfProducts, firstProduct);
        count1 = sizeOfSumOfProducts;
    }
    myStrCpy(firstProduct, product);
    sizeProduct = count1;

    // if exactly one of the numbers is negative, we add '-'
    if((array1[0] == '-' && array2[0] != '-') || (array1[0] != '-' && array2[0] == '-'))
    {
        addMinus(product, sizeProduct);
    }
}

void addZeroOnLastPosition(char array[], size_t &size)
{
    array[size] = '0';
    ++size;
}

void divideLongNumbers(char array1[], char array2[], size_t size1, size_t size2, char quotient[], char remainder[], size_t &sizeQuotient, size_t &sizeRemainder, bool &successfulDivision)
{
    sizeQuotient = 0;
    sizeRemainder = 0;
    successfulDivision = true;

    // if the second number is 0, the division isn't succesfull
    if (size2 == 1 && array2[0] == '0')
    {
        successfulDivision = false;
        return;
    }

    // if the first number is 0, both the quotient and the remainder are equal to 0
    if (size1 == 1 && array1[0] == '0')
    {
        sizeQuotient = 1;
        quotient[0] = '0';
        sizeRemainder = 1;
        remainder[0] = '0';
        return;
    }

    // we will make positive copies (without the minus of these which are negative) for easier work
    // and eventually we will add a minus at the end of the function
    char copyOfArray1[MAX_ARRAY_SIZE], copyOfArray2[MAX_ARRAY_SIZE];
    myStrCpy(array1, copyOfArray1);
    myStrCpy(array2, copyOfArray2);
    size_t copyOfSize1 = size1, copyOfSize2 = size2;

    if (array1[0] == '-')
    {
        removeElementOnFirstPosition(copyOfArray1, copyOfSize1);
    }
    if (array2[0] == '-')
    {
        removeElementOnFirstPosition(copyOfArray2, copyOfSize2);
    }

    int comparison = compareLongNumbers(copyOfArray1, copyOfArray2, copyOfSize1, copyOfSize2);

    // if the second number is bigger that the first
    // the quotient is equal to 0
    // and the remainder is equal to the first number
    if (comparison == 2)
    {
        sizeQuotient = 1;
        quotient[0] = '0';
        myStrCpy(copyOfArray1, remainder);
        sizeRemainder = copyOfSize1;   
    }
    // if the numbers are equal
    // the quotient is equal to 1
    // and the remainder is equal to 0
    else if (comparison == 0)
    {
        sizeQuotient = 1;
        quotient[0] = '1';
        sizeRemainder = 1;
        remainder[0] = '0';
    }
    // if the first number is bigger that the second
    else
    {
        // we take the first (size2) elements of the first number
        char partOfArray1[MAX_ARRAY_SIZE];
        size_t sizeOfPartOfArray1 = 0;
        for (int i = 0; i < copyOfSize2; ++i)
        {
            partOfArray1[i] = copyOfArray1[i];
        }
        sizeOfPartOfArray1 = copyOfSize2;

        // if this part of the first array is smaller than the second array, we add the next digit
        int comparison = compareLongNumbers(partOfArray1, copyOfArray2, sizeOfPartOfArray1, copyOfSize2);
        if (comparison == 2)
        {
            partOfArray1[sizeOfPartOfArray1] = copyOfArray1[sizeOfPartOfArray1];
            ++sizeOfPartOfArray1;
        }

        // method for dividing multi-digit numbers
        // (we studied this is 3-4 grade, idk how it is in English :D)
        for (int i = sizeOfPartOfArray1-1; i < copyOfSize1; ++i)
        {
            // the new part of the first array is equal to the remainder
            if (sizeRemainder > 0)
            {
                for (int j = 0; j < sizeRemainder; ++j)
                {
                    partOfArray1[j] = remainder[j];
                }
                sizeOfPartOfArray1 = sizeRemainder;

                //adding the next digit of the first array
                if (sizeOfPartOfArray1 == 1 && partOfArray1[0] == '0')
                {
                    partOfArray1[0] = copyOfArray1[i];
                    sizeOfPartOfArray1 = 1;
                }
                else
                {
                    partOfArray1[sizeOfPartOfArray1] = copyOfArray1[i];
                    ++sizeOfPartOfArray1;  
                }
            }

            int comparison = compareLongNumbers(partOfArray1, copyOfArray2, sizeOfPartOfArray1, copyOfSize2);
            // if the second number is bigger than the remainder
            if (comparison == 2)
            {
                quotient[sizeQuotient] = '0'; // we add 0 to the quotient
                ++sizeQuotient;
                myStrCpy(partOfArray1, remainder);
                sizeRemainder = sizeOfPartOfArray1;
            }
            // the remainder is bigger or equal to the second number
            else
            {
                // checking which number to add to the quotient by multiplying the numbers from 1 to 9 with the second number
                // then subtracting the result from the remainder
                // the difference is the new remainder
                for (int j = 1; j <= 9; ++j)
                {
                    char product[MAX_ARRAY_SIZE];
                    size_t sizeProduct;
                    multiplyOneDigitNumberWithMultiDigit('0'+j, copyOfArray2, copyOfSize2, product, sizeProduct);
                    int comparison = compareLongNumbers(partOfArray1, product, sizeOfPartOfArray1, sizeProduct);
                    if (comparison == 0)
                    {
                        quotient[sizeQuotient] = '0'+j;
                        ++sizeQuotient;
                        remainder[0] = '0';
                        sizeRemainder = 1;
                        break;
                    }
                    if (comparison == 2)
                    {
                        multiplyOneDigitNumberWithMultiDigit('0'+j-1, copyOfArray2, copyOfSize2, product, sizeProduct);
                        quotient[sizeQuotient] = '0'+j-1;
                        ++sizeQuotient;
                        subtractLongNumbers(partOfArray1, product, sizeOfPartOfArray1, sizeProduct, remainder, sizeRemainder);
                        break;
                    }
                    if (j == 9)
                    {
                        quotient[sizeQuotient] = '9';
                        ++sizeQuotient;
                        subtractLongNumbers(partOfArray1, product, sizeOfPartOfArray1, sizeProduct, remainder, sizeRemainder);
                    }
                }    
            }
        }
    }

    // if exactly one of the numbers is negative, we add '-' to the quotient
    if ((quotient[0] != '0') && ((array1[0] == '-' && array2[0] != '-') || (array1[0] != '-' && array2[0] == '-')))
    {
        addMinus(quotient, sizeQuotient);
    }   

    // the remainder is always positive!
}