#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <iomanip>
// class Student
// {
// private:
//     std::string name;
//     std::uint16_t homework;
//     std::uint16_t midterm;
//     std::uint16_t finalExam;

// public:
//     std::uint16_t getNumberBetween100(std::string par_text);
//     void readStudentData(std::string &par_name, std::uint16_t &par_homework, std::uint16_t &par_midterm, std::uint16_t &par_finalExam);
// };
/**
 * @brief Get the Number Between100 object
 * 
 * @param par_text 
 * @return std::uint16_t 
 */
std::uint16_t getNumberBetween100(std::string par_text)
{
    int par_value = 0;
    do
    {
        std::cout << par_text << std::endl;

        if (!(std::cin >> par_value))
        {
            std::cout << "Input error please try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            par_value = 101;
        }
    } while (par_value > 100);
    return static_cast<std::uint16_t>(par_value);
};
/**
 * @brief 
 * 
 * @param par_name 
 * @param par_homework 
 * @param par_midterm 
 * @param par_finalExam 
 */
void readStudentData(std::string &par_name, std::uint16_t &par_homework, std::uint16_t &par_midterm, std::uint16_t &par_finalExam)
{
    std::cout << "Please insert your name" << std::endl;
    std::getline(std::cin, par_name);

    par_homework = getNumberBetween100("Please insert homework grade");
    par_midterm = getNumberBetween100("Please insert midterm grade");
    par_finalExam = getNumberBetween100("Please insert final exam grade");
};
/**
 * @brief 
 * 
 * @param homework 
 * @param midterm 
 * @param finalExam 
 * @param finalGrade 
 * @param letterGrade 
 * @param par_status 
 */
void calculateGrade(std::uint16_t &homework, std::uint16_t &midterm, std::uint16_t &finalExam, std::uint16_t &finalGrade, std::string &letterGrade, std::string &par_status)
{
    double temp = (std::uint16_t)(0.4 * (double)(homework) + 0.25 * (double)(midterm) + 0.35 * (double)(finalExam));
    finalGrade = static_cast<int>(temp);
    if (temp < 51)
    {
        letterGrade = "F";
        par_status = "FAIL";
    }
    else if (temp < 61)
    {
        letterGrade = "E";
        par_status = "CONTITIONAL PASS";
    }
    else if (temp < 71)
    {
        letterGrade = "D";
        par_status = "CONDITIONAL PASS";
    }
    else if (temp < 81)
    {
        letterGrade = "C";
        par_status = "PASS";
    }
    else if (temp < 91)
    {
        letterGrade = "B";
        par_status = "PASS";
    }
    else
    {
        letterGrade = "A";
        par_status = "PASS";
    }
};
/**
 * @brief 
 * 
 * @param par_name 
 * @param par_homework 
 * @param par_midterm 
 * @param par_finalExam 
 * @param par_finalGrade 
 * @param par_letterGrade 
 * @param par_status 
 */
void printReport(std::string &par_name, std::uint16_t &par_homework, std::uint16_t &par_midterm, std::uint16_t &par_finalExam, std::uint16_t &par_finalGrade, std::string &par_letterGrade, std::string &par_status)
{
    const std::uint16_t SPACE = 14;
    std::cout << std::endl;
    std::cout << std::setw(SPACE) << std::left << "Letter" << "Status" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << std::setw(SPACE) << "A,B,C" << std::left << "PASS" << std::endl;
    std::cout << std::setw(SPACE) << "D,E" << std::left << "CONDITIONAL PASS" << std::endl;
    std::cout << std::setw(SPACE) << "F" << std::left << "FAIL" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Student Report" << std::endl;
    std::cout << "Name: " << par_name << std::endl
              << std::endl;
    std::cout << "Scores" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << std::setw(SPACE) << "Homework" << std::left << ": " << par_homework << std::setprecision(2) << std::endl;
    std::cout << std::setw(SPACE) << "Midterm" << std::left << ": " << par_midterm << std::setprecision(2) << std::endl;
    std::cout << std::setw(SPACE) << "Final" << std::left << ": " << par_finalExam << std::setprecision(2) << std::endl
              << std::endl;
    std::cout << std::setw(SPACE) << "Final Grade" << std::left << ": " << par_finalGrade << std::setprecision(2) << std::endl;
    std::cout << std::setw(SPACE) << "Letter Grade" << std::left << ": " << par_letterGrade << std::setprecision(2) << std::endl;
    std::cout << std::setw(SPACE) << "Status" << std::left << ": " << par_status << std::setprecision(2) << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}
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