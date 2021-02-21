#include <iostream>

const int MAX_SIZE = 100;

size_t readSize ();

void readMatrix (int array[][MAX_SIZE], size_t size);

bool areThereDifferentNumbersInDiagonals (int array[][MAX_SIZE], size_t size);

int main ()
{
    int numbers[MAX_SIZE][MAX_SIZE];
    size_t size = readSize ();

    readMatrix(numbers, size);

    std::cout << std::endl;

    std::cout << std::boolalpha << areThereDifferentNumbersInDiagonals(numbers, size) << std::endl;

    //areThereDifferentNumbersInDiagonals(numbers, size);

    return 0;
}

size_t readSize ()
{
    int n;
    do
    {
        std::cout << "N = ";
        std::cin >> n;

    } while (n <= 0 || n > MAX_SIZE);
    
    return n;
}

void readMatrix (int array[][MAX_SIZE], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cin >> array[i][j];
        }
    }
}

bool areThereDifferentNumbersInDiagonals (int array[][MAX_SIZE], size_t size)
{
    // diagonals parallel to the main diagonal (diagonal = row - column)
    for (int diag = -(int)(size-2); diag <= (int)(size-2); ++diag)
    {
        int counter = 0;
        int firstElement;
        for (int row = 0; row < size; ++row)
        {
            int col = row - diag;
            if (col >=0 && col <= size-1)
            {
                if (counter == 0)
                {
                    firstElement = array[row][col];
                    ++counter;
                }
                else
                {
                    if (array[row][col] != firstElement)
                    {
                        std::cout << firstElement << " " << array[row][col] << std::endl;
                        return true;
                    }
                }
                //std::cout << array[row][col] << " ";
            }
        }
        //std::cout << std::endl;
    }
    
    //std::cout << std::endl;

    // diagonals parallel to the secondary diagonal (diagonal = row + column)
    for (int diag = 1; diag <= 2*(size-1)-1; ++diag)
    { 
        int counter = 0;
        int firstElement;
        for (int row = 0; row < size; ++row)
        {
            int col = diag - row;
            if (col >=0 && col <= size-1)
            {
                if (counter == 0)
                {
                    firstElement = array[row][col];
                    ++counter;
                }
                else
                {
                    if (array[row][col] != firstElement)
                    {
                        std::cout << firstElement << " " << array[row][col] << std::endl;
                        return true;
                    }
                }
                //std::cout << array[row][col] << " ";
            }
        }
        //std::cout << std::endl;
    }
    return false;
}