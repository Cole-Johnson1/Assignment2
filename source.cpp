#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
};

int main(){

    ifstream inFile("StudentData.txt");
    if (!inFile) {
        // in case the exe is run from the output/ folder
        inFile.open("../StudentData.txt");
    }
    if (!inFile) {
        cerr << "Error: could not open StudentData.txt" << endl;
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
        getline(ss, student.lastName);

        students.push_back(student);
    }

    inFile.close();

    for (const STUDENT_DATA& student : students) {
        cout << student.firstName << " " << student.lastName << endl;
    }

    return 0;
}
