/**
*.cpp file:
*/
 #include "driver.h"
 #include "database.cpp"
 #include <string>
 #include <iostream>
 #include <cstdlib>
 #include <vector>

 using namespace std;
 using namespace STUDENT_NO;
 using namespace DATABASE;


void STUDENT_NO::clear(void) { system("clear"); } 

int main (void){

    //errorStudent is a fake student always added to the database vector first (element 0) for error trapping purposes
    StudentRecord errorStudent; 
    errorStudent.name = "null";
    errorStudent.surname = "null";
    errorStudent.studentNumber = "null";
    errorStudent.classRecord = "null";

    DATABASE::add_student(errorStudent);

    // PRINT OPTIONS FOR USER -------------
    string prompt = "\n0: Add student\n1: Read in from file\n2: Display student data\n3: Grade student\n4: Write database to file\nc: to clear the console\nq: Quit program\nEnter a number (or q to quit) and press return...\n";


    for (;;) { // loop forever
    // process key press and call relevant functions 
    cout << prompt; //print the prompt menu defined above

    string option;
    getline(std::cin, option, '\n');

    if(option == "4"){

        string filename;
        cout<<"\nEnter file name to append to:\n";
        getline(std::cin, filename, '\n');
        DATABASE::write_to_file(filename);
        cout << "\nDATABASE WRITTEN TO FILE "<< filename <<endl;
    }

  
    if(option == "c")STUDENT_NO::clear();

    if(option == "3"){
         cout << "\nEnter student number:\n";
         string studentNum;
         getline(std::cin, studentNum , '\n');
         double grade = DATABASE::grade_student(studentNum);
         cout << "Student grade:\n"<< grade << endl;
    } 

    if(option == "0"){
        
        StudentRecord student;
        string in;
        cout << "\nEnter student name:\n";
        getline(std::cin,student.name , '\n');
        cout << "\nEnter student surname:\n";
        getline(std::cin,student.surname , '\n');
        cout << "\nEnter student number:\n";
        getline(std::cin,student.studentNumber , '\n');
        cout << "\nEnter student class record:\n";
        getline(std::cin,student.classRecord , '\n');
        DATABASE::display_record(student);
        DATABASE::add_student(student);

    }
     
     if (option == "q") {
         cout <<"quitting...\n";
         STUDENT_NO::clear();
         break;}


    if (option == "2") {
     cout <<"\nEnter a student number:\n";
     string snum;
     getline(std::cin, snum, '\n');
     StudentRecord student = DATABASE::find(snum);

    if(student.name=="null"){ //error student received, i.e. student doesnt exist
         cout << "\nSTUDENT NOT FOUND\n";
         }else{
             DATABASE::display_record(student); //if valid student record returned, then display student record
         }
         
         }

         if (option == "1"){
             DATABASE::read_file("studentData.txt");
         }
    }
         return 0;
    }
    
    





