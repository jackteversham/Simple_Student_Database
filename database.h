/**
*.h file:
*/
 #ifndef DATABASE_H
 #define DATABASE_H
//any includes here
#include <string> 
using namespace std;



namespace DATABASE {

struct StudentRecord{
    string name;
    string surname;
    string studentNumber;
    string classRecord;
};
int exists(std::string studentNumber);
void add_student(StudentRecord student);
StudentRecord find(std::string studentNumber);
void display_record(DATABASE::StudentRecord student);
void read_file(string filename);
double grade_student(string studentNum);
void write_to_file(string out);
void clear(void);


}
#endif