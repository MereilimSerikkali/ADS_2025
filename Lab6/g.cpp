#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<string, string> changeMap;
    set<string> allOld;
    
    for (int i = 0; i < n; i++) {
        string oldNick, newNick;
        cin >> oldNick >> newNick;
        changeMap[oldNick] = newNick;
        allOld.insert(oldNick);
    }
    set<string> targets;
    for (const auto& entry : changeMap) {
        targets.insert(entry.second);
    }
    
    set<string> startingPoints;
    for (const string& nick : allOld) {
        if (targets.find(nick) == targets.end()) {
            startingPoints.insert(nick);
        }
    }
    
    set<string> processed;
    for (const string& nick : allOld) {
        if (startingPoints.find(nick) != startingPoints.end() || processed.find(nick) != processed.end()) {
            continue;
        }
        set<string> currentChain;
        string current = nick;
        
        while (changeMap.find(current) != changeMap.end()) {
            if (currentChain.find(current) != currentChain.end()) {
                startingPoints.insert(current);
                break;
            }
            if (processed.find(current) != processed.end()) {
                break;
            }
            currentChain.insert(current);
            current = changeMap[current];
        }
        
        for (const string& visitedNick : currentChain) {
            processed.insert(visitedNick);
        }
    }
    
    map<string, string> result;
    for (const string& start : startingPoints) {
        string current = start;
        set<string> visited;
        
        while (changeMap.find(current) != changeMap.end() && visited.find(current) == visited.end()) {
            visited.insert(current);
            current = changeMap[current];
        }
        
        result[start] = current;
    }
    
    cout << result.size() << endl;
    for (const auto& entry : result) {
        cout << entry.first << " " << entry.second << endl;
    }
    
    return 0;
}