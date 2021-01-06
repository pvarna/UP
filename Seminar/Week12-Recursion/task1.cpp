#include <iostream>

void resize(char* &str, size_t& size) {
	char* oldStr = str;
	str = new char[size*2];

	for (int i = 0; i < size; i++) {
		str[i] = oldStr[i];
	}
	size *= 2;
	delete[] oldStr;
}

char* insertText(char endingSymbol) {
	size_t size = 2;
	size_t counter = 0;
	char* text = new char [size]{};

	std::cout << "Insert text: " << std::endl;
	char symbol;
    std::cin.get(symbol);

	while (symbol != endingSymbol) {
    	if (counter >= size - 1) {
        	resize(text, size);
        }
        text[counter++] = symbol;
        std::cin.get(symbol);
    }
    text[counter] = '\0';

    return text;
}

void printStrV1(char* str)
{
    if (*str == '\0')
    {
        std::cout << std::endl;
        return;
    }

    std::cout << *str;
    printStrV1(str+1);
}

int main ()
{
    char* text = insertText('\n');
    printStrV1(text);

    return 0;
}