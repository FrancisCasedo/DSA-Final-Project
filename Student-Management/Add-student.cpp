#include <iostream>
#include <queue>
#include <string>
#include <fstream>

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
bool CopyInfo(queue<StudentList>& studentQueue, const string& name, const string& id);
void displayList(const queue<StudentList>& studentQueue);
void DeleteStudent(queue<StudentList>& studentQueue);
void EditStudent(queue<StudentList>& studentQueue);

int main() {
    queue<StudentList> studentQueue;
    string input;
    char option;

   
    ifstream file("student_list.txt");
    if (file.is_open()) {
        string line;
        string Name, Year, ID, Birth, Addr, Degr;
        char Gen;

        while (getline(file, line)) {
            if (line.find("Name: ") != string::npos) {
                Name = line.substr(6); // Extract the value after "Name: "
                getline(file, line); // Read and discard the empty line
                Year = line.substr(12); // Extract the value after "Year: "
                getline(file, line); // Read and discard the empty line
                ID = line.substr(11); // Extract the value after "ID: "
                getline(file, line); // Read and discard the empty line
                Birth = line.substr(10); // Extract the value after "Birth: "
                getline(file, line); // Read and discard the empty line
                Addr = line.substr(9); // Extract the value after "Addr: "
                getline(file, line); // Read and discard the empty line
                Degr = line.substr(16); // Extract the value after "Degr: "
                getline(file, line); // Read and discard the empty line
                Gen = line[8]; // Extract the value after "Gen: "

                // Create a StudentList struct and push it to the queue using constructor
                StudentList student(Name, Year, ID, Birth, Addr, Degr, Gen);
                studentQueue.push(student);

                // Debug output
                cout << "Added student: " << student.StudName << endl;
            }
        }
        file.close();
        cout << "Student records loaded from file." << endl;
    } else {
        cerr << "Unable to open file 'student_list.txt' for reading." << endl;
    
    }if(studentQueue.empty()){
    	cout << "bobo mo" << endl ;
	}


    do {
        cout << "======= STUDENT MANAGEMENT =======" << endl;
        cout << "[1. ADD STUDENT]" << endl;
        cout << "[2. VIEW STUDENT LIST]" << endl;
        cout << "[3. EDIT STUDENT]" << endl;
        cout << "[4. DELETE STUDENT]" << endl;
        cout << "[5. EXIT]" << endl;
        getline(cin, input);

        if (input.length() == 1) {
            option = input[0];
        } else {
            option = ' ';
        }

        switch (option) {
            case '1': {
                Addstud(studentQueue);
                break;
            }
            case '2': {
                displayList(studentQueue);
                break;
            }
            case '3': {
                EditStudent(studentQueue);
                break;
            }
            case '4': {
                DeleteStudent(studentQueue);
                break;
            }
            case '5': {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Input is invalid..." << endl;
                cout << "Try again..." << endl;
                break;
            }
        }
    } while (true);

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
    string DegreeList[5] = { "Bachelor of Science in Computer Science", "Bachelor of Science in Information Technology", "Bachelor of Science in Computer Engineering", "Bachelor of Science in Information Systems", "Bachelor of Science in Information Technology with Specialization in Cybersecurity" };
    string degreeInput;
    string degree;
    string yearList[4] = { "1st year", "2nd Year", "3rd Year", "4th year" };
    string yearLevel;
    string yearLevelInput;
    string Gender;
    
    ofstream outFile("student_list.txt", ios::app);

    do {
        cout << "Student name: ";
        getline(cin, NameInput);
        if (!ValidName(NameInput)) {
            cout << "Please enter a valid name." << endl;
        } else {
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
            if (IDinput.length() == 6) {
                ID = IDinput;
                break;
            } else {
                cout << "Please enter a valid ID number (6 digits long)." << endl;
                system("PAUSE");
            }
        }
    } while (true);

    if (CopyInfo(studentQueue, Name, ID)) {
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
                year = to_string(yearcheck);
                break;
            } else {
                cout << "Please enter a valid year" << endl;
            }
        }
    } while (true);
    birthday = Day + "/" + Month + "/" + year;

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

    cin.ignore(); // Clear the newline character left in the input buffer
    cout << "Address: ";
    getline(cin, address);

    StudentList student(Name, yearLevel, ID, birthday, address, degree, Gender[0]);
    studentQueue.push(student);
    displayList(studentQueue);

    // Write student info to file
    outFile << "Name: " << student.StudName << endl;
    outFile << "Year Level: " << student.YearLevel << endl;
    outFile << "ID Number: " << student.IDNumber << endl;
    outFile << "Birthday: " << student.Birthday << endl;
    outFile << "Address: " << student.Address << endl;
    outFile << "Degree Program: " << student.DegreeProgram << endl;
    outFile << "Gender: " << student.Gender << endl;
    outFile << "----------------------" << endl;

}

bool ValidName(const string& name){
    for (char c: name) {
        if (!isalpha(c) && c != ' '){
            return false;
        }
    }
    return true;
}

