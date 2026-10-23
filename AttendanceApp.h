#ifndef CALLONAPP_H
#define CALLONAPP_H
#include "Buttons.h"
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>

class Roster;
class Student;

class AttendanceApp : public Fl_Window
{
 public:
    AttendanceApp(Roster& roster)
          : // create a GUI window object
            Fl_Window{400, 280, "Attendanc-er"}, roster{roster}, curStudent{0}
    {    }
    const char* callee() { return calleeName->value(); }
    void createWindow(int argc, char* argv[]);
    bool markStudent(bool attend);
    bool selectNewStudent();

 private:
    Roster& roster;
    Student* curStudent;
    Fl_Input* curDate;
    Fl_Output* attendanceView;
    Fl_Output* calleeName;
    //Fl_Button* nextCallee;
    AttendButton* attendHere;
    AttendButton* attendAbsent;
};

#endif // CALLONAPP_H
