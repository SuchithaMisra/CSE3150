#include "student.h"

int main() {
    Student student1 = {1, "Christie", 34, 78};
    //pushing hw grades onto vector 
    student1.hw_grades.push_back(99);
    student1.hw_grades.push_back(65);
    student1.hw_grades.push_back(90);
    student1.hw_grades.push_back(86);
    student1.hw_grades.push_back(89);
    student1.hw_grades.push_back(76);

    student1.printInfo(); //printing info
    return 0;
}
