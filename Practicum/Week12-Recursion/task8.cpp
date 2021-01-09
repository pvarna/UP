#include <iostream>

void bucketPaint(char matrix[][100], int height, int width, int currentI, int currentJ, char oldCh, char newCh);

int main ()
{
    int height, width;

    std::cin >> height >> width;

    char matrix[100][100];

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    int startI, startJ;
    std::cin >> startI >> startJ;

    char ch;
    std::cin >> ch;

    bucketPaint(matrix, height, width, startI, startJ, matrix[startI][startJ], ch);

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

void bucketPaint(char matrix[][100], int height, int width, int currentI, int currentJ, char oldCh, char newCh)
{
    if (matrix[currentI][currentJ] != oldCh || matrix[currentI][currentJ] == newCh || currentI == -1 || currentJ == -1 || currentI == height || currentJ == width)
    {
        return;
    }
    if (matrix[currentI][currentJ] == oldCh)
    {
        matrix[currentI][currentJ] = newCh;
    }
    bucketPaint(matrix, height, width, currentI+1, currentJ, oldCh, newCh);
    bucketPaint(matrix, height, width, currentI-1, currentJ, oldCh, newCh);
    bucketPaint(matrix, height, width, currentI, currentJ+1, oldCh, newCh);
    bucketPaint(matrix, height, width, currentI, currentJ-1, oldCh, newCh);
}