/********************************************
 * r3.cpp -> Searches for Items by date and description 
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

class r3 {
    private:
    public:
        //Given a vector gradeInfo, containing all gradeItems, it searches every item in the 
        //list and appends any items that match the description to the vector, items. 
        vector<GradeItem> searchGradeByDesc(vector<GradeItem> gradeInfo, string desc){
            vector<GradeItem> items; 
            for (int i = 0; i < gradeInfo.size(); i++)
            {
                if (gradeInfo[i].getDescription() == desc){
                    items.push_back(gradeInfo[i]);
                }
                
            }
            return items;
        }
        //Given a vector gradeInfo, containing all gradeItems, it searches every item in the 
        //list and appends any items that match the date to the vector, items. 
        vector<GradeItem> searchGradeByDate(vector<GradeItem> gradeInfo, string date){
            vector<GradeItem> items; 
            for (int i = 0; i < gradeInfo.size(); i++)
            {
                if (gradeInfo[i].getDate() == date){
                    items.push_back(gradeInfo[i]);
                }
                
            }
            return items;
        }
};