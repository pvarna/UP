#include <iostream>

enum CellState
{
    EMPTY,
    PLAYER_1,
    PLAYER_2
};

enum WinSeq
{
    NONE,
    VERTICAL,
    HORIZONTAL,
    DIAGONAL
};

void printPlayingField(CellState playingField[][3]);

WinSeq checkForWinner(CellState playingField[][3]);

int main ()
{
    CellState playingField[3][3];
    WinSeq result = NONE;
    int n = 0;
    bool player1Turn = true;
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            playingField[i][j] = EMPTY;
        }
    }

    do
    {
        int i, j;
        do
        {
            std::cout << (player1Turn ? "Player 1: " : "Player 2: ");
            std::cin >> i >> j;
        } while (i < 1 || i > 3 || j < 1 || j > 3);
        
        playingField[i-1][j-1] = (player1Turn ? PLAYER_1 : PLAYER_2);
        
        printPlayingField(playingField);

        result = checkForWinner(playingField);

        player1Turn = !player1Turn;
        ++n;


    } while (n < 9 && result == NONE);
    
    if (result == NONE)
    {
        std::cout << "Draw!" << std::endl;
    }
    else 
    {
        std::cout << (player1Turn ? "Player 2 " : "Player 1 ") << "wins by ";
        switch (result)
        {
        case VERTICAL:
            std::cout << "vertical" << std::endl;
            break;
        
        case HORIZONTAL:
            std::cout << "horizontal" << std::endl;
            break;

        case DIAGONAL:
            std::cout << "diagonal" << std::endl;
            break;
        }
    }

    return 0;
}

void printPlayingField(CellState playingField[][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            switch (playingField[i][j])
            {
            case PLAYER_1:
                std::cout << "X ";
                break;
            
            case PLAYER_2:
                std::cout << "O ";
                break;
            
            default:
                std::cout << "  ";
                break;
            }
        }
        std::cout << std::endl;
    }
}

WinSeq checkForWinner(CellState playingField[][3])
{
    if ((playingField[0][0] == playingField[1][1] && playingField[1][1] == playingField[2][2] && playingField[2][2] != EMPTY)
            || (playingField[0][2] == playingField[1][1] && playingField[1][1] == playingField[2][0] && playingField[2][0] != EMPTY))
        return DIAGONAL;

    if ((playingField[0][0] == playingField[0][1] && playingField[0][1] == playingField[0][2] && playingField[0][2] != EMPTY)
            || (playingField[1][0] == playingField[1][1] && playingField[1][1] == playingField[1][2] && playingField[1][2] != EMPTY)
            || (playingField[2][0] == playingField[2][1] && playingField[2][1] == playingField[2][2] && playingField[2][2] != EMPTY))
        return HORIZONTAL;

    if ((playingField[0][0] == playingField[1][0] && playingField[1][0] == playingField[2][0] && playingField[2][0] != EMPTY)
        || (playingField[0][1] == playingField[1][1] && playingField[1][1] == playingField[2][1] && playingField[2][1] != EMPTY)
        || (playingField[0][2] == playingField[1][2] && playingField[1][2] == playingField[2][2] && playingField[2][2] != EMPTY))
    return VERTICAL;

    return NONE;
}