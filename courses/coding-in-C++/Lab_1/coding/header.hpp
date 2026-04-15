#ifndef STUDENT
#define STUDENT

#include <string>
#include <cstdint>
std::uint16_t getNumberBetween100(std::string par_text);
void readStudentData(std::string &par_name, std::uint16_t &par_homework, std::uint16_t &par_midterm, std::uint16_t &par_finalExam);
void calculateGrade(std::uint16_t &homework, std::uint16_t &midterm, std::uint16_t &finalExam, std::uint16_t &finalGrade, std::string &letterGrade, std::string &par_status);
void printReport(std::string &par_name, std::uint16_t &par_homework, std::uint16_t &par_midterm, std::uint16_t &par_finalExam, std::uint16_t &par_finalGrade, std::string &par_letterGrade, std::string &par_status);
#endif
