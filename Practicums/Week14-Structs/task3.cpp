#include <iostream>

struct Marks
{
    double test1;
    double test2;
    double homework1;
    double homework2;
    double homework3;
    double examTheory;
    double examProblems;
};

void readMarks(Marks& marks);

double calculateFinalMark(Marks marks);

int main ()
{
    Marks marksPesho;

    readMarks(marksPesho);

    std::cout << calculateFinalMark(marksPesho) << std::endl;

    return 0;
}

void readMarks(Marks& marks)
{
    std::cout << "Test 1: ";
    std::cin >> marks.test1;

    std::cout << "Test 2: ";
    std::cin >> marks.test2;

    std::cout << "Homework 1: ";
    std::cin >> marks.homework1;

    std::cout << "Homework 2: ";
    std::cin >> marks.homework2;

    std::cout << "Homework 3: ";
    std::cin >> marks.homework3;

    std::cout << "Theory exam: ";
    std::cin >> marks.examTheory;

    std::cout << "Problems exam: ";
    std::cin >> marks.examProblems;
}

double calculateFinalMark(Marks marks)
{
    double homeworks = (marks.homework1 + marks.homework2 + marks.homework3) / 3;
    double testsHomeworks = (marks.test1 + marks.test2 + homeworks) / 3;
    double exams = (marks.examTheory + marks.examProblems) / 2;
    return (testsHomeworks*0.5 + exams*0.5);
}