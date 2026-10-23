//
// Student class
//
#include "Student.h"
#include <iostream>
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
    //std::cerr << "----\n";
    while (std::getline(dstream, datum, ',')) {
        if (datum.length() < 1) break;
        //std::cerr << "datef: (" << datum << ")\n";
        bool att = std::stoi(datum);
        attends.push_back(att);
    }
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
    std::string ret;
    ret = name + "," + std::to_string(numAttends) + "," +
           std::to_string(numAbsences); // + "," + std::to_string(avgScore);
    for (int i: attends) {
        ret += "," + std::to_string(i);
    }
    return ret;
}

bool Student::countResponse(bool attend)
{
    attends.push_back(attend);
    if (attend)
        numAttends++;
    else
        numAbsences++;
    //double oldTotal = avgScore * (numAttends + numAbsences);
    //avgScore = (oldTotal + response) / (double)numAttends;
    avgScore = numAttends / (double)(numAttends + numAbsences);
    return true;
}
