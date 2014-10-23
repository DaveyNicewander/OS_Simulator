#include "Command.h"
#include <string>
#include <vector>

void displayWelcome();                  //DISPLAYS OPENING WELCOME MESSAGE
void wait(int sec);                     //PAUSES FOR 'SEC' NUMBER OF SECONDS
void clearScreen(int delay);            //DELAYS FOR 'DELAY' NUMBER OF SECONDS, THEN CLEARS SCREEN
void runSession(bool session);          //STARTS AND RUNS SESSION UNTIL COMPLETION
bool displayMainMenu(bool session);     //DISPLAYS MAIN MENU OPTIONS
void displayHistory();                      //EXTRA CREDIT, DISPLAYS HISTORY OF COMMANDS



bool dateChanged = false;
int year = 0;
int month = 0;
int day = 0;
vector<string> history;

using namespace std;
int main()
{
    bool session = true;



    displayWelcome();
    clearScreen(3);

    runSession(session);


    return 0;
}








//___________________FUNCTION DEFINITIONS_____________________



void displayWelcome()
{
    cout << "Fractal OS" << endl;
    cout << "Welcome!" << endl;
    return;
}

void wait(int sec)
{
    clock_t endwait;
    endwait = clock() + sec * CLK_TCK;
    while (clock() < endwait)
        {
        }
    return;
}

void clearScreen(int delay)
{
    wait(delay);
    cout << string(MAX_SCREEN_HEIGHT, '\n');
    return;
}

void runSession(bool session)
{
    session = true;

    while (session)
    {
        session = displayMainMenu(session);
    }
}

bool displayMainMenu(bool session)
{
    string userChoice;
    Command control;

    cout << "Choose a valid menu option and then press enter" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "[V] - Version" << endl;
    cout << "[D] - Date" << endl;
    cout << "[F] - Files" << endl;
    cout << "[H] - Help" << endl;
    cout << "[K] - History" << endl;
    cout << "[E] - Exit" << endl;
    cin >> userChoice;

    if (userChoice == "V" || userChoice == "v")
    {
        history.push_back(userChoice);
        clearScreen(0);
        control.displayVersion();
        cout << "Press enter to return to menu...";
        cin.sync();
        cin.get();
        clearScreen(0);
    }

    if (userChoice == "D" || userChoice == "d")
    {
        history.push_back(userChoice);
        clearScreen(0);
        control.displayDate(dateChanged, year, month, day);
        cout << "------------------------" << endl;
        cout << "[S] - Set Date" << endl;
        cout << "[M] - Return To Menu" << endl;
        cin >> userChoice;

        if (userChoice == "S" || userChoice == "s")
        {
            history.push_back(userChoice);
            dateChanged = true;
            clearScreen(0);
            control.setDate(year, month, day);
            clearScreen(0);
            control.displayDate(dateChanged, year, month, day);
            cout << "------------------------" << endl;
            cout << "[S] - Set Date" << endl;
            cout << "[M] - Return To Menu" << endl;
            cin >> userChoice;
        }
        else
        {
            cout << "Press enter to return to menu...";
            cin.sync();
            cin.get();
            clearScreen(0);
        }
    }

    if (userChoice == "F" || userChoice == "f")
    {
        history.push_back(userChoice);
        clearScreen(0);
        control.displayDirectory();
        cout << "Press enter to return to menu...";
        cin.sync();
        cin.get();
        clearScreen(0);
    }

    if (userChoice == "H" || userChoice == "h")
    {
        history.push_back(userChoice);
        clearScreen(0);
        control.displayHelp();
        cout << "Press enter to return to menu...";
        cin.sync();
        cin.get();
        clearScreen(0);
    }

    if (userChoice == "E" || userChoice == "e")
    {
        clearScreen(0);
        cout << "Are you sure you want to exit? (Y/N)" << endl;
        cin >> userChoice;
        history.push_back(userChoice);
        if (userChoice == "Y" || userChoice == "y")
            session = false;
            history.push_back(userChoice);
        clearScreen(0);
    }

    if (userChoice == "K" || userChoice == "k")
    {
        history.push_back(userChoice);
        clearScreen(0);
        displayHistory();
        cout << "Press enter to return to menu...";
        cin.sync();
        cin.get();
        clearScreen(0);
    }

    else
    {
        clearScreen(0);
        displayMainMenu(session);
    }

    return session;
}

void displayHistory()
{
    cout << "Session Command History" << endl;
    cout << "-------------------------------"<< endl;

    for(int i = 0; i<history.size(); i++)
    {
        cout << history[i] << ", ";
    }
}


