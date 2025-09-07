#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(int n){
    if(n < 2){
        return false;
    }
    for(int check = 2; check * check <= n; check++){
        if(n% check == 0){
            return false;
        }
    }
    return true;

}

int nth_prime(int num){
    int count = 2;
    int prime_count = 0;
    while (true){
        if(is_prime(count)){
            prime_count++;
        if(prime_count == num){
            return count;
        }
    }
    
    count++;
    }

}
int main(){
    int n = 0;
    cin >> n;
    cout << nth_prime(n);
    return 0;
}