//
// Class Student definition
//
#ifndef STUDENT_H
#define STUDENT_H
//#include <fstream>
//#include <iostream>
#include <string>
//#include <sstream>
//#include <vector>
//#include <random>

class Student
{
 public:
    Student(const std::string dataString);
    const std::string displayString() const;
    int calls() const;
    const std::string saveString() const;
    bool countResponse(bool attend);

 private:
    std::string name;
    int numAttends;
    int numAbsences;
    float avgScore;
};

#endif // STUDENT_H
