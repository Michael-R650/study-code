#include <iostream>
#include <string>
#include <cstdint>
#include "header.hpp"
int main()
{
    std::string name = "";
    std::uint16_t homework = 0;
    std::uint16_t midterm = 0;
    std::uint16_t finalExam = 0;
    std::uint16_t finalGrade = 0;
    std::string letterGrade = "";
    std::string status = "";

    readStudentData(name, homework, midterm, finalExam);
    calculateGrade(homework, midterm, finalExam, finalGrade, letterGrade, status);
    printReport(name, homework, midterm, finalExam, finalGrade, letterGrade, status);
    return 0;
}