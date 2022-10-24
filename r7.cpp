/********************************************
 * r7.cpp -> Display csv file info
 *
 * Author: Lavan Vivekanandasarma
 * Version: 03/05/2022
 *********************************************/

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include "GradeItem.h"
using namespace std;

class r7
{
public:
    // DisplayGradeInfo just takes the vector of GradeItems from r1.read().
    // Then it gets all of its properties and uses printf to print it to the console in a tabular fashion.
    void displayGradeInfo(vector<GradeItem> gradeInfo)
    {
        printf("%-*s", 12, "Date");
        printf("%-*s", 20, "Description");
        printf("%-*s", 12, "Type");
        printf("%-*s", 11, "MaxGrade");
        printf("%-*s \n", 3, "Grade");
        for (GradeItem i : gradeInfo)
        {
            string date = i.getDate();
            string description = i.getDescription();
            string type = i.getType();
            string maxGrade = i.getMaxGrade();
            string grade = i.getGrade();

            printf("%-*s", 12, date.c_str());
            printf("%-*s", 20, description.c_str());
            printf("%-*s", 12, type.c_str());
            printf("%-*s", 11, maxGrade.c_str());
            printf("%-*s \n", 3, grade.c_str());
        }
    }
};