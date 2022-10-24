/********************************************
 * r2.cpp -> Adds a grade item.
 *
 * Author: Lavan Vivekanandasarma
 * Version: 04/05/2022
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

class r2 {
    private:
    public:
        //Asks the user for information (date, description, type, maxGrade, grade)
        //then it creates a new gradeItem object with it, and pushes it onto the gradeInfo vector. 
        vector<GradeItem> addGrade(vector<GradeItem> gradeInfo){
            string date = "";
            string description = "";
            string type = "";
            string maxGrade = "";
            string grade = "";
            
            cout << "Enter a due date." << endl;
            getline(cin >> ws, date);
            cout << "Enter a description." << endl;
            getline(cin >> ws, description);
            cout << "Enter an assignment type." << endl;
            getline(cin >> ws, type);
            cout << "Enter the maximum possible grade for the assignment." << endl;
            getline(cin >> ws, maxGrade);
            cout << "Enter the grade received for the assignment." << endl;
            getline(cin >> ws, grade);

            GradeItem gradeLine = GradeItem(date, description, type, maxGrade, grade);
            gradeInfo.push_back(gradeLine);
            return gradeInfo;
            cout << "Grade Added.";

        }

};