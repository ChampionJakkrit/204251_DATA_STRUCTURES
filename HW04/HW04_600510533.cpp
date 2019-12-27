#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *backPtr;
node *tempPtr;
int counter = 0;

bool isEmpty();
void enqueue(int x);
bool getFront();
bool dequeue();
int getSize();
void clearQueue();

int main()
{
    backPtr = NULL;
    int n;
    do {
        cin >> n;
        if (n == 6) {
            if (isEmpty()) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else if (n == 1) {
            int x;
            cin >> x;
            enqueue(x);
        }
        else if (n == 2) {
            if (dequeue()) {
                cout << tempPtr -> data << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else if (n == 3) {
            if (getFront()) {
                cout << tempPtr -> data << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else if (n== 4) {
            clearQueue();
        }
        else if (n == 5) {
            cout << getSize() << endl;
        }
    }while (n != 7);

}

bool isEmpty(){
    if (backPtr == NULL) {
        return true;
    }
    else {
        return false;
    }
}
0
void enqueue(int x) {
    node *newNode = new node;
    newNode -> data = x;
    newNode -> next = NULL;
    if (isEmpty()) {
        backPtr = newNode;
        backPtr -> next = backPtr;
    }
    else {
        newNode -> next = backPtr -> next;
        backPtr -> next = newNode;
        backPtr = newNode;
    }
    counter++;
}

bool getFront() {
    if (isEmpty()) {
        return false;
    }
    else {
        tempPtr = backPtr -> next;
        return true;
    }
}

bool dequeue() {
    if (getFront()) {
        backPtr -> next = tempPtr -> next;
        if (tempPtr == backPtr) {
            backPtr = NULL;
        }
        counter--;
        return true;
    }
    else {
        return false;
    }
}

int getSize() {
    return counter;
}

void clearQueue() {
    if (getSize() == 0) {
        cout << "no" << endl;
    }
    else {
        while (!isEmpty()) {
            int z = backPtr -> data;
            if (getSize() == 1) {
            cout << z << endl;
            }
            else {
            cout << backPtr -> next -> data << " ";
            }
        dequeue(); 
        }
    }
}