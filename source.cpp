#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
    string email;
};

int main(){

#ifdef PRE_RELEASE
    cout << "Running Pre-Release version" << endl;
    const string dataFile = "StudentData_Emails.txt";
#else
    cout << "Running Standard version" << endl;
    const string dataFile = "StudentData.txt";
#endif

    ifstream inFile(dataFile);
    if (!inFile) {
        // in case the exe is run from the output/ folder
        inFile.open("../" + dataFile);
    }
    if (!inFile) {
        cerr << "Error: could not open " << dataFile << endl;
        return 1;
    }

    vector<STUDENT_DATA> students;
    string line;

    while (getline(inFile, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        STUDENT_DATA student;

        getline(ss, student.firstName, ',');
        getline(ss, student.lastName, ',');
        getline(ss, student.email);

        students.push_back(student);
    }

    inFile.close();

#ifdef _DEBUG
    for (const STUDENT_DATA& student : students) {
        cout << student.firstName << " " << student.lastName << " " << student.email << endl;
    }
#endif

    return 0;
}
