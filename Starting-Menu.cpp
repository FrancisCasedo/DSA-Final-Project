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
        cout << "[3. COURSE MANAGEMENT]" << endl;
        cout << "[4. EXIT]" << endl;
        cout << ": ";
        getline(cin, input);
        if (input.length() == 1){
            option = input[0];
        }else{
            option = '5';
        }switch (option){
        case '1':{
            // Enrollment();
            break;
        }case '2':{
            // StudentManagement();
            break;
        }case '3':{
            // ScheduleManagement();
            break;
        }case '4':{
            // CourseManagement();
            break;
        }case '5':{
                char option2;
                cout << "Do you want to continue? [Y/N]: ";
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
