#include "Command.h"



void displayWelcome();                  //DISPLAYS OPENING WELCOME MESSAGE
void wait(int sec);                     //PAUSES FOR 'SEC' NUMBER OF SECONDS
void clearScreen(int delay);            //DELAYS FOR 'DELAY' NUMBER OF SECONDS, THEN CLEARS SCREEN
void runSession(bool session);          //STARTS AND RUNS SESSION UNTIL COMPLETION
bool displayMainMenu(bool session);     //DISPLAYS MAIN MENU OPTIONS




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
    bool success = true;
    Command control;

    cout << "Choose a valid menu option and then press enter" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "[V] - Version" << endl;
    cout << "[D] - Date" << endl;
    cout << "[F] - Files" << endl;
    cout << "[H] - Help" << endl;
    cout << "[E] - Exit" << endl;
    cin >> userChoice;

    if (userChoice == "V" || userChoice == "v")
    {
        clearScreen(0);
        control.displayVersion();
        cout << "Press enter to return to menu...";
        cin.sync();
        cin.get();
        clearScreen(0);
    }

    if (userChoice == "D" || userChoice == "d")
    {
        clearScreen(0);
        control.displayDate();
        cout << "Press enter to return to menu...";
        cin.sync();
        cin.get();
        clearScreen(0);
    }

    if (userChoice == "F" || userChoice == "f")
    {
        clearScreen(0);
        control.displayDirectory();
        cout << "Press enter to return to menu...";
        cin.sync();
        cin.get();
        clearScreen(0);
    }

    if (userChoice == "H" || userChoice == "h")
    {
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
        if (userChoice == "Y" || userChoice == "y")
            session = false;
        clearScreen(0);
    }

    else
    {
        clearScreen(0);
        displayMainMenu(session);
    }

    return session;
}
