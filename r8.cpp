/********************************************
 * r8.cpp -> Display csv file info
 *
 * Author: Lavan Vivekanandasarma
 * Version: 04/30/2022
 *********************************************/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include "GradeItem.h"
using namespace std;


//Cateogry class made to store major components of each category
// It stores a cateogry's name, total points and total potential points
class Category
{
private:
    string type;
    int maxGradeTotal = 0;
    int gradeTotal = 0;
public:
    Category(string t){ 
        type = t;
    }
    void setMaxGradeTotal(int n){
        maxGradeTotal = n;
    }
    void setGradeTotal(int n){
        gradeTotal = n;
    }
    int getMaxGradeTotal(){
       return maxGradeTotal;
    }
    int getGradeTotal(){
       return gradeTotal;
    }
    string getType(){
        return type;
    }
};



//r8 has a member function displayGradeSummary that does all the heavy lifting
class r8
{
public:
    // DisplayGradeSummary just takes the vector of GradeItems from r1.read().
    // The function then goes through and compares every category of every item, 
    // and if it is in a certain category it will add tha tinformation to the corresponding
    // category object.
    void displayGradeSummary(vector<GradeItem> gradeInfo)
    {
        //Four major cateogries and the "everything" category that contains an aggregate
        Category quiz = Category("Quiz");
        Category hw = Category("HW");
        Category exam =  Category("Exam");
        Category classWork = Category("Class Work");
        Category everything = Category("Everything");
        
        //Checks every object and compares category to add information to a given category object
        for (GradeItem i : gradeInfo)
        {
            if(i.getType() == "Quiz"){
                int maxGradeLocal = stoi(i.getMaxGrade().c_str());
                int gradeTotalLocal = stoi(i.getGrade().c_str());
                maxGradeLocal = maxGradeLocal + quiz.getMaxGradeTotal();
                gradeTotalLocal = gradeTotalLocal + quiz.getGradeTotal();
                quiz.setMaxGradeTotal(maxGradeLocal);
                quiz.setGradeTotal(gradeTotalLocal);
            }
            if(i.getType() == "HW"){
                int maxGradeLocal = stoi(i.getMaxGrade().c_str());
                int gradeTotalLocal = stoi(i.getGrade().c_str());
                maxGradeLocal = maxGradeLocal + hw.getMaxGradeTotal();
                gradeTotalLocal = gradeTotalLocal + hw.getGradeTotal();
                hw.setMaxGradeTotal(maxGradeLocal);
                hw.setGradeTotal(gradeTotalLocal);
            }
            if(i.getType() == "Exam"){
                int maxGradeLocal = stoi(i.getMaxGrade().c_str());
                int gradeTotalLocal = stoi(i.getGrade().c_str());
                maxGradeLocal = maxGradeLocal + exam.getMaxGradeTotal();
                gradeTotalLocal = gradeTotalLocal + exam.getGradeTotal();
                exam.setMaxGradeTotal(maxGradeLocal);
                exam.setGradeTotal(gradeTotalLocal);
            }
            if(i.getType() == "Class Work"){
                int maxGradeLocal = stoi(i.getMaxGrade().c_str());
                int gradeTotalLocal = stoi(i.getGrade().c_str());
                maxGradeLocal = maxGradeLocal + classWork.getMaxGradeTotal();
                gradeTotalLocal = gradeTotalLocal + classWork.getGradeTotal();
                classWork.setMaxGradeTotal(maxGradeLocal);
                classWork.setGradeTotal(gradeTotalLocal);
            }
        }
        //tabulates the sum based off of the totals of every other category
        int NetTotal = quiz.getGradeTotal() + hw.getGradeTotal() + exam.getGradeTotal() + classWork.getGradeTotal();
        int NetTotalMax = quiz.getMaxGradeTotal() + hw.getMaxGradeTotal() + classWork.getMaxGradeTotal() + exam.getMaxGradeTotal();
        everything.setGradeTotal(NetTotal);
        everything.setMaxGradeTotal(NetTotalMax);

        //Calculates the grade percent as a float
        float gradePercent = ((float)everything.getGradeTotal()/(float)everything.getMaxGradeTotal())*100;
        string GradeLetter = " ";
        //determines the grade letter 
        if (gradePercent >= 90){
            GradeLetter  = "A";
        }else if (gradePercent < 90 && gradePercent >= 80){
            GradeLetter  = "B";
        }else if (gradePercent < 80 && gradePercent >= 70){
            GradeLetter  = "C";
        }else if (gradePercent < 70 && gradePercent >= 60){
            GradeLetter  = "D";
        }else{
            GradeLetter  = "F";
        }

        //Print Items in a tabular fashion using printf
        cout << "-----------------------------------------------------------" << endl;
        cout << "Summary" << endl;
        cout << "-----------------------------------------------------------" << endl;
        printf("%-*s", 44, "Quiz");
        printf("%-*s", 11, to_string(quiz.getMaxGradeTotal()).c_str());
        printf("%-*s \n", 4, to_string(quiz.getGradeTotal()).c_str());

        printf("%-*s", 44, "HW");
        printf("%-*s", 11, to_string(hw.getMaxGradeTotal()).c_str());
        printf("%-*s \n", 4, to_string(hw.getGradeTotal()).c_str());

        printf("%-*s", 44, "Class Work");
        printf("%-*s", 11, to_string(classWork.getMaxGradeTotal()).c_str());
        printf("%-*s \n", 4, to_string(classWork.getGradeTotal()).c_str());
        
        printf("%-*s", 44, "Exam");
        printf("%-*s", 11, to_string(exam.getMaxGradeTotal()).c_str());
        printf("%-*s \n", 4, to_string(exam.getGradeTotal()).c_str());
        cout << "-----------------------------------------------------------" << endl;
        printf("%-*s", 44, "Grand Total");
        printf("%-*s", 11, to_string(everything.getMaxGradeTotal()).c_str());
        printf("%-*s \n", 4, to_string(everything.getGradeTotal()).c_str());

        printf("%-*s", 55, "Grade Percentage");
        printf("%-*s \n", 4, (to_string(gradePercent).c_str()));

        printf("%-*s", 55, "Grade Letter");
        printf("%-*s \n", 1, (GradeLetter.c_str()));
        cout << "-----------------------------------------------------------" << endl;

    }
};  