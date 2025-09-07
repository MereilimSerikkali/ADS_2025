#include <iostream>

using namespace std;

bool is_prime(int number){
    bool prime = true; 
    if(number < 2){
        return false;
    }
    for(int i = 2; i*i <= number; i++){
        if(number%i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    long long n;
    cin >> n;
    if(is_prime(n)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}