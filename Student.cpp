//
// Student class
//
#include "Student.h"
#include <sstream>

Student::Student(const std::string dataString)
{
    std::istringstream dstream(dataString);
    std::string datum;
    name = "Unknown";
    avgScore = numAttends = numAbsences = 0;
    if (std::getline(dstream, datum, ','))
        name = datum;
    if (std::getline(dstream, datum, ','))
        numAttends = std::stoi(datum);
    if (std::getline(dstream, datum, ','))
        numAbsences = std::stoi(datum);
    if (std::getline(dstream, datum, ','))
        avgScore = std::stof(datum);
}

const std::string Student::displayString() const
{
    return name;
}

int Student::calls() const
{
    return numAttends;
}

const std::string Student::saveString() const
{
    return name + "," + std::to_string(numAttends) + "," +
           std::to_string(numAbsences) + "," + std::to_string(avgScore);
}

bool Student::countResponse(bool attend)
{
    if (attend)
        numAttends++;
    else
        numAbsences++;
    //double oldTotal = avgScore * (numAttends + numAbsences);
    //avgScore = (oldTotal + response) / (double)numAttends;
    avgScore = numAttends / (double)(numAttends + numAbsences);
    return true;
}
