// including headers files
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

// functions
void login();
void registration();
void forgot();

int main()
{
    int c;
    cout << "\t\t\t_________________________________________________\n";
    cout << "\t\t\t              Wellcome to login page             \n";
    cout << "\t\t\t_____________        MENU        ________________\n";
    cout << "                                                 \n";
    cout << "\t\t\tPlease enter your choice\n";
    cout << "\t\t\tPRESS 1 : LOGIN\n";
    cout << "\t\t\tPRESS 2 : RESITRATION\n";
    cout << "\t\t\tPRESS 3 : FORGOT PASSWORD\n";
    cout << "\t\t\tPRESS 4 : EXIT\n";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\tthank you for your response!!\n";
        break;

    default:
        system("cls");
        cout << "\t\t\tplease enter valid choice\n";
        main();
    }
}

// function description
void login()
{
    int count;
    string username, password, id, pass;
    cout << "\t\t\tPlease enter userid and password\n";
    cout << "USERNAME : ";
    cin >> username;
    cout << "PASSWORD : ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == username && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << "\t\t\t your login is sucessful\n \t\t\t Thanks for log in!!\n";
        main();
    }
    else
    {
        cout << "\t\t\tLOGIN ERROR\n \t\t\t please check your username and password";
        main();
    }
}

void registration()
{
    int count;
    string rusername, rpassword, rid, rpass;
    cout << "\t\t\tPlease enter userid and password\n";
    cout << "ENTER THE USERNAME : ";
    cin >> rusername;
    cout << "ENTER THE PASSWORD : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << rusername << " " << rpassword << endl;

    system("cls");
    cout << "\n\t\t\t  Registration is successfull !\n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t you forgot your password? no worries\n";
    cout << "PRESS 1 to search your id by username\n";
    cout << "PRESS 2 to go back to menu\n";
    cout << "\t\t\tenter your choice\n";
    cin >> option;

    switch (option)
    {
        case 1:
       {
           int count = 0;
           string susername, sid, spass;
           cout << "\t\t\tPlease enter userid  which you remeber\n";
           cout << "USERNAME : ";
           cin >> susername;

           ifstream f2("records.txt");
           while (f2 >> sid >> spass)
           {
                if (sid == susername )
                {
                    count = 1;
                }
            }
            f2.close();

            if (count == 1)
            {
                cout << "\t\t\t your account is find\n \t\t\t your password is " << spass << "\n";
                main();
            }
            else
            {
                cout << "\t\t\tSorry your account is not found\n";
                main();
            }
            break;
        }
        case 2:
        {
            main();
        }
        default:
        {
           cout << "\t\t\t wrong choice!  please try again";
           forgot();
        }
    }
}