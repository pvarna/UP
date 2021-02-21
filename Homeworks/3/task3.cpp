#include <iostream>
#include <cmath>

typedef unsigned char pixel[3];

// wanted function
pixel** fillArea(const pixel *const *const image, size_t width, size_t height, size_t row, size_t column);

// helper recursive function which actually changes the result image
void paint(pixel** image, size_t width, size_t height, int currentRow, int currentColumn, int previousIntensity, bool** haveBeenHere);

// clears the memory
void clearImage(pixel** image, size_t rows);

int main ()
{
    size_t height, width;

    // validation
    int validInput = true;
    do
    {
        if (!validInput)
        {
            std::cout << "Both the height and the width must be bigger than 0" << std::endl;
        }
        validInput = true;

        std::cin >> height >> width;

        if (height == 0 || width == 0)
        {
            validInput = false;
        }
    } while (!validInput);
    

    pixel** mainImage = new(std::nothrow) pixel*[height];
    if (!mainImage)
    {
        std::cout << "Memory problem!" << std::endl;
        return 0;
    }

    for (size_t i = 0; i < height; ++i)
    {
        mainImage[i] = new(std::nothrow) pixel[width];
        if (!mainImage[i])
        {
            std::cout << "Memory problem!" << std::endl;
            clearImage(mainImage, i);
            return 0;
        }
    }

    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            int red, green, blue;
            std::cin >> red >> green >> blue;

            if(!std::cin)
            {
                std::cout << "The values of the pixels must be only numbers!" << std::endl;
                clearImage(mainImage, i);
                return 0;
            }
            if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
            {
                std::cout << "All values of the pixels must be in the range [0, 255]!" << std::endl;
                clearImage(mainImage, i);
                return 0;
            }
            
            mainImage[i][j][0] = (char)red;
            mainImage[i][j][1] = (char)green;
            mainImage[i][j][2] = (char)blue;
        }
    }

    int row, column;

    validInput = true;
    do
    {
        if (!validInput)
        {
            std::cout << "There is not such pixel in the image" << std::endl;
        }
        validInput = true;

        std::cin >> row >> column;

        if (row < 0 || column < 0 || row >= height || column >= width)
        {
            validInput = false;
        }
    } while (!validInput);

    pixel** result = fillArea(mainImage, width, height, row, column);

    if (!result)
    {
        return 0;
    }

    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            // adding brackets and commas for better presentation of the output
            std::cout << "(" << (int)result[i][j][0] << ", " << (int)result[i][j][1] << ", " << (int)result[i][j][2] << ") ";
        }
        std::cout << std::endl;
    }

    clearImage(mainImage, height);
    clearImage(result, height);

    return 0;
}

pixel** fillArea (const pixel *const *const image, size_t width, size_t height, size_t row, size_t column)
{
    pixel** resultImage = new(std::nothrow) pixel*[height];

    if(!resultImage)
    {
        std::cout << "Memory problem!" << std::endl;
        return nullptr;
    }

    for (size_t i = 0; i < height; ++i)
    {
        resultImage[i] = new(std::nothrow) pixel[width];
        if(!resultImage[i])
        {
            std::cout << "Memory problem!" << std::endl;
            clearImage(resultImage, i);
            return nullptr;
        }
    }

    // copy
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            resultImage[i][j][0] = image[i][j][0];
            resultImage[i][j][1] = image[i][j][1];
            resultImage[i][j][2] = image[i][j][2];
        }
    }

    double intensity = ((int)image[row][column][0] + (int)image[row][column][1] + 
                        (int)image[row][column][2])/3.0;

    // bool 2D array that shows if a pixel has already been changed
    bool** haveBeenHere = new(std::nothrow) bool*[height];
    if(!haveBeenHere)
    {
        std::cout << "Memory problem!" << std::endl;
        return nullptr;
    }

    for (size_t i = 0; i < height; ++i)
    {
        haveBeenHere[i] = new(std::nothrow) bool[width];
        if(!haveBeenHere)
        {
            std::cout << "Memory problem!" << std::endl;
            for (int j = 0; j < i; ++j)
            {
                delete[] haveBeenHere[j];
            }
            delete[] haveBeenHere;
            return nullptr;
        }
    }

    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            haveBeenHere[i][j] = false;
        }
    }

    // 4 different directions
    paint(resultImage, width, height, row+1, column, intensity, haveBeenHere);
    paint(resultImage, width, height, row-1, column, intensity, haveBeenHere);
    paint(resultImage, width, height, row, column+1, intensity, haveBeenHere);
    paint(resultImage, width, height, row, column-1, intensity, haveBeenHere);

    for (size_t i = 0; i < height; ++i)
    {
        delete[] haveBeenHere[i];
    }
    delete[] haveBeenHere;

    return resultImage;
}

void paint(pixel ** image, size_t width, size_t height, int currentRow, int currentColumn, int previousIntensity, bool** haveBeenHere)
{
    // check if we are IN the image
    if (currentRow == -1 || currentColumn == -1 || currentRow == height || currentColumn == width)
    {
        return;
    }

    double currentIntensity = ((int)image[currentRow][currentColumn][0] + (int)image[currentRow][currentColumn][1] + 
                                     (int)image[currentRow][currentColumn][2])/3.0;

    // check if we have already changed that pixel
    if (haveBeenHere[currentRow][currentColumn])
    {
        return;
    }

    if (fabs(currentIntensity - previousIntensity) <= 1)
    {
        previousIntensity = currentIntensity;
        haveBeenHere[currentRow][currentColumn] = true;

        image[currentRow][currentColumn][0] = (char)0;
        image[currentRow][currentColumn][1] = (char)0;
        image[currentRow][currentColumn][2] = (char)0;

        paint(image, width, height, currentRow+1, currentColumn, previousIntensity, haveBeenHere);
        paint(image, width, height, currentRow-1, currentColumn, previousIntensity, haveBeenHere);
        paint(image, width, height, currentRow, currentColumn+1, previousIntensity, haveBeenHere);
        paint(image, width, height, currentRow, currentColumn-1, previousIntensity, haveBeenHere);
    }
}

void clearImage(pixel** image, size_t rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] image[i];
    }
    delete[] image;
}

