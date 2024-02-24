#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

TEST_CASE("Edge Cases") {
    
    SUBCASE("All 0's"){
        Student student1 = {1, "Bob", 0, 0, {0, 0, 0}};
        double expected_score1 = 0.0;
        CHECK(student1.class_total_score() == expected_score1);
    }

    SUBCASE("Full Score"){
        Student student2 = {2, "Tray", 100, 100, {100, 100, 100}};
        double expected_score2 = 100.0;
        CHECK(student2.class_total_score() == expected_score2);
    }

    SUBCASE("No Exam Scores"){
        Student student3 = {3, "Alice", 0, 0, {60, 75, 90}};
        double expected_score3 = 0.3 * 0 + 0.3 * 0 + (((60 + 75 + 90) / 3.0) * 0.4);
        CHECK(student3.class_total_score() == expected_score3);
    }

    SUBCASE("No HW Scores"){
        Student student3 = {3, "Mike", 78, 91, {0, 0, 0}};
        double expected_score3 = 0.3 * 78 + 0.3 * 91 + (((0 + 0 + 0) / 3.0) * 0.4);
        CHECK(student3.class_total_score() == expected_score3);
    }
}

TEST_CASE("Regular --> Multiple HW grades"){
    SUBCASE("Test1"){
        Student student4 = {4, "John", 88, 77, {90, 99, 90}};
        double expected_score4 = 0.3 * 88 + 0.3 * 77 + (((90 + 99 + 90) / 3.0) * 0.4);
        CHECK(student4.class_total_score() == expected_score4);
    }

    SUBCASE("Test2"){
        Student student5 = {5, "Suchitha", 77, 70, {83, 87, 34, 90}};
        double expected_score5 = 0.3 * 77 + 0.3 * 70 + (((83 + 87 + 34 + 90) / 4.0) * 0.4);
        CHECK(student5.class_total_score() == expected_score5);
    }

    SUBCASE("Test3"){
        Student student6 = {6, "Joe", 99, 85, {81, 82, 83, 84, 85}};
        double expected_score6 = 0.3 * 99 + 0.3 * 85 + (((81 + 82 + 83 + 84 + 85) / 5.0) * 0.4);
        CHECK(student6.class_total_score() == expected_score6);
    }

    SUBCASE("Test4"){
        Student student7 = {4, "David", 45, 74, {60, 75}};
        double expected_score7 = 0.3 * 45 + 0.3 * 74 + (((60 + 75) / 2.0) * 0.4);
        CHECK(student7.class_total_score() == expected_score7);
    }



}