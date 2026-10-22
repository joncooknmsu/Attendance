#include "AttendanceApp.h"
#include "Roster.h"
#include "atticon.xpm"
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_RGB_Image.H>

bool AttendanceApp::markStudent(bool attend)
{
    if (!curStudent) {
        //calleeName->value("  choose again!");
        return false;
    }
    curStudent->countResponse(attend);
    roster.callOccurred();
    //calleeName->value("      processed!");
    //roster.saveRoster("roster.csv");
    //roster.saveRoster();
    curStudent = 0;
    return true;
}

bool AttendanceApp::selectNewStudent()
{
    curStudent = roster.selectStudent();
    if (curStudent)
        calleeName->value(curStudent->displayString().c_str());
    else {
        calleeName->value("All Done!");
        roster.saveRoster();
    }
    return true;
}

void AttendanceApp::createWindow(int argc, char* argv[])
{
    // labelsize(34); // seems not to inherit
    // begin window sub-components
    begin();
    calleeName = new Fl_Output(30, 20, 340, 50, 0);
    //calleeName->value("   choose next");
    calleeName->textfont(FL_HELVETICA_BOLD);
    calleeName->textsize(28);
    //nextCallee = new NewStudentButton(this, 125, 100, 150, 40, "Next Callee");
    //nextCallee->labelsize(24);
    attendHere = new AttendButton(this, true, 30, 90, 330, 40, "Here");
    attendHere->labelsize(24);
    attendAbsent = new AttendButton(this, false, 30, 150, 330, 40, "Absent");
    attendAbsent->labelsize(24);
    // declare the drawing area to be resizable
    // mainWindow.resizable(drawer);
    // end window sub-components
    end();
    // set window icon?
    Fl_Pixmap attend_xpm_icon(atticon_xpm);
    Fl_RGB_Image attend_icon(&attend_xpm_icon, Fl_Color(0));
    icon(&attend_icon);
    xclass("Attendance");
    // display the window
    selectNewStudent();
    show(argc, argv);
}
