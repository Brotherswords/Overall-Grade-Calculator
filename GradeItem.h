#ifndef _GradeItem_h_
#define _GradeItem_h_

/********************************************
 * GradeItem Class containing associated properties & methods
 *
 * Author: Lavan Vivekanandasarma
 * Version: 03/05/2022
 *********************************************/

using namespace std;

class GradeItem
{
private:
    string date, description, type, maxGrade, grade;

public:
    GradeItem(string d, string desc, string t, string mGrade, string cgrade)
    {
        date = d;
        description = desc;
        maxGrade = mGrade;
        grade = cgrade;
        type = t;
    }
    void setDate(string d)
    {
        date = d;
    }
    void setDescription(string desc)
    {
        description = desc;
    }
    void setType(string t)
    {
        type = t;
    }
    void setMaxGrade(string mGrade)
    {
        maxGrade = mGrade;
    }
    void setGrade(string cgrade)
    {
        grade = cgrade;
    }
    string getDate()
    {
        return date;
    }
    string getDescription()
    {
        return description;
    }
    string getType()
    {
        return type;
    }
    string getMaxGrade()
    {
        return maxGrade;
    }
    string getGrade()
    {
        return grade;
    }
};

#endif
