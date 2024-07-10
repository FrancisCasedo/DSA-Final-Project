#include <iostream>
#include <queue>
#include <string>
using namespace std;


struct StudentList{
    string StudName;
    string YearLevel;
    string IDNumber;
    string Birthday;
    string Address;
    string DegreeProgram;
    char Gender;
    StudentList(string Name, string Year, string ID, string Birth, string Addr, string Degr, char Gen)
        : StudName(Name), YearLevel(Year), IDNumber(ID), Birthday(Birth), Address(Addr), DegreeProgram(Degr), Gender(Gen) {}
};

void Addstud(queue<StudentList>& studentQueue);
bool ValidName(const string& name);
bool CopyInfo(const queue<StudentList>& studentQueue, const string& name, const string& id);
void loop(queue<StudentList>& studentQueue);

int main(){
    queue<StudentList> studentQueue;
    Addstud(studentQueue);
    
    return 0;
}

void Addstud(queue<StudentList>& studentQueue) {
    string Name;
    string NameInput;
    string Year;
    string ID;
    string IDinput;
    string Month;
    string monthInput;
    string Day;
    string dayInput;
    string year;
    string yearInput;
    string birthday;
    string address;
    string DegreeList[5] = {"Bachelor of Science in Computer Science", "Bachelor of Science in Information Technology", "Bachelor of Science in Computer Engineering", "Bachelor of Science in Information Systems", "Bachelor of Science in Information Technology with Specialization in Cybersecurity"};
    string degreeInput;
    string degree;
    string yearList[4] ={"1st year","2nd Year","3rd Year","4th year"};
    string yearLevel;
    string yearLevelInput;
    string Gender;

    do {
        cout << "Student name: ";
        getline(cin, NameInput);
        if (!ValidName(NameInput)) {
            cout << "Please enter a valid name." << endl;
        }else{
            Name = NameInput;
        }
    } while (!ValidName(NameInput));

    do {
        cout << "ID number: ";
        cin >> IDinput;
        bool validID = true;

        for (char c : IDinput) {
            if (!isdigit(c)) {
                validID = false;
                cout << "Please enter a valid ID number (6 digits long)" << endl;
                system("PAUSE");
                break;
            }
        }

        if (validID) {
            if  (IDinput.length() == 6) {
                ID = IDinput;
                break;
            } else {
                cout << "Please enter a valid ID number (6 digits long)." << endl;
                system("PAUSE");
            }
        }
    } while (true);

    if (IsDuplicate(studentQueue, Name, ID)) {
        cout << "This student is already in the list." << endl;
        return;
    }

    do {
        cout << "Gender (M/F): ";
        cin >> Gender;
        if (Gender != "M" && Gender != "m" && Gender != "F" && Gender != "f") {
            cout << "Input is not included in the options" << endl;
            system("PAUSE");
        }
    } while (Gender != "M" && Gender != "m" && Gender != "F" && Gender != "f");

    do {
        cout << "Month [1-12]: ";
        cin >> monthInput;
        bool validmonth = true;

        for (char c : monthInput) {
            if (!isdigit(c)) {
                validmonth = false;
                cout << "Please enter a valid month (01 - 12)." << endl;
                system("PAUSE");
                break;
            }
        }

        if (validmonth) {
            int month = stoi(monthInput);
            if (month >= 1 && month <= 12) {
                Month = monthInput;
                break;
            } else {
                cout << "Please enter a valid month (01 - 12)." << endl;
                system("PAUSE");
            }
        }
    } while (true);

    do {
        cout << "Day: ";
        cin >> dayInput;
        bool validday = true;

        for (char b : dayInput) {
            if (!isdigit(b)) {
                validday = false;
                cout << "Please enter a valid day (01 - 31)." << endl;
                system("PAUSE");
                break;
            }
        }

        if (validday) {
            int day = stoi(dayInput);
            if (day >= 1 && day <= 31) {
                Day = dayInput;
                break;
            } else {
                cout << "Please enter a valid day (01 - 31)." << endl;
                system("PAUSE");
            }
        }
    } while (true);

    do {
        cout << "Year: ";
        cin >> yearInput;
        bool validyear = true;

        for (char a : yearInput) {
            if (!isdigit(a)) {
                validyear = false;
                cout << "Please enter a valid year" << endl;
                break;
                system("PAUSE");
            }
        }

        if (validyear) {
            int yearcheck = stoi(yearInput);
            if (yearcheck >= 1920 && yearcheck <= 2020) {
                year = yearcheck;
                break;
            } else {
                cout << "Please enter a valid year" << endl;
            }
        }
    } while (true);
    birthday = Day + " " + Month + " " + year;

    do {
        cout << "Degree:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "[" << i + 1 << ". " << DegreeList[i] << "]" << endl;
        }
        cout << ": ";
        cin >> degreeInput;

        if (degreeInput.length() == 1) {
            if (degreeInput == "1" || degreeInput == "2" || degreeInput == "3" || degreeInput == "4" || degreeInput == "5") {
                degree = DegreeList[stoi(degreeInput) - 1];
            } else {
                degreeInput = " ";
                cout << "Invalid Input, input a number from 1 - 5" << endl;
                system("PAUSE");
            }
        } else {
            degreeInput = " ";
            cout << "Invalid Input, input a number from 1 - 5" << endl;
            system("PAUSE");
        }
    } while (degreeInput == " ");

    do {
        cout << "Year Level [1-4]" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "[" << i + 1 << ". " << yearList[i] << "]" << endl;
        }
        cout << ": ";
        cin >> yearLevelInput;

        if (yearLevelInput.length() == 1) {
            if (yearLevelInput == "1" || yearLevelInput == "2" || yearLevelInput == "3" || yearLevelInput == "4") {
                yearLevel = yearList[stoi(yearLevelInput) - 1];
            } else {
                cout << "Invalid Input, input a number from 1 - 4" << endl;
                system("PAUSE");
            }
        } else {
            cout << "Invalid Input, input a number from 1 - 4" << endl;
            system("PAUSE");
        }
    } while (yearLevelInput != "1" && yearLevelInput != "2" && yearLevelInput != "3" && yearLevelInput != "4");

    StudentList student(Name, yearLevel, ID, birthday, address, degree, Gender[0]);
    studentQueue.push(student);
    loop(studentQueue);
}

bool ValidName(const string& name){
    for (char c: name) {
        if (!isalpha(c) && c != ' '){
            return false;
        }
    }
    return true;
}

bool CopyInfo(const queue<StudentList>& studentQueue, const string& name, const string& id) {
    queue<StudentList> CopyQueue = studentQueue;
    while (!CopyQueue.empty()) {
        StudentList student = CopyQueue.front();
        CopyQueue.pop();
        if (student.StudName == name && student.IDNumber == id) {
            return true;
        }
    }
    return false;
}

void loop(queue<StudentList>& studentQueue){
	cin.ignore();
	Addstud(studentQueue);
}