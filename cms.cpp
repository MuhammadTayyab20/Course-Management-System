#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct student
{
    string fname;
    string lname;
    string Registration;
    string classes;
} studentData;

struct teacher
{
    string fst_name;
    string lst_name;
    string qualification;
    string exp;
    string pay;
    string subj;
    string lec;
    string addrs;
    string cel_no;
    string blod_grp;
    string serves;
} tech[50];

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForKey() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

int login();

int main()
{
    login();

    int i = 0, j;
    char choice;
    string find;

    while (1)
    {
        clearScreen();
        cout << "\n\n\t\t\t   COURSE MANAGEMENT SYSTEM\n\n";
        cout << "\n\n\t\t\t\t:MAIN SCREEN:\n\n";
        cout << "\t\t\t1. Student Section" << endl;
        cout << "\t\t\t2. Teacher Section" << endl;
        cout << "\t\t\t3. Exit Program" << endl;
        cout << "\n\n\t\tEnter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        clearScreen();

        switch (choice)
        {
        case '1':
        {
            while (1)
            {
                clearScreen();
                cout << "\t\tSTUDENT INFORMATION DATA SECTION\n\n\n";
                cout << "\t\t\t1. Register new student\n";
                cout << "\t\t\t2. Search and display student\n";
                cout << "\t\t\t3. Back to main menu\n";
                cout << "\n\n\t\tEnter your choice: ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice)
                {
                case '1':
                {
                    ofstream f1("student.txt", ios::app);
                    for (i = 0; (choice != 'N' && choice != 'n'); i++)
                    {
                        if ((choice == 'y') || (choice == 'Y') || (choice == '1'))
                        {
                            clearScreen();
                            cout << "\t\t\tNEW ENTRY\n\n";
                            cout << "\t\t\tEnter First name: ";
                            cin >> studentData.fname;
                            cout << "\n\t\t\tEnter Last name: ";
                            cin >> studentData.lname;
                            cout << "\n\t\t\tEnter Registration number: ";
                            cin >> studentData.Registration;
                            cout << "\n\t\t\tEnter class: ";
                            cin >> studentData.classes;
                            f1 << studentData.fname << endl << studentData.lname << endl << studentData.Registration << endl << studentData.classes << endl;
                            cout << "\n\n\t\t\tPress Y for Continue and N to Finish:   ";
                            cin >> choice;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    f1.close();
                }
                continue;

                case '2':
                {
                    ifstream f2("student.txt");
                    clearScreen();
                    cout << "\n\t\tDISPLAY STUDENT'S DATA\n";
                    cout << "\n\t\t\tEnter First name to be displayed: ";
                    cin >> find;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl;
                    int notFound = 0;
                    while (getline(f2, studentData.fname) &&
                           getline(f2, studentData.lname) &&
                           getline(f2, studentData.Registration) &&
                           getline(f2, studentData.classes))
                    {
                        if (studentData.fname == find)
                        {
                            notFound = 1;
                            cout << "\n\t\t\tFirst Name: " << studentData.fname << endl;
                            cout << "\n\t\t\tLast Name: " << studentData.lname << endl;
                            cout << "\n\t\t\tRegistration Number: " << studentData.Registration << endl;
                            cout << "\n\t\t\tClass: " << studentData.classes << endl << endl;
                        }
                    }
                    if (notFound == 0)
                        cout << "\n\t\tNo Record Found" << endl;
                    f2.close();
                    waitForKey();
                }
                continue;

                case '3':
                    break;
                }
                break;
            }
            continue;
        }

        case '2':
        {
            while (1)
            {
                clearScreen();
                cout << "\t\tTEACHER INFORMATION DATA SECTION\n\n\n";
                cout << "\t\t\t1. Register new teacher\n";
                cout << "\t\t\t2. Search and display teacher\n";
                cout << "\t\t\t3. Back to main menu\n";
                cout << "\n\n\t\tEnter your choice: ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice)
                {
                case '1':
                {
                    ofstream t1("teacher.txt", ios::app);
                    for (i = 0; choice != 'n' && choice != 'N'; i++)
                    {
                        if ((choice == 'y') || (choice == 'Y') || (choice == '1'))
                        {
                            clearScreen();
                            cout << "\t\t\tEnter First name: ";
                            cin >> tech[i].fst_name;
                            cout << "\n\t\t\tEnter Last name: ";
                            cin >> tech[i].lst_name;
                            cout << "\n\t\t\tEnter Qualification: ";
                            cin >> tech[i].qualification;
                            cout << "\n\t\t\tEnter Experience(year): ";
                            cin >> tech[i].exp;
                            cout << "\n\t\t\tEnter Year in this institute: ";
                            cin >> tech[i].serves;
                            cout << "\n\t\t\tEnter Subject: ";
                            cin >> tech[i].subj;
                            cout << "\n\t\t\tEnter Lecture(per Week): ";
                            cin >> tech[i].lec;
                            cout << "\n\t\t\tEnter Pay: ";
                            cin >> tech[i].pay;
                            cout << "\n\t\t\tEnter Phone Number: ";
                            cin >> tech[i].cel_no;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            t1 << tech[i].fst_name << endl << tech[i].lst_name << endl
                               << tech[i].qualification << endl << tech[i].exp << endl
                               << tech[i].serves << endl << tech[i].subj << endl << tech[i].lec
                               << endl << tech[i].pay << endl << tech[i].cel_no << endl << endl;
                            cout << "\n\n\t\t\tDo you want to enter data (Y/N): ";
                            cin >> choice;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    t1.close();
                }
                continue;

                case '2':
                {
                    ifstream t2("teacher.txt");
                    clearScreen();
                    cout << "\n\t\tDISPLAY TEACHER'S DATA\n";
                    cout << "\n\t\t\tEnter name to be displayed: ";
                    cin >> find;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl;
                    int notFound = 0;
                    string dummy_blank_line;
                    while (getline(t2, tech[0].fst_name))
                    {
                        getline(t2, tech[0].lst_name);
                        getline(t2, tech[0].qualification);
                        getline(t2, tech[0].exp);
                        getline(t2, tech[0].serves);
                        getline(t2, tech[0].subj);
                        getline(t2, tech[0].lec);
                        getline(t2, tech[0].pay);
                        getline(t2, tech[0].cel_no);
                        getline(t2, dummy_blank_line);
                        if (tech[0].fst_name == find)
                        {
                            notFound = 1;
                            cout << "\n\t\t\tFirst name: " << tech[0].fst_name << endl;
                            cout << "\n\t\t\tLast name: " << tech[0].lst_name << endl;
                            cout << "\n\t\t\tQualification: " << tech[0].qualification << endl;
                            cout << "\n\t\t\tExperience: " << tech[0].exp << endl;
                            cout << "\n\t\t\tYear in this Institute: " << tech[0].serves << endl;
                            cout << "\n\t\t\tSubject: " << tech[0].subj << endl;
                            cout << "\n\t\t\tLecture (per Week): " << tech[0].lec << endl;
                            cout << "\n\t\t\tPay: " << tech[0].pay << endl;
                            cout << "\n\t\t\tPhone Number: " << tech[0].cel_no << endl;
                        }
                    }
                    t2.close();
                    if (notFound == 0)
                        cout << "\n\t\tNo Record Found" << endl;
                    waitForKey();
                }
                continue;

                case '3':
                    break;
                }
                break;
            }
            continue;
        }

        case '3':
        {
            cout << "\n Thank you for using the system!\n";
            return 0;
        }
        }
    }
}

int login() {
    string input_pass;
    cout << "\n\n\n\n\n\n\n\n\t\t\t     COURSE MANAGEMENT SYSTEM \n\n";
    cout << "\t\t\t------------------------------";
    cout << "\n\t\t\t\t      LOGIN \n";
    cout << "\t\t\t------------------------------\n\n";
    cout << "\t\t\tEnter Password: ";
    cin >> input_pass;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (input_pass == "123") {
        cout << "\n\n\n\t\t\tAccess Granted! \n";
        waitForKey();
        clearScreen();
        return 1;
    } else {
        cout << "\n\n\t\t\tAccess Aborted...\n\t\t\tPlease Try Again\n\n";
        waitForKey();
        clearScreen();
        return login();
    }
}
