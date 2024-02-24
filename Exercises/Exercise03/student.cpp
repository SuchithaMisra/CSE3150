#include "student.h"
#include <iostream>

double Student::class_total_score() const {
    double total = 0.3 * midterm + 0.3 * final_exam; //calculates the total based on 30% midterm and 30% final
    double sum_hw_grades = 0.0;

    //forloop calculates the sum of all hw grades
    for (int grade : hw_grades) {
        sum_hw_grades += grade;
    }
    // Adds 40% of hw grade to total calulated above
    total += 0.4 * (sum_hw_grades / hw_grades.size());
    return total;
}

void Student::printInfo() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Total Class Score: " << class_total_score() << std::endl;
}
