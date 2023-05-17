#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : head(NULL) {}



void LinkedList::add(int value) {
    if (!head) {
        head = new Node(value);
        return;
    }

    Node* Q = head;
    while (Q->next) {
        if (Q->value == value) {
            Q->count++;
            return;
        }
        Q = Q->next;
    }

    if (Q->value == value) {
        Q->count++;
    }
    else {
        Q->next = new Node(value);
    }
}
void LinkedList::insertAfter(int firstValue, int secondValue) {
    if (isEmpty()) {
        std::cout << "The list is empty.\n";
        return;
    }

    Node* current = head;
    while (current) {
        if (current->value == firstValue) {
            Node* newNode = new Node(secondValue);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode;
        }
        current = current->next;
    }
}
void LinkedList::remove(int value) {
    if (!head) {
        return;
    }

    if (head->value == value) {
        if (head->count > 1) {
            head->count--;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        return;
    }

    Node* Q = head;
    while (Q->next ) {
        if (Q->next->value == value) {
            if (Q->next->count > 1) {
                Q->next->count--;
            }
            else {
                Node* temp = Q->next;
                Q->next = Q->next->next;
                delete temp;
            }
            return;
        }
        Q = Q->next;
    }
}
bool LinkedList::isEmpty() {
    return head == NULL;
}

void LinkedList::printall() {
    if (isEmpty()) {
        std::cout << "The list is empty"<<endl;
        return;
    }

    Node* P = head;
    while (P->next!=NULL) {
        cout << P->value<<"[" << P->count << "] " << " > ";
        P = P->next;
    }
    cout << "List end"<<endl<<endl;
}

void LinkedList::create_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        add(v[i]);
    }
}

int LinkedList::sum() {
    int sum = 0;
    Node* current = head;
    while (current!=NULL) {
        sum =sum+ current->value * current->count;
        current = current->next;
    }
    return sum;
}




int main() {// used chatgpt to get the idea to test main
    
    vector<int> v = { 1, 2, 3, 2, 4, 5, 4 };
    LinkedList list;
    list.create_vector(v);

    
    cout << "Initial linked list: ";
    list.printall();

    int valueToRemove = 2;
    cout << "valueToRemove = 2"<<endl;
    list.remove(valueToRemove);
    list.printall();
    
    int firstValue;
    int secondValue;
    cout << "enter first value"<<endl;
    cin >> firstValue;
    cout << "enter Second value" << endl;
    cin >> secondValue;
    list.insertAfter(firstValue, secondValue);

   cout << "Linked list after inserting " << secondValue << " after " << firstValue << ": ";
    list.printall();

    
    int sum = list.sum();
    cout << "Sum of all nodes: " << sum << std::endl;

    return 0;
}
