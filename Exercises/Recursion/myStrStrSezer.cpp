#include <iostream>
using namespace std;

bool doesContain(char* mainArr, char* secondArr) {

	/*if (*mainArr == '\0') {
		return true;
	}*/

	/*for (int i = 0; secondArr[i] != '\0'; i++) {
		if (*mainArr == secondArr[i]) {
			return doesContain(mainArr + 1, secondArr);
		}
	}*/    
    bool doesCurrentLetterContain = false;
    if (!isThereLetter(secondArr, *mainArr))
    {
        doesCurrentLetterContain = false;
    }
    else
    {
        doesCurrentLetterContain = isThereLetter(secondArr, *(mainArr+1));   
    }    

	//return false;
}

bool isThereLetter(char* array, char letter)
{
    if(!(*array))
    {
        return false;
    }
    if (*array == letter)
    {
        return true;
    }
    return isThereLetter(array+1, letter);
}

int main()
{
	char mainArr[100];
	char secondArr[100];
	cin.getline(mainArr, 100);
	cin.getline(secondArr, 100);
	if (doesContain(mainArr, secondArr)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}