#
# FLTK-usable makefile
#

CC = gcc
C++ = g++

CXXFLAGS = -Wall -g -std=c++11
LDLIBS = -lfltk -lstdc++

attend: attendance.o AttendanceApp.o Buttons.o Roster.o Student.o
	$(C++) -o $@ $^ $(LDLIBS)

clean:
	rm *.o
	rm attend