bool CopyInfo(queue<StudentList>& studentQueue, const string& name, const string& id) {
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

void displayList(const queue<StudentList>& studentQueue) {
    queue<StudentList> CopyQueue = studentQueue;
    if (CopyQueue.empty()) {
        cout << "List empty" << endl;
    } else {
        while (!CopyQueue.empty()) {
            StudentList student = CopyQueue.front();
            cout << "Name: " << student.StudName << endl;
            cout << "Year Level: " << student.YearLevel << endl;
            cout << "ID Number: " << student.IDNumber << endl;
            cout << "Birthday: " << student.Birthday << endl;
            cout << "Address: " << student.Address << endl;
            cout << "Degree Program: " << student.DegreeProgram << endl;
            cout << "Gender: " << student.Gender << endl;
            cout << "--------------------------" << endl;
            CopyQueue.pop();
        }
    }
}

void DeleteStudent(queue<StudentList>& studentQueue) {
    queue<StudentList> tempQueue;
    string idnum;
    string Name;
    bool found = false;

    cout << "Delete Student: " << endl;
    cout << "Student: ";
    getline(cin, Name);

    cout << "ID: ";
    getline(cin, idnum);

    while (!studentQueue.empty()) {
        StudentList student = studentQueue.front();
        studentQueue.pop();

        if (student.IDNumber == idnum && student.StudName == Name) {
            found = true;
            cout << "Deleting student: " << endl;
            cout << "Student: " << student.StudName << endl;
            cout << "ID number: " << student.IDNumber << endl;
            cout << "=========================" << endl;
        } else {
            tempQueue.push(student);
        }
    }

    studentQueue = tempQueue;

    if (!found) {
        cout << "Student with ID " << idnum << " not found." << endl;
    }
}

void EditStudent(queue<StudentList>& studentQueue) {
    string idnum;
    string Name;
    string Year;
    string address;
    string DegreeList[5] = {"Bachelor of Science in Computer Science", "Bachelor of Science in Information Technology", "Bachelor of Science in Computer Engineering", "Bachelor of Science in Information Systems", "Bachelor of Science in Information Technology with Specialization in Cybersecurity"};
    string degreeInput;
    string degree;
    string yearList[4] = {"1st year", "2nd Year", "3rd Year", "4th year"};
    string newYearLevel;
    string yearLevelInput;
    string Gender;
    bool found = false;
    queue<StudentList> tempQueue;

    if (studentQueue.empty()) {
        cout << "List is empty..." << endl;
        return;
    } else {
        cout << "Edit Student: " << endl;
        cout << "ID Number: ";
        getline(cin, idnum);
        cout << "Student Name: ";
        getline(cin, Name);

        while (!studentQueue.empty()) {
            StudentList student = studentQueue.front();
            studentQueue.pop();

            if (idnum == student.IDNumber && Name == student.StudName) {
                found = true;
                cout << "Editing student: " << endl;
                cout << "Current Name: " << student.StudName << endl;
                cout << "Current Year Level: " << student.YearLevel << endl;
                cout << "Current ID Number: " << student.IDNumber << endl;
                cout << "Current Birthday: " << student.Birthday << endl;
                cout << "Current Address: " << student.Address << endl;
                cout << "Current Degree Program: " << student.DegreeProgram << endl;
                cout << "Current Gender: " << student.Gender << endl;

                cout << "Enter new Year Level (leave empty to keep current): ";
                getline(cin, yearLevelInput);
                if (!yearLevelInput.empty() && yearLevelInput >= "1" && yearLevelInput <= "4") {
                    student.YearLevel = yearList[stoi(yearLevelInput) - 1];
                }

                cout << "Enter new Address (leave empty to keep current): ";
                getline(cin, address);
                if (!address.empty()) {
                    student.Address = address;
                }

                cout << "Enter new Degree Program (leave empty to keep current): ";
                for (int i = 0; i < 5; i++) {
                    cout << "[" << i + 1 << ". " << DegreeList[i] << "]" << endl;
                }
                getline(cin, degreeInput);
                if (!degreeInput.empty() && degreeInput >= "1" && degreeInput <= "5") {
                    student.DegreeProgram = DegreeList[stoi(degreeInput) - 1];
                }

                cout << "Enter new Gender (leave empty to keep current): ";
                getline(cin, Gender);
                if (!Gender.empty() && (Gender == "M" || Gender == "m" || Gender == "F" || Gender == "f")) {
                    student.Gender = Gender[0];
                }
            }

            tempQueue.push(student);
        }

        studentQueue = tempQueue;

        if (found) {
            ofstream file("student_list.txt");
            if (file.is_open()) {
                queue<StudentList> CopyQueue = studentQueue;
                while (!CopyQueue.empty()) {
                    StudentList student = CopyQueue.front();
                    file << student.StudName << endl;
                    file << student.YearLevel << endl;
                    file << student.IDNumber << endl;
                    file << student.Birthday << endl;
                    file << student.Address << endl;
                    file << student.DegreeProgram << endl;
                    file << student.Gender << endl;
                    file << "=========================" << endl;
                    CopyQueue.pop();
                }
                file.close();
                cout << "Student list saved to file." << endl;
            } else {
                cout << "Unable to open file for saving." << endl;
            }
        } else {
            cout << "Student with ID " << idnum << " and Name " << Name << " not found." << endl;
        }
    }
}