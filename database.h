/**
*.h file:
*/
 #ifndef DATABASE_H
 #define DATABASE_H
//any includes here
#include <string> 
using namespace std;

namespace STUDENT_NO {

void add_student(std::string name ...);
void delete_student(std::string name);

 }
#endif