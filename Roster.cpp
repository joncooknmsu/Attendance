//
// Class Roster and Student definitions
//
#include "Roster.h"
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

bool Roster::addStudent(Student* student)
{
    roster.push_back(student);
    count++;
    return true;
}

Student* Roster::selectStudent()
{
    if (callIndex >= roster.size()) {
        return nullptr;
    }
    //std::cerr << "Returning selection at " << callIndex << ": "
    //          << callOnSequence[callIndex] << "\n";
    return roster[callIndex++];
}

void Roster::callOccurred()
{
    totalCalls++;
}

void Roster::addAttendDate(std::string date)
{
    columnNames.push_back(date);
}

void Roster::saveRoster(const std::string& filename) const
{
    std::string usedFilename = filename;
    if (filename == "_loadfile_") {
        usedFilename = dataFilename;
    }
    std::ofstream dataf(usedFilename);
    //dataf << "Student,Attends,Absences,";
    bool first = true;
    for (auto d: columnNames) {
        if (!first)
            dataf << ",";
        else
            first = false;
        dataf << d;
    }
    dataf << "\n";
    for (auto student : roster) {
        dataf << student->saveString() << "\n";
    }
    dataf.close();
}
bool Roster::loadFile(const std::string& filename)
{
    dataFilename = filename;
    std::ifstream dataf(filename);
    std::string line;
    if (!dataf)
        return false;
    // extract date columns from first line
    std::getline(dataf, line);
    std::istringstream dstream(line);
    std::string datum;
    while (std::getline(dstream, datum, ',')) {
        if (datum.length() < 2) break;
        columnNames.push_back(datum);
    }
    while (std::getline(dataf, line)) {
        // std::cout << "line is [" << line << "]\n";
        if (line.length() < 2)
            continue; // probably at end of file
        /**
        std::istringstream ss(line);
        std::string piece;
        while (std::getline(ss, piece, ',')) {
            // std::cout << "  piece [" << piece << "]\n";
        }
        **/
        auto student = new Student(line);
        // std::cout << "student is [" << student->saveString() << "]\n";
        addStudent(student);
    }
    dataf.close();
    if (roster.size() < 1)
        return false;
    return true;
}
