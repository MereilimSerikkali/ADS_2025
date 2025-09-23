#include <iostream>
#include <vector>

using namespace std;

int Binary_search(vector <int>A, int key){
    int l = 0;
    int h = A.size() - 1;
    while(l <= h){
        int mid = (l + h)/2;
        if(key == A[mid]){
            return mid;
        }
        if(key < A[mid]){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}


int main(){
    int n, x;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> x;
    int index = Binary_search(v, x);
    if(index == -1){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
    return 0;
}