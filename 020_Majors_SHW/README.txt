PROGRAM NAME: Majors

What it is given:
majors1.in
majors1.cmd

majors1.in:
majors1.in is a text file that has a name then a "," then a major

Mark W. Redekopp , CECS
Mark W. Redekopp , EE
Alan Turing, CSCI
Alan Turing       , Cecs
Alan Turing,BISC
David Kempe, CSCI
Student Athlete, comm
Aaron Cote, CSCI HRTHS
John VN, Buad Csci BUAD FNDR
Steven B. Sample, BUAD EE
CS Minorville, BUAD
Ada Lovelace, CSGM
Joe Genius, PHCS
Clark Zuckerberg, CANST Cecs

majors1.cmd:
majors1.cmd is a list of the majors that are to be kept track of

CECS 
EE
ISE
Buad
EE BUAD
BUAD CSCI
BUAD CSCI CECS COMM BISC

What majors.cpp is supposed to do:
majors cpp is supposed to go through majors1.in and essentially keep track of all of the students that are a part of a major that needs to be tracked in majors1.cmd
The step by step of the program is to run through majors1.in first and make a map of student names to sets of majors.
Since there are name repeats, the program has to have a way to update names that already exist, while also creating new names that may also have multiple majors

after the initial map is created using majors1.in, majors1.cmd is the target majors. these are the majors that we want to keep track of
if you look at majors1.in, there are majors listed lke PHCD that are not to be tracked acording to majors1.cmd (PHCD is not present in majors1.cmd)
Essentially, create a new map that has these majors in them. compare the new target majors map with the one with all of the names and majors

The program should have a way to push to a output file all of the target majors with the names of the students that are part of each target major






setops.cpp
setops.h

this program is the union (|), difference (-) and intersection (&) operators that are to be used on the set of strings in the majors program
The further details of these operators is listed in comments in setops.cpp