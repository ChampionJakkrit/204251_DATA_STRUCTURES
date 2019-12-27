#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *header;
bool isEmpty();
void addNode(int value);
void displayList();
int main()
{
    header = NULL;
    if(isEmpty()){
        cout << "yes" << endl;
    }
    int value;
    cin >> value;
    addNode(value);
    cin >> value;
    addNode(value);
    displayList();
    if(!isEmpty()){
        cout << "no" << endl;
    }

}
bool isEmpty(){
    if(header == NULL){
        return true;
    }
    return false;
}
void addNode(int value){
    node *newNode,*currNode;
    currNode = header;
    newNode = new node;
    newNode->next = NULL;
    newNode->data = value;
    if(isEmpty()){
        header = newNode;
    }
    else{
        while(currNode->next != NULL){
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }

}
void displayList(){
    node *currNode;
    currNode = header;
    while (currNode != NULL){
        cout << currNode->data;
        currNode = currNode->next;
    }
}