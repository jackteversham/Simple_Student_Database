/**
*.cpp file:
*/
 #include "database.h"
 #include <string>
 #include <iostream>
 #include <cstdlib>
 #include <vector>
 #include <fstream>

 using namespace std;
 using namespace DATABASE;

 std::vector<DATABASE::StudentRecord> db; //Our database structure

//  struct StudentRecord{
//     string name;
//     string surname;
//     string studentNumber;
//     string classRecord;
// };

int DATABASE::exists(std::string studentNumber){

    for (int i=0; i< db.size(); i++){
        if(db[i].studentNumber==studentNumber){
            return 1;
        }
    }
    return 0;

}    
void DATABASE::add_student(DATABASE::StudentRecord student){
    

if(exists(student.studentNumber)){
    cout << "\nSTUDENT ALREADY EXISTS.\n";
}
else{
db.push_back(student);
cout << "\nstudent " << student.studentNumber << " added to database!\n";
}


 
}

StudentRecord DATABASE::find(std::string studentNumber){
    if(exists(studentNumber)){
        for (int i=0; i< db.size(); i++){
          
        if(db[i].studentNumber==studentNumber){
            return db[i];
        }
    }

    }else{
        return db[0];
    }
}
void DATABASE::read_file(string filename){
     string line;
     ifstream ifs;
     ifs.open(filename.c_str()); // argument is ‘‘char*’’ NOT String
     if(!ifs){
         cerr << "file open failed!";
     }else{
         while(!ifs.eof()){
         getline(ifs, line, '\n');
     cout << line << endl;
     }
     
     ifs.close();

     }
     
}


void DATABASE::display_record(DATABASE::StudentRecord student){

    cout<<"\n-----STUDENT RECORD-----\n";
    cout << student.name <<"\n";
    cout << student.surname <<"\n";
    cout << student.studentNumber <<"\n";
    cout << student.classRecord <<"\n";

}    











