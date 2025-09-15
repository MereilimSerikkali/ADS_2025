#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;
    Node(string data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void insertAtBeginning(Node*& head, string data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

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

string deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        return "error";
    }
    string data = head->data;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    return data;
}

string deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        return "error";
    }
    Node* temp = head;
    if (temp->next == nullptr) {
        string data = head->data;
        head = nullptr;
        delete temp;
        return data;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    string data = temp->data;
    temp->prev->next = nullptr;
    delete temp;
    return data;
}

string front(Node*& head) {
    if (head == nullptr) {
        return "error";
    }
    return head->data;
}

string back(Node*& head) {
    if (head == nullptr) {
        return "error";
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->data;
}

void clear(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    string s;
    Node* head = nullptr;
    while (cin >> s) {
        if (s == "add_front") {
            string w;
            cin >> w;
            insertAtBeginning(head, w);
            cout << "ok" << endl;
        }
        else if (s == "add_back") {
            string w;
            cin >> w;
            insertAtEnd(head, w);
            cout << "ok" << endl;
        }
        else if (s == "erase_front") {
            cout << deleteAtBeginning(head) << endl;
        }
        else if (s == "erase_back") {  // Fixed: was erase_front
            cout << deleteAtEnd(head) << endl;
        }
        else if (s == "front") {
            cout << front(head) << endl;
        }
        else if (s == "back") {
            cout << back(head) << endl;
        }
        else if (s == "clear") {
            clear(head);
            cout << "ok" << endl;
        }
        else if (s == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}