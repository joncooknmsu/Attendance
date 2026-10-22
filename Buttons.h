#ifndef BUTTONS_H
#define BUTTONS_H
#include "AttendanceApp.h"
#include <FL/Fl_Button.H>

class AttendanceApp;

class AttendButton : public Fl_Button
{
 public:
    AttendButton(AttendanceApp* app, bool attend, int x, int y, int w, int h,
                 const char* label)
          : Fl_Button{x, y, w, h, label}, attend{attend}, app{app}
    {    }
    virtual int handle(int event);
    bool markStudent();

 private:
    bool attend;
    AttendanceApp* app;
};

#endif // BUTTONS_H
