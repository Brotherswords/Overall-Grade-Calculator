/********************************************
 * r1.cpp -> Reads CSV formatted files
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

// Class contains private instance variables of filename, all grade data and the header.
// Class also contains getter/setter methods
class r1
{
private:
    string filename;
    vector<GradeItem> gradeInfo;
    string header;

public:
    r1(string f)
    {
        filename = f;
    }
    string getFilename()
    {
        return filename;
    }
    // void method reads by getting the first line (the header).
    // Then while there is data in the file, it turns it into a GradeItem object.
    // Then stores it in the vector.
    void read()
    {
        ifstream infile(filename);

        getline(infile, header);

        while (infile.good())
        {
            string date;
            string description;
            string type;
            string MaxGrade;
            string Grade;

            getline(infile, date, ',');
            getline(infile, description, ',');
            getline(infile, type, ',');
            getline(infile, MaxGrade, ',');
            getline(infile, Grade);

            GradeItem gradeLine = GradeItem(date, description, type, MaxGrade, Grade);
            gradeInfo.push_back(gradeLine);
        }
        infile.close();
    }
    vector<GradeItem> getGradeInfo()
    {
        return gradeInfo;
    }
    string getHeader()
    {
        return header;
    }
};
