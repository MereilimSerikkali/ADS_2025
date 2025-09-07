#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++){
        long long p;
        cin >> p;
        v.push_back(p);
    }
    for(int i = 0; i < n; i++){
        bool found = false;
        for(int j = i - 1; j >= 0; j--){
            if(v[j] < v[i]){
                cout << v[j] << ' ';
                found = true;
                break;
            }
        }
        if(found == false){cout << "-1" << ' ';}
    }
}