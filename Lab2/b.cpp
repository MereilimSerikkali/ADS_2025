#include <iostream>
#include <string> 
class Node{
public:
    string data;
    Node* prev;
    Node* next;
    Node(string data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void insertAtEnd(Node*& head, string data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


Node* cyclicShift(Node* head, Node* tail, int n, int k){
    k = k%n;

    tail->next = head;
    head->prev = tail;

    Node* newTail = head;
    for(int i = 0; i < k - 1; i++){
        newTail = newTail -> next;

    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    newHead->prev = nullptr;
    
    return newHead;

}



int main(){
    int n, k;
    cin >> n >> k;
    Node* head = nullptr;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        insertAtEnd(head, word);
    }
    head = cyclicShift(head, k);
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->data;
    }
    cout << endl;
    return 0;

}