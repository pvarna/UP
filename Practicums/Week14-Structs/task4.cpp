#include <iostream>
#include <cstring>

const int MAX_STRING_SIZE = 100;
const int ISBN_SIZE = 13;
const int MAX_BOOKS = 1000;

struct Book
{
    char title[MAX_STRING_SIZE];
    char author[MAX_STRING_SIZE];
    char ISBN[ISBN_SIZE];
};

struct Library
{
    Book books[MAX_BOOKS];
    int numberOfBooks = 0;
};

void addBook(Library& library);

void removeBook(Library& library);

void printNumberOfBooks(Library library);

void printMenu();

int main ()
{
    int option;
    Library myLibrary;

    do
    {
        printMenu();

        std::cout << "Please choose an option: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option)
        {
        case 1:
            addBook(myLibrary);
            break;
        case 2:
            removeBook(myLibrary);
            break;
        case 3:
            printNumberOfBooks(myLibrary);
            break;
        }

    } while (option > 0);
    
    return 0;
}

void addBook(Library& library)
{
    Book newBook;

    std::cout << "Please enter the title of the book: ";
    std::cin.ignore();
    std::cin.getline(newBook.title, MAX_STRING_SIZE);
    std::cout << "Please enter the author of the book: ";
    std::cin.ignore();
    std::cin.getline(newBook.author, MAX_STRING_SIZE);
    std::cout << "Please enter the ISBN of the book: ";
    std::cin.ignore();
    std::cin.getline(newBook.ISBN, ISBN_SIZE);

    library.books[library.numberOfBooks] = newBook;
    ++library.numberOfBooks;

    std::cout << "The book has been added successfully" << std::endl;
}

void removeBook(Library& library)
{
    char searchedISBN[ISBN_SIZE];

    std::cout << "Please enter the ISBN of the book you want to remove: ";
    std::cin.ignore();
    std::cin.getline(searchedISBN, ISBN_SIZE);

    int index = -1;
    for (int i = 0; i < library.numberOfBooks; ++i)
    {
        if (strcmp(searchedISBN, library.books[i].ISBN) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        std::cout << "There is no such book" << std::endl;
    }

    else
    {
        for (int i = index; i < library.numberOfBooks-1; ++i)
        {
            library.books[i] = library.books[i+1];
        }
        --library.numberOfBooks;

        std::cout << "The book has been removed successfully" << std::endl;
    }
}

void printNumberOfBooks(Library library)
{
    std::cout << "The current number of the books is: " << library.numberOfBooks << std::endl;
}

void printMenu()
{
    std::cout << '\t' << '\t' << "Menu" << std::endl;
    std::cout << "1. Add a book to the Library" << std::endl;
    std::cout << "2. Remove a book from the Library" << std::endl;
    std::cout << "3. Get the number of books in the Library" << std::endl;
    std::cout << "0. Exit" << std::endl;
}