/**
*.cpp file:
*/
 #include "database.h"
 #include <string>
 #include <iostream>
 #include <cstdlib>
 #include <vector>
 #include <fstream>
 #include <sstream>

 using namespace std;
 using namespace DATABASE;

 std::vector<DATABASE::StudentRecord> db; //Our database structure

//  struct StudentRecord{
//     string name;
//     string surname;
//     string studentNumber;
//     string classRecord;
// };

void DATABASE::clear(void) { system("clear"); } 

int DATABASE::exists(std::string studentNumber){
    for (int i=0; i< db.size(); i++){
        if(db[i].studentNumber==studentNumber){
            return 1;
        }
    }
    return 0;
}    
void DATABASE::add_student(DATABASE::StudentRecord student){
    
if(exists(student.studentNumber)){ //check if student already exists
    int index;
     for (int i=0; i< db.size(); i++){
          
        if(db[i].studentNumber==student.studentNumber){
            index = i; //return location of student
            break;
        }
    }
    db.erase(db.begin()+index); //erase existing student record
    db.push_back(student); //replace with same record with potential new data

    cout << "\nSTUDENT ALREADY EXISTS. IT WILL BE REPLACED WITH NEW STUDENT RECORD\n";
}
else{
db.push_back(student); //if student doesnt exist - add it to database as expected
cout << "\nstudent " << student.studentNumber << " added to database!\n";
}


 
}

StudentRecord DATABASE::find(std::string studentNumber){ //returns a studentRecord object
    if(exists(studentNumber)){
        for (int i=0; i< db.size(); i++){
          
        if(db[i].studentNumber==studentNumber){
            return db[i];
        }
    }
    }else{
        return db[0]; //the null student record created for this purpose.
    }
    return db[0];
}

void DATABASE::read_file(string filename){
     string line;
     ifstream ifs;
     std::vector<string> buffer;
     ifs.open(filename.c_str()); // argument is ‘‘char*’’ NOT String
     if(!ifs){
         cerr << "file open failed!";
     }else{
         while(!ifs.eof()){
         getline(ifs, line, '\n');

         std::istringstream ss(line);
         string token;

         while(getline(ss, token, ' ')){
             buffer.push_back(token); //add tokens to a vector
         }
     }
     for(int i= 0; i< buffer.size(); i+=6){
         StudentRecord student;
         student.name = buffer[i];
         student.surname = buffer[i+1];
         student.studentNumber = buffer[i+2];
         student.classRecord = buffer[i+3]+' '+buffer[i+4]+' '+buffer[i+4];
         
         add_student(student);
     }
     ifs.close();
     }
     
}
double DATABASE::grade_student(string studentNum){
    
        StudentRecord student = find(studentNum);
        if (student.name == "null"){
            cout << "\nSTUDENT NOT FOUND\n";
            return 0;
        }else {
            string grade = student.classRecord;
            string token;
            istringstream ss(grade);
            double sum;
            while(getline(ss, token, ' ')){
                double x = stoi(token);
                sum = sum +x;
            }
            return sum/3;
        }
} 
void DATABASE::write_to_file(string out){
    std::ofstream outfile;
    outfile.open(out, std::ios_base::app); // append instead of overwrite
    for (int i = 1; i < db.size(); i++)
    {
        string to_write = db[i].name+' '+db[i].surname+' '+db[i].studentNumber+' '+db[i].classRecord+'\n';
        outfile << to_write;
    }
}

void DATABASE::display_record(DATABASE::StudentRecord student){

    cout<<"\n-----STUDENT RECORD-----\n";
    cout << student.name <<"\n";
    cout << student.surname <<"\n";
    cout << student.studentNumber <<"\n";
    cout << student.classRecord <<"\n\n";

}    











