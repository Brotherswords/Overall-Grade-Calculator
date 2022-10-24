/********************************************
 * r6.cpp -> Save grades into a csv file
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

// Class contains the name of the output file as a private instance variable
class r6
{
private:
    string outputfile;

public:
    r6(string f)
    {
        outputfile = f;
    }
    // Write Method first opens and places the header in the first line.
    // Then Cycles through the vector of GradeItems, and gets the associated properties.
    // It finally places those properties into the output file.
    void write(string header, vector<GradeItem> gradeInfo)
    {
        ofstream outfile;
        outfile.open(outputfile);
        outfile << header;
        for (int i = 0; i < gradeInfo.size(); i++)
        {
            outfile << endl;
            string date, desc, t, mGrade, grade;
            date = gradeInfo[i].getDate();
            desc = gradeInfo[i].getDescription();
            t = gradeInfo[i].getType();
            mGrade = gradeInfo[i].getMaxGrade();
            grade = gradeInfo[i].getGrade();
            outfile << date << "," << desc << "," << t << "," << mGrade << "," << grade;
        }
        outfile.close();
    }
};