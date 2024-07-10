#include <iostream>

using namespace std;

int main()
{
    string input;
    char option;
    cout << "\t\tTGG v2 UNIVERISTY" << endl;
    while (true){
        cout << "===== MENU ======" << endl;
        cout << "[1. ENROLLMENT]" << endl;
        cout << "[2. STUDENT MANAGEMENT]" << endl;
        cout << "[3. SCHEDULE MANAGEMENT]" << endl;
        cout << "[4. COURSE MANAGEMENT]" << endl;
        cout << "[5. EXIT]" << endl;
        cout << ": ";
        getline(cin, input);
        if (input.length() == 1){
            option = input[0];
        }else{
            option = '5';
        }switch (option){
        case '1':{
            cout << "// Enrollment();"<<endl;
            break;
        }case '2':{
            cout << "// StudentManagement();"<<endl;
            break;
        }case '3':{
            cout << "// ScheduleManagement();"<<endl;
            break;
        }case '4':{
            cout << "// CourseManagement();"<<endl;
            break;
        }case '5':{
                char option2;
                cout << "Do you want to continue exit? [Y/N]: ";
                cin >> option2;
                if (option2 == 'Y' || option2 == 'y'){
                    cout << "Exiting the Program....." << endl;
                    system("PAUSE");
                    exit(EXIT_SUCCESS);
                }else{
                    cout << "Going back to the Main Menu" << endl;
                    system("PAUSE");
                }
                break;
        }default:
            cout << "Input is invalid......" << endl;
            cout << "Going back to the Main Menu......" << endl;
            system("PAUSE");
            break;
        }
    }
}
