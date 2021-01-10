#Simple Student Database

Files:
database.h ---> header file defining all methods and structures contained in database.cpp
database.cpp ---> contains the implementations of all database functionality and methods defined in the database.h file
driver.cpp ---> Implements the application: Contains the main method and executes the text based menu interface and makes
                calls to the database methods located in database.cpp
Makefile ---> called using 'make' to compile and link .h and .cpp files into a single executable called driver       

Worth noting:
In my application implementation, I always add a null StudentRecord object as the 1st element
of the database vector --> this acts as a return when error trapping.

Text files:
"studentData.txt" --> contains data to be read in for database population
"out.txt" --> a textfile to output the database to - will append each addition

Running:
I'm sure you know the drill...

ensure   make clean     (no doubt it has been done already)
         make
         make run


Thanks for your time :)         
