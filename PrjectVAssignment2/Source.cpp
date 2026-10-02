#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


struct STUDENT_DATA {
    string FirstName;
    string LastName;

};


int main()
{
    std::vector<STUDENT_DATA> students;

    std::ifstream inFile("StudentData.txt");
    if (!inFile.is_open())
    {
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        if (line.empty())
            continue; // Skip empty lines

        std::stringstream ss(line);
        std::string first, last;

        // Each line is "first,last"
        if (std::getline(ss, first, ',') && std::getline(ss, last))
        {
            STUDENT_DATA student;
            student.FirstName = first;
            student.LastName = last;
            students.push_back(student);
        }
    }

    inFile.close();
}