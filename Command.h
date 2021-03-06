#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED


#include <ctime>
#include <iostream>
#include <dirent.h>
#include <stdlib.h>
#include <string>
#include <fstream>



#include "windows.h"
#include "Process Queues.h"



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

    void displayDate(bool dateChanged, int year, int month, int day)
    {
        if (dateChanged == false)
        {
            char date[10];
            _strdate(date);
            cout << "Current Date: " << date << endl;
            cout << endl;

        }
        else
        {
            cout << "Current Date: " << month << "/" <<
             day << "/" << year << endl;
            cout << endl;
        }
        return;
    }


    void setDate(int &year, int &month, int &day)
    {
        cout << "Enter new year (e.g. 2014): ";
        cin >> year;
        cout << endl;

        cout << "Enter new month (e.g. 5 for May, 12 for December): ";
        cin >> month;
        cout << endl;

        cout << "Enter new day (e.g. 5, 12, 28): ";
        cin >> day;
        cout << endl;
        return;
    }


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
        cout << "History: Displays command history of current session." << endl;
        cout << endl;
        cout << "Read Scheduler File: Reads in a file with information to schedule a process." << endl;
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

        while (direntPtr == readdir(directoryPtr))
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

    void CreatePCB();
    void readFile();

private:

    const float CURRENT_VERSION = 1.1;

};



void Command::CreatePCB()
{
    string processName;
    int processClass;
    int priority;
    PCB *pcb;

    cout << "What is the process name? ";
    cin >> processName;
    cout << endl;
    cout << "What is the process class? (0 for APP or 1 for SYSTEM)";
    cin >> processClass;
    cout << endl;
    cout << "What is the process priority? (-127 - 128)";
    cin >> priority;
    cout << endl;

    SetupPCB(processName,priority,processClass);
    InsertPCB(Ready,pcb);
}

void Command::readFile()
{
    string fileName;
    string processName;
    char processClass;
    int priority,memory,timeRemaining,timeArrived,perOfCpu;
    ifstream inputFile;
    cout << "Enter file name: ";
    cin >> fileName;
    inputFile.open(fileName.c_str());
    if (inputFile.fail())
    {
        cout << "FILE DOES NOT EXIST! (Check spelling and include file extension)" << endl;
    }
    else
    {
        inputFile >> processName;
        while (inputFile)
        {
            inputFile >> processClass;
            inputFile >> priority >> memory >> timeRemaining
                         >> timeArrived >> perOfCpu;
        }
    inputFile.close();
    }
    cout << endl << endl;
    cout << "Process Information" << endl;
    cout << "-----------------------" << endl;
    cout << "Process Name: " << processName << endl;
    cout << "Process Class: " << processClass << endl;
    cout << "Memory: " << memory << endl;
    cout << "Time Remaining: " << endl;
    cout << "Time Arrived: " << timeArrived << endl;
    cout << "Percentage of CPU: " << perOfCpu << endl;

    return;
}


#endif // COMMAND_H_INCLUDED
