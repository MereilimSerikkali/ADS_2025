#include <iostream>
#include <cmath>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// insertion a node at the beginning
void insertAtBeginning(Node*& head, int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
int finding_index(Node* head, int k){
    int min_index = 0;
    int mindiff = abs(head->data - k);
    Node* temp = head->next;
    int index = 1;
    while (temp != nullptr){
        int diff = abs(temp->data - k);
        if(diff <= mindiff){
            mindiff = diff;
            min_index = index;
        }
        temp = temp-> next;
        index++;
    }
    return min_index;

}
int main(){
    int n;
    cin >> n;
    Node* head = nullptr;
    for(int i = 0; i < n; ++i){
        int value;
        cin >> value;
        insertAtBeginning(head, value);
    }
    int k;
    cin >> k;
    int result =  finding_index(head, k);
    cout << n - 1 - result << endl;



    return 0;
}