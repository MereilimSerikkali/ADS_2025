#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int calculateSum(const vector<int>& row) {
    int sum = 0;
    for (int num : row) {
        sum += num;
    }
    return sum;
}

bool compareRows(const vector<int>& a, const vector<int>& b) {
    int sumA = calculateSum(a);
    int sumB = calculateSum(b);
    
    if (sumA != sumB) {
        return sumA > sumB;
    }
    
    return a < b;
}

void merge(vector<vector<int>>& rows, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<vector<int>> leftArr(n1);
    vector<vector<int>> rightArr(n2);
    
    for (int i = 0; i < n1; i++) {
        leftArr[i] = rows[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = rows[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (compareRows(leftArr[i], rightArr[j])) {
            rows[k] = leftArr[i];
            i++;
        } else {
            rows[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        rows[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        rows[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(vector<vector<int>>& rows, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(rows, left, mid);
        mergeSort(rows, mid + 1, right);
        
        merge(rows, left, mid, right);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> rows(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
        }
    }
    
    mergeSort(rows, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << rows[i][j];
            if (j < m - 1) {
                cout << " ";
            }
        }
        cout << " " << endl;  // This ensures proper newline after each row
    }
    
    return 0;
}