#include <iostream>

const int MAX_ROWS_SIZE = 20;
const int MAX_COLUMNS_SIZE = 40;
const int MIN_ARRAY_SIZE = 4;

void printField(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width);

void updateField(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width, int column, int playerTurn);

int checkWinner(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width);

int checkRowColDiag(int element, int& count1, int& count2);

int main ()
{
    int playingField[MAX_ROWS_SIZE][MAX_COLUMNS_SIZE] = {};
    size_t width, height;
    int countInput = 0;

    do
    {
        if (countInput > 0)
        {
            std::cout << "Please enter a height in the range [4, 20] and a width in the range [4, 40]:" << std::endl;
        }
        std::cin >> height >> width;
        ++countInput;
    } while (width < MIN_ARRAY_SIZE || MIN_ARRAY_SIZE < 4 || width > MAX_COLUMNS_SIZE || height > MAX_ROWS_SIZE);

    printField(playingField, height, width);

    int counter = 0, numberOfColumn, playerTurn = 1;
    int columns[MAX_COLUMNS_SIZE] = {};

    while (counter < width*height)
    {
        bool invalidColumn = false;
        do
        {
            std::cin >> numberOfColumn;
            if (numberOfColumn > width || numberOfColumn <= 0)
            {
                std::cout << "There is no such column!" << std::endl;
                invalidColumn = true;
            }
            else if (columns[numberOfColumn-1] == height)
            {
                std::cout << "The column is full!" << std::endl;
                invalidColumn = true;
            }
            else
            {
                invalidColumn = false;
                ++columns[numberOfColumn-1];
            }
            
        } while (invalidColumn);
        
        updateField(playingField, height, width, numberOfColumn, playerTurn);
        playerTurn *= -1;
        ++counter;
        printField(playingField, height, width);

        if (counter >= 7)
        {
            if (checkWinner(playingField, height, width) == 1)
            {
                std::cout << "Player 1 wins!" << std::endl;
                return 0;
            }
            if (checkWinner(playingField, height, width) == -1)
            {
                std::cout << "Player 2 wins!" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "Draw!" << std::endl;
    
    return 0;
}

void printField(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width)
{
    std::cout << std::endl;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (field[i][j] == 0)
            {
                std::cout << "| ";
            }
            else if (field[i][j] == 1)
            {
                std::cout << "|O";
            }
            else
            {
                std::cout << "|X";
            }
        }
        std::cout << "|" << std::endl;
    }
}

void updateField(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width, int column, int playerTurn)
{
    for (int i = height-1; i >= 0; --i)
    {
        if (field[i][column-1] == 0)
        {
            field[i][column-1] = (playerTurn == 1) ? 1 : -1;
            return;
        }
    }
}

int checkWinner(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width)
{
    int countPlayer1 = 0, countPlayer2 = 0;

    // rows
    for (int row = height-1; row >= 0; --row)
    {
        countPlayer1 = 0, countPlayer2 = 0;
        for (int col = 0; col < width; ++col)
        {
            int result = checkRowColDiag(field[row][col], countPlayer1, countPlayer2);
            if (result != 0)
            {
                return result;
            }
        }
    }

    //columns
    for (int col = 0; col < width; ++col)
    {
        countPlayer1 = 0, countPlayer2 = 0;
        for (int row = height-1; row >= 0; --row)
        {
            int result = checkRowColDiag(field[row][col], countPlayer1, countPlayer2);
            if (result != 0)
            {
                return result;
            }
        }
    }

    // diagonals parallel to the secondary diagonal 
    for (int diag = width+height-5; diag >= 3; --diag)
    {
        countPlayer1 = 0, countPlayer2 = 0;
        for (int row = height-1; row >= 0; --row)
        {
            int col = diag - row;
            if (col >= 0 && col <= width-1)
            {
                int result = checkRowColDiag(field[row][col], countPlayer1, countPlayer2);
                if (result != 0)
                {
                    return result;
                }
            }
        }
    }

    // diagonals parallel to the main diagonal 
    for (int diag = -(int)(height-1)+5; diag >= -(int)width+4; --diag)
    {
        countPlayer1 = 0, countPlayer2 = 0;
        for (int row = height-1; row >= 0; --row)
        {
            int col = row - diag;
            if (col >= 0 && col <= width-1)
            {
                int result = checkRowColDiag(field[row][col], countPlayer1, countPlayer2);
                if (result != 0)
                {
                    return result;
                }
            }
        }
    }
    return 0;
}

int checkRowColDiag(int element, int& count1, int& count2)
{
    if (element == 1)
    {
        ++count1;
        count2 = 0;
    }
    else if (element == -1)
    {
        ++count2;
        count1 = 0;
    }
    else
    {
        count1 = 0;
        count2 = 0;
    }

    if (count1 == 4)
    {
        return 1;
    }
    if (count2 == 4)
    {
        return -1;
    }
    return 0;
}