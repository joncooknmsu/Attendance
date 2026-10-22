# The CallOn App

CallOn is a C++ FLTK app to select students to call on during class. It reads a class roster as a CSV file -- see `testroster.csv` for the format -- and also writes this same file out as students are called on, so that the stats are updated.

### Usage

1. Run as `./callon rosterfilename.csv`
2. Use _Next Callee_ button to select a new student; if you want to skip this student for any reason, just hit _Next Callee_ again. The _Not Here_ button will record their absence, if you want to use it.
3. Interact with the student in whatever way you choose (typically, asking them questions).
4. Choose one of the _Effort_ buttons to record what their level of effort or performance was. So far I have not used this feature, I just hit _Good Effort_ each time, but in, perhaps, upper division or graduate courses I may use it. The point values are 1, 2, and 3 for weak, so-so, and good effort, respectively.
5. After an _Effort_ button is pressed, the student stats are updated, the data file is written out (overwritten), and "Processed" appears in the name field. Now you can repeat to step 2.

### Building

You need FLTK 1.3 (current as of this writing: 1.3.8) to compile this program. If you install it in a non-standard place, edit the Makefile and add include and library paths to your location. Other than that, `make` should work.

