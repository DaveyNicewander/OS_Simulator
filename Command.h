#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED


#include <ctime>
#include <iostream>
#include <dirent.h>
#include <stdlib.h>


#include "windows.h"


using namespace std;


const int MAX_SCREEN_HEIGHT = 50;


class Command
{
public:

    Command()
    {
    }

    void displayVersion()
    {
        cout << "Fractal Version: " << CURRENT_VERSION
             << " is running!" << endl;
        cout << endl;
    }

    void displayDate()
    {
        char date[10];
        _strdate(date);

        cout << "Current Date: " << date << endl;
        cout << endl;
    }

    /*
    void setDate()
    {
        int year,month,day;
        cout << "Enter new year: ";
        cin >> year;
        cout << endl;

        cout << "Enter new month (e.g. 5 = May, 12 = December): ";
        cin >> month;
        cout << endl;

        cout << "Enter new day (e.g. 5,12,28): ";
        cin >> day;
        cout << endl;

        SYSTEMTIME reset;
        reset.wYear = year;
        reset.wMonth = month;
        reset.wDay = day;

        ::SetSystemTime(&reset);
    }
    */

    void displayHelp()
    {
        cout << "Available Commands and Command Descriptions" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Version: Displays the current version of Fractal OS." << endl;
        cout << endl;
        cout << "Exit: Exits Fractal OS." << endl;
        cout << endl;
        cout << "Date: Displays current date." << endl;
        cout << endl;
        cout << "Files: Displays a list of files in Fractal's current directory." << endl;
        cout << endl;
        cout << "Help: Provides help menu." << endl;
        cout << endl;
    }

    void displayDirectory()
    {
        DIR *directoryPtr = NULL;

        struct dirent *direntPtr = NULL;

        directoryPtr = opendir(".");
        if (directoryPtr == NULL)
        {
            cout << "Error! Fractal encountered a problem opening the directory!"
                 << endl;
            return;
        }

        cout << "Files Located" << endl;
        cout << "-------------" << endl;

        while (direntPtr = readdir(directoryPtr))
        {
            if (direntPtr == NULL)
            {
                cout << "Error! Fractal encountered a problem opening the directory!"
                     << endl;
                return;
            }

            cout << direntPtr->d_name << endl;
        }

        closedir(directoryPtr);

        cout << endl;
        return;
    }

private:

    const float CURRENT_VERSION = 1.0;

};





#endif // COMMAND_H_INCLUDED
