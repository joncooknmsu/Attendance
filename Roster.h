//
// Class Roster definition
//
#ifndef ROSTER_H
#define ROSTER_H
#include "AttendanceApp.h"
#include "Student.h"
#include <string>
#include <vector>

class Roster
{
 public:
    Roster() {};
    bool addStudent(Student* student);
    Student* selectStudent();
    void callOccurred();
    void addAttendDate(std::string date);
    void saveRoster(const std::string& filename = "_loadfile_") const;
    bool loadFile(const std::string& filename);

 private:
    std::vector<Student*> roster;
    int count = 0;
    int totalCalls = 0;
    unsigned int callIndex = 0;
    std::string dataFilename;
    std::vector<std::string> columnNames{};
};

#endif // ROSTER_H
