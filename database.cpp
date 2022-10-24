
//.CPP File
#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include "r1.cpp"
#include "r6.cpp"
#include "r7.cpp"
#include "r2.cpp"
#include "r3.cpp"
#include "r8.cpp"
#include "GradeItem.h"

/********************************************
 * Database file/main -> User input on name
 *
 * Author: Lavan Vivekanandasarma
 * Version: 04/13/2022
 *********************************************/

using namespace std;

bool continueFunctions()
{
    int n = 0;
    cout << "Press 1 to continue or 0 to exit."
         << endl;
    cin >> n;
    return n;
    if (n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Variables that store what was in the csv file
    vector<GradeItem> gradeInfo;
    string header;
    // Booleans that make sure that the file is in .csv file format, exists and has data in it.
    bool isCSV = false;
    bool isFilled = false;

    string c = "";
    int choice = 0;
    do
    {
        // The menu to pick options.
        cout << "Pick an option:" << endl;
        cout << "Enter 1 to Read Data." << endl;
        cout << "Enter 2 to Copy Data." << endl;
        cout << "Enter 3 to Display Data." << endl;
        cout << "Enter 4 to Add a Grade." << endl;
        cout << "Enter 5 to Search for an Item." << endl;
        cout << "Enter 6 to Exit." << endl;

        getline(cin >> ws, c);
        try{
            choice = stoi(c);
        }
        catch(...){
            choice = -1;
        }

        switch (choice)
        {
        case 1:
        {
            while (!isCSV || !isFilled)
            {
                string inputf = "";
                cout << "Enter Input csv File Name:" << endl;
                cin >> inputf;

                // checks if file is .csv
                if (inputf.length() < 5)
                {
                    cout << " " << endl;
                    cout << "Task Unsuccesful." << endl;
                    cout << "This is not a .csv file.\nPlease try again with a file name ending in .csv." << endl;
                    continue;
                }
                else if (!(inputf.substr(inputf.length() - 4) == ".csv"))
                {
                    cout << " " << endl;
                    cout << "Task Unsuccesful." << endl;
                    cout << "This is not a .csv file.\nPlease try again with a file name ending in .csv." << endl;
                    continue;
                }
                else
                {
                    isCSV = true;
                }

                // Reads the file
                r1 ReadCSV = r1(inputf);
                ReadCSV.read();
                string hlocal = ReadCSV.getHeader();

                // Checks if the file is empty by reading the first line.
                if (hlocal.length() == 0)
                {
                    cout << " " << endl;
                    cout << "Task Unsuccesful." << endl;
                    cout << "Your File either doesnt exist or is empty.\nPlease double check file name or add data to your file.\n"
                         << endl;
                }
                else
                {
                    // if its not empty, then updates the isFilledVar to exit while loop
                    isFilled = true;
                    // Updates the variables within the higher scope
                    header = hlocal;
                    gradeInfo = ReadCSV.getGradeInfo();
                    cout << "Task Completed." << endl;
                }
            }

            if (continueFunctions())
            {
                break;
            }
            else
            {
                return 0;
            }
        }
        case 2:
        {
            // Copies the output filename.
            if (header.length() == 0)
            {
                cout << " " << endl;
                cout << "Your CSV file doesnt exist or your data was empty.\nPlease double check file name or add data to your file.\n"
                     << endl;
            }
            else
            {
                string outputf = "";
                cout << "Enter Output CSV File Name:    " << endl;
                cin >> outputf;
                r6 WriteCSV = r6(outputf);
                WriteCSV.write(header, gradeInfo);
                cout << "Task Completed." << endl;
            }
            if (continueFunctions())
            {
                break;
            }
            else
            {
                return 0;
            }
        }
        case 3:
        {

            // Displays the data in the console
            if (header.length() == 0)
            {
                cout << " " << endl;
                cout << "Task Unsuccesful." << endl;
                cout << "Your CSV file doesnt exist or your data was empty.\nPlease double check file name or add data to your file.\n"
                     << endl;
            }
            else
            {
                r7 DisplayInfo = r7();
                DisplayInfo.displayGradeInfo(gradeInfo);
                r8 DisplaySummary = r8();
                DisplaySummary.displayGradeSummary(gradeInfo);
                cout << "Task Completed." << endl;
            }
            if (continueFunctions())
            {
                break;
            }
            else
            {
                return 0;
            }
        }
        case 4:
        {


            if (header.length() == 0)
            {
                cout << " " << endl;
                cout << "Task Unsuccesful." << endl;
                cout << "Your CSV file doesnt exist or your data was empty.\nPlease double check file name or add data to your file.\n"
                     << endl;
                cout << "Please enter a csv file before attempting to add information! Not technically neccesary, but otherwise there's no point!\n"
                     << endl;
                if (continueFunctions())
                {
                    break;
                }
                else
                {
                    return 0;
                }
                break;
            }

            r2 AddGrade = r2();
            gradeInfo = AddGrade.addGrade(gradeInfo);
            if (continueFunctions())
                {
                    break;
                }
                else
                {
                    return 0;
                }

        }
        case 5:
        {
            if (header.length() == 0)
            {
                cout << " " << endl;
                cout << "Task Unsuccesful." << endl;
                cout << "Your CSV file doesnt exist or your data was empty.\nPlease double check file name or add data to your file.\n"
                     << endl;
                cout << "Please enter a csv file before attempting to add information! Not technically neccesary, but otherwise there's no point!\n"
                     << endl;
                if (continueFunctions())
                {
                    break;
                }
                else
                {
                    return 0;
                }
                break;
            }


            vector<GradeItem> searched;
            int optionLocal;
            cout << "Press 1 to search by date."
                << endl;
            cout << "Press 0 to search by description."
                << endl;
            cin >> optionLocal;
            if (optionLocal == 1)
            {
                string query = "";
                r3 search = r3();
                cout << "Please Enter a Date." << endl;
                cin >> query;
                searched = search.searchGradeByDate(gradeInfo, query);
            }
            else
            {
                string query = "";
                r3 search = r3();
                cout << "Please Enter a Description." << endl;
                getline(cin >> ws, query);
                searched = search.searchGradeByDesc(gradeInfo, query);
                
            }

            if (searched.size() == 0){
                cout << "No Results Found." << endl;
            }else{
                 cout << "Results Found: " << endl;
                 r7 found = r7();
                 found.displayGradeInfo(searched);
            }
            if (continueFunctions())
                {
                    break;
                }
                else
                {
                    return 0;
                }

        }
        default:
            cout << "Something went wrong. Please try again." << endl;
            break;
        }
        
    } while (choice != 6);
    return 0;
}