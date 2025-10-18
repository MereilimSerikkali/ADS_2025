#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quick_sort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    
    int p = arr[(l + r) / 2];
    int i = l;
    int j = r;


    while (i <= j) {while (arr[i] < p) i++;
        while (arr[j] > p) j--;


        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }


    if (l < j)
        quick_sort(arr, l, j);

    if (i < r)
        quick_sort(arr, i, r);
}


void quick_sort(vector<int>& arr) {
    if (!arr.empty()) {
        quick_sort(arr, 0, arr.size() - 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr1(n), arr2(m);
    
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    

    quick_sort(arr1);
    quick_sort(arr2);
    

    vector<int> result;
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            result.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    for (int k = 0; k < result.size(); k++) {
        if (k > 0) cout << " ";
        cout << result[k];
    }
    
    return 0;
}