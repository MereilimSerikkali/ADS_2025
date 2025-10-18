#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Date {
    string original;
    int day, month, year;
    
    Date(const string& dateStr) : original(dateStr) {
        day = stoi(dateStr.substr(0, 2));
        month = stoi(dateStr.substr(3, 2));
        year = stoi(dateStr.substr(6, 4));
    }
    
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<Date> dates;
    
    for (int i = 0; i < n; i++) {
        string dateStr;
        cin >> dateStr;
        dates.push_back(Date(dateStr));
    }
    
    sort(dates.begin(), dates.end());

    for (const Date& date : dates) {
        cout << date.original << endl;
    }
    
    return 0;
}