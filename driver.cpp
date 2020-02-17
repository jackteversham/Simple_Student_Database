/**
*.cpp file:
*/
 #include "driver.h"
 #include <string>
 #include <iostream>
 #include <cstdlib>
 #include <vector>

 using namespace std;
 using namespace STUDENT_NO;

void STUDENT_NO::add_student(string name){
    
cout << "student added!" << name;
 
}

void STUDENT_NO::clear(void) { system("clear"); } 

struct StudentRecord
{   /* data */
    string name;
    string surname;
    string studentNumber;
    string classRecord;
};

int main (void){
    //STUDENT_NO::add_student("Jack Teversham");
   
    std:vector<STUDENT_NO::StudentRecord> db;


    // PRINT OPTIONS FOR USER -------------
    string prompt = "\n0: Add student\n1: Read database\n2: Display student data\n3: Grade student\nc: to clear the console\nq: Quit program\nEnter a number (or q to quit) and press return...\n";


    for (;;) { // loop forever
    // process key press and call relevant functions 
    cout << prompt; //print the prompt menu defined above

    string option;
    getline(std::cin, option, '\n');

    cout << "\nThe selected option is: "<<option<<"\n";
  
    if(option == "c")clear();
     
     if (option == "q") {
         cout <<"quitting...\n";
         clear();
         break;}
    }
    
    return 0;
}




