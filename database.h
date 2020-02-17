/**
*.h file:
*/
 #ifndef DATABASE_H
 #define DATABASE_H
//any includes here
#include <string> 
using namespace std;

namespace DATABASE {

void add_student(std::string name);
void delete_student(std::string name);
void clear(void);
struct StudentRecord{};

 }
#endif