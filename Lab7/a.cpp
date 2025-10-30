#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void merge(vector<string>& arr, vector<string>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i].length() <= arr[j].length()) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int idx = left; idx <= right; ++idx) {
        arr[idx] = temp[idx];
    }
}

void mergeSort(vector<string>& arr, vector<string>& temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void mergeSort(vector<string>& arr) {
    if (arr.empty()) {
        return;
    }
    vector<string> temp(arr.size());
    mergeSort(arr, temp, 0, arr.size() - 1);
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int set = 0; set < n; set++) {
        string line;
        getline(cin, line);
        
        vector<string> words;
        stringstream ss(line);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        mergeSort(words);
        
        for (size_t i = 0; i < words.size(); i++) {
            cout << words[i];
            if (i < words.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}