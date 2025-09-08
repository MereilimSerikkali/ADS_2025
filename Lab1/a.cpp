#include <iostream>
#include <deque>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        deque<int> deq;
        for(int i = n; i >= 1; i --){
            deq.push_front(i);
            for(int j = 0; j < i; j++){
                int x = deq.back();
                deq.pop_back();
                deq.push_front(x);
            }
        }
        for(int i = 0; i < n; i++){
            cout << deq[i];
            if (i + 1 == n) {
                cout << '\n';  
            } else {
                cout << ' ';    
            }
        }
    }
}