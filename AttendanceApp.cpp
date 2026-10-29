#include "AttendanceApp.h"
#include "Roster.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_RGB_Image.H>
#include <ctime>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "atticon.xpm"
#pragma GCC diagnostic pop

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
    static bool saved = false;
    curStudent = roster.selectStudent();
    if (curStudent) {
        calleeName->value(curStudent->displayString().c_str());
        attendanceView->value(curStudent->attendanceString().c_str());
    } else {
        if (!saved) {
            calleeName->value("All Done!");
            roster.addAttendDate(curDate->value());
            roster.saveRoster();
            saved = true;
        }
    }
    return true;
}

void AttendanceApp::createWindow(int argc, char* argv[])
{
    // labelsize(34); // seems not to inherit
    // begin window sub-components
    begin();
    Fl_Pack* mainPack = new Fl_Pack(10, 5, 430, 0);
    mainPack->spacing(5);
    mainPack->begin();
    Fl_Pack* datePack = new Fl_Pack(0, 0, 380, 50);
    datePack->type(Fl_Pack::HORIZONTAL);
    datePack->spacing(10);
    datePack->begin();
    Fl_Box* dateLabel = new Fl_Box(0, 0, 80, 0, "Date:");
    dateLabel->labelfont(FL_HELVETICA);
    dateLabel->labelsize(26);
    curDate = new Fl_Input(0, 0, 200, 0, 0);
    //curDate->value("10/10/2026");
    std::time_t tnow = std::time(0);
    std::tm* now = std::gmtime(&tnow);
    char cdate[36];
    //std::strftime(cdate, sizeof(cdate), "%m/%d/%Y", now);
    std::strftime(cdate, sizeof(cdate), "%m/%d", now);
    curDate->value(cdate);
    curDate->textfont(FL_HELVETICA);
    curDate->textsize(26);
    datePack->end();
    calleeName = new Fl_Output(0, 0, 0, 50, 0);
    //calleeName->value("   choose next");
    calleeName->textfont(FL_HELVETICA_BOLD);
    calleeName->textsize(28);
    attendHere = new AttendButton(this, true, 0, 0, 0, 40, "Here");
    attendHere->labelsize(24);
    attendAbsent = new AttendButton(this, false, 0, 0, 0, 40, "Absent");
    attendAbsent->labelsize(24);
    // list of attendance values
    Fl_Pack* attPack = new Fl_Pack(0, 0, 430, 35);
    attPack->type(Fl_Pack::HORIZONTAL);
    attPack->spacing(10);
    attPack->begin();
    Fl_Box* attLabel = new Fl_Box(0, 0, 40, 0, "Att:");
    attLabel->labelfont(FL_HELVETICA);
    attLabel->labelsize(22);
    attendanceView = new Fl_Output(0, 0, 380, 40, 0);
    attendanceView->value("nothing yet");
    attendanceView->textfont(FL_HELVETICA);
    attendanceView->textsize(20);
    attPack->end();
    // declare the drawing area to be resizable
    // mainWindow.resizable(drawer);
    // end window sub-components
    mainPack->end();
    end(); // end window components
    // set window icon?
    Fl_Pixmap attend_xpm_icon(atticon_xpm);
    Fl_RGB_Image attend_icon(&attend_xpm_icon, Fl_Color(0));
    icon(&attend_icon);
    xclass("Attendance");
    // display the window
    selectNewStudent();
    show(argc, argv);
}
