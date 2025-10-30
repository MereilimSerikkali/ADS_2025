#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student {
    string lastname;
    string firstname;
    double gpa;
};

double getGradeValue(const string& grade) {
    if (grade == "A+") return 4.00;
    if (grade == "A") return 3.75;
    if (grade == "B+") return 3.50;
    if (grade == "B") return 3.00;
    if (grade == "C+") return 2.50;
    if (grade == "C") return 2.00;
    if (grade == "D+") return 1.50;
    if (grade == "D") return 1.00;
    return 0.00;
}

bool compareStudents(const Student& a, const Student& b) {
    if (a.gpa != b.gpa) return a.gpa < b.gpa;
    if (a.lastname != b.lastname) return a.lastname < b.lastname;
    return a.firstname < b.firstname;
}

int main() {
    int n;
    cin >> n;
    
    vector<Student> students(n);
    
    for (int i = 0; i < n; i++) {
        cin >> students[i].lastname >> students[i].firstname;
        int numSubjects;
        cin >> numSubjects;
        
        double totalPoints = 0;
        int totalCredits = 0;
        
        for (int j = 0; j < numSubjects; j++) {
            string grade;
            int credit;
            cin >> grade >> credit;
            
            totalPoints += getGradeValue(grade) * credit;
            totalCredits += credit;
        }
        
        students[i].gpa = totalPoints / totalCredits;
    }
    
    sort(students.begin(), students.end(), compareStudents);
    
    cout << fixed << setprecision(3);
    for (const auto& student : students) {
        cout << student.lastname << " " << student.firstname << " " << student.gpa << endl;
    }
    
    return 0;
}