#include <iostream>

struct Student
{
    char name[100];
    int facultyNumber;
    int course;
    int group;
};

void readStudent(Student& student);

void findStudent(Student* students, int numberOfStudents, int searchedFacultyNumber);

int main ()
{
    int n;

    std::cin >> n;

    Student* students = new(std::nothrow) Student[n];

    for (int i = 0; i < n; ++i)
    {
        readStudent(students[i]);
    }

    int facNumber;

    std::cin >> facNumber;

    findStudent(students, n, facNumber);

    delete[] students;

    return 0;
}

void readStudent(Student& student)
{
    std::cout << "Enter a name: ";
    std::cin.ignore();
    std::cin.getline(student.name, 100);

    std::cout << "Enter a faculty number: ";
    std::cin >> student.facultyNumber;

    std::cout << "Enter a course number: ";
    std::cin >> student.course;

    std::cout << "Enter a group number: ";
    std::cin >> student.group;
}

void findStudent(Student* students, int numberOfStudents, int searchedFacultyNumber)
{
    for (int i = 0; i < numberOfStudents; ++i)
    {
        if (students[i].facultyNumber == searchedFacultyNumber)
        {
            std::cout << "Name: " << students[i].name << std::endl;
            std::cout << "Faculty number: " << students[i].facultyNumber << std::endl;
            std::cout << "Course: " << students[i].course << std::endl;
            std::cout << "Group: " << students[i].group << std::endl; 
            return;
        }
    }
    std::cout << "There is no such student" << std::endl;
}