#include <iostream>
#include <vector>
using namespace std;


void quickSort(vector<long long>& arr, int left, int right) {
    if (left >= right) return;
    long long pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int upperBound(const vector<long long>& arr, long long value) {
    int l = 0, r = (int)arr.size(); 
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] <= value) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // sort 
    quickSort(a, 0, n - 1);

    // prefix sums
    vector<long long> pref(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = a[i] + (i ? pref[i-1] : 0);
    }

    int q;
    cin >> q;
    while (q--) {
        long long p;
        cin >> p;
        int cnt = upperBound(a, p);
        long long sum = (cnt == 0) ? 0 : pref[cnt-1];
        cout << cnt << " " << sum << "\n";
    }

    return 0;
}
