#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <map>
using namespace std;
map<string, double> gpaScale = {
    {"A+", 4.00},
    {"A", 3.75},
    {"B+", 3.50},
    {"B", 3.00},
    {"C+", 2.50},
    {"C", 2.00},
    {"D+", 1.50},
    {"D", 1.00},
    {"F", 0.00}
};

struct Student {
    string lastname;
    string firstname;
    double gpa;
    bool operator<(const Student& other) const {
        if (gpa != other.gpa) return gpa < other.gpa; // Ascending by GPA
        if (lastname != other.lastname) return lastname < other.lastname;
        return firstname < other.firstname;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<Student> students;
    
    for (int i = 0; i < n; i++) {
        string lastname, firstname;
        int subjectCount;
        cin >> lastname >> firstname >> subjectCount;
        
        double totalPoints = 0.0;
        int totalCredits = 0;
        for (int j = 0; j < subjectCount; j++) {
            string mark;
            int credits;
            cin >> mark >> credits;
            
            totalPoints += gpaScale[mark] * credits;
            totalCredits += credits;
        }
        
        double gpa = totalPoints / totalCredits;
        students.push_back({lastname, firstname, gpa});
    }
    sort(students.begin(), students.end());
    cout << fixed << setprecision(3);
    for (const Student& student : students) {
        cout << student.lastname << " " << student.firstname << " " << student.gpa << endl;
    }
    
    return 0;
}