#include "AttendanceApp.h"
#include <iostream>

int AttendButton::handle(int event)
{
    if (event != FL_PUSH) {
        // return Fl_Widget::handle(event);
        return Fl_Button::handle(event);
        // or should we just return 0?
    }
    //std::cout << "Marking student: " << app->callee();
    //std::cout << " with a " << rating << '\n';
    app->markStudent(attend);
    app->selectNewStudent();
    return 1; // 1 indicates we handled it
}

