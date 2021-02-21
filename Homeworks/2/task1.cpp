#include <iostream>

const int MAX_ROWS_SIZE = 20;
const int MAX_COLUMNS_SIZE = 40;
const int MIN_ARRAY_SIZE = 4;

// input + validation
void readSize (size_t& height, size_t& width);

// prints the current version of the playing field
void printField(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width);

// updates the playing field by adding 1 or -1 on the chosen column (which is already validated)
void updateField(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width, int column, int playerTurn);

// checks if there is a winner
int checkWinner(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width);

// helper function of the "checkWinner" function which checks if an element is the fourth consecutive in a row, column or diagonal 
int checkRowColDiag(int element, int& count1, int& count2);

int main ()
{
    // the field will be a 2D array of ints
    // at the start of the game the array is full of zeroes
    // player 1's symbol 'O' ---->  1
    // player 2's symbol 'X' ----> -1
    int playingField[MAX_ROWS_SIZE][MAX_COLUMNS_SIZE] = {};
    size_t height, width;
    
    readSize(height, width);

    printField(playingField, height, width);

    // if playerTurn =  1, it is player 1's turn
    // if playerTurn = -1, it is player 2's turn
    int numberOfTurns = 0, numberOfColumn, playerTurn = 1; 
    int columns[MAX_COLUMNS_SIZE] = {}; // array that will count how many element are there in each column

    // players make their moves until one of them is a winner or the array is full
    while (numberOfTurns < width*height)
    {
        bool validColumn = true;

        // validation of the number of the chosen column (the column must exist and it mustn't be full)
        do
        {
            std::cin >> numberOfColumn;
            if (numberOfColumn > width || numberOfColumn <= 0)
            {
                std::cout << "There is no such column!" << std::endl; // print a message if there is a invalid input
                validColumn = false;
            }
            else if (columns[numberOfColumn-1] == height)
            {
                std::cout << "The column is full!" << std::endl; // print a message if there is a invalid input
                validColumn = false;
            }
            else
            {
                validColumn = true;
                ++columns[numberOfColumn-1];
            }
            
        } while (!validColumn);
        
        updateField(playingField, height, width, numberOfColumn, playerTurn);
        playerTurn *= -1; // change of turn (1*(-1)=(-1), (-1)*(-1)=1)
        ++numberOfTurns;
        printField(playingField, height, width); // printing the new field

        // the first possible turn in which we can have a winner is the seventh one 
        // because the first player will have already placed four symbols
        if (numberOfTurns >= 7)
        {
            if (checkWinner(playingField, height, width) == 1)
            {
                std::cout << "Player 1 wins!" << std::endl;
                return 0; // Game Over for Player 2 :D
            }
            if (checkWinner(playingField, height, width) == -1)
            {
                std::cout << "Player 2 wins!" << std::endl;
                return 0; // Game Over for Player 1 :D
            }
        }
    }
    std::cout << "Draw!" << std::endl; // if there is no winner after (width*height) turns, it is a Draw
    
    return 0;
}

void readSize (size_t& height, size_t& width)
{
    int counter = 0;

    do
    {
        if (counter > 0) // print a message if there is a invalid input
        {
            std::cout << "Please enter a height in the range [4, 20] and a width in the range [4, 40]:" << std::endl;
        }
        std::cin >> height >> width;
        ++counter;
    } while (width < MIN_ARRAY_SIZE || height < MIN_ARRAY_SIZE || width > MAX_COLUMNS_SIZE || height > MAX_ROWS_SIZE);
}

void printField(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width)
{
    std::cout << std::endl;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (field[i][j] == 0) // empty cell
            {
                std::cout << "| ";
            }
            else if (field[i][j] == 1) // player 1's cell
            {
                std::cout << "|O";
            }
            else // player 2's cell
            {
                std::cout << "|X";
            }
        }
        std::cout << "|" << std::endl; // closing symbol of the last column
    }
}

void updateField(int field[][MAX_COLUMNS_SIZE], size_t height, size_t width, int column, int playerTurn)
{
    for (int i = height-1; i >= 0; --i)
    {
        if (field[i][column-1] == 0) // first free cell from bottom to top on the given column
        {
            field[i][column-1] = (playerTurn == 1) ? 1 : -1; // add 1 or -1 depending on which player's turn it is
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
        countPlayer1 = 0, countPlayer2 = 0; // restart the counters, we are currently inspecting a new row
        for (int col = 0; col < width; ++col)
        {
            int result = checkRowColDiag(field[row][col], countPlayer1, countPlayer2);
            if (result != 0) // there is a winner
            {
                return result;
            }
        }
    }

    // columns
    for (int col = 0; col < width; ++col)
    {
        countPlayer1 = 0, countPlayer2 = 0; // restart the counters, we are currently inspecting a new column
        for (int row = height-1; row >= 0; --row)
        {
            int result = checkRowColDiag(field[row][col], countPlayer1, countPlayer2);
            if (result != 0) // there is a winner
            {
                return result;
            }
        }
    }

    // diagonals parallel to the secondary diagonal 
    for (int diag = width+height-5; diag >= 3; --diag)
    {
        countPlayer1 = 0, countPlayer2 = 0; // restart the counters, we are currently inspecting a new diagonal
        for (int row = height-1; row >= 0; --row)
        {
            int col = diag - row;
            if (col >= 0 && col <= width-1)
            {
                int result = checkRowColDiag(field[row][col], countPlayer1, countPlayer2);
                if (result != 0) // there is a winner
                {
                    return result;
                }
            }
        }
    }

    // diagonals parallel to the main diagonal 
    for (int diag = height-4; diag >= -(int)width+4; --diag)
    {
        countPlayer1 = 0, countPlayer2 = 0; // restart the counters, we are currently inspecting a new diagonal
        for (int row = height-1; row >= 0; --row)
        {
            int col = row - diag;
            if (col >= 0 && col <= width-1)
            {
                int result = checkRowColDiag(field[row][col], countPlayer1, countPlayer2);
                if (result != 0) // there is a winner
                {
                    return result;
                }
            }
        }
    }
    return 0; // there is no a winner 
}

int checkRowColDiag(int element, int& count1, int& count2)
{
    //count1 counts the number of consecutive 'O's
    //count2 counts the number of consecutive 'X's

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

    if (count1 == 4) // there are four consecutive 'O's
    {
        return 1; // player 1 wins!
    }
    if (count2 == 4) // there are four consecutive 'X's
    {
        return -1; // player 2 wins!
    }

    return 0; // there is no winner 
}