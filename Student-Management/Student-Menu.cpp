#include <iostream>

using namespace std;

void StudentMenu();

int main()
{
    StudentMenu();
}

void StudentMenu()
{
    string input;
    char option;
    cout << "======= STUDENT MANAGEMENT =======" << endl;
    cout << "[1. ADD STUDENT]" << endl;
    cout << "[2. VIEW STUDENT LIST]" << endl;
    cout << "[3. EDIT STUDENT]" << endl;
    cout << "[4. DELETE STUDENT]" << endl;
    cout << "[5. MENU]" << endl;
    getline(cin, input);
    if (input.length() == 1){
        option = input[0];
    }else{
        option = ' ';
    }switch (option){
    case '1':{
        //AddStud();
        break;
    }case '2':{
        //ViewStud();
        break;
    }case '3':{
        //EditStud();
        break;
    }case '4':{
        //DeleteStud();
        break;
    }case '5':{
        // MainMenu();
        break;
    }default:{
        cout << "Input is invalid......" << endl;
        cout << "Try again...." << endl;
        system("PAUSE");
        StudentMenu();
        break;
    }
    }
}
