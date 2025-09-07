#include <iostream>
#include <stack>
using namespace std;

bool is_balanced(string str){
    stack <char> st;
    for(char c:str){
        if(!st.empty() && st.top() == c){
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    return st.empty();
}



int main(){
    string s;
    cin >> s;
    if(is_balanced(s)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}