#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int item)  // สร้าง node ใหม่
    { 
        data = item;
        next = NULL;
    }
};

struct AdjList
{
    Node *head;
    Node *last;
};

struct Graph
{
    int numofvertex;
    AdjList *array;

    Graph(int n_vertex)
    {
        numofvertex = n_vertex;
        array = new AdjList[n_vertex]; // จอง list (ได้กราฟ)
        for (int i = 0; i < n_vertex; i++) {
            array[i].head = NULL; // set head = NULL
            array[i].last = NULL;
        }
    }
    void addEdge(int src, int des)
    {
        Node *desNode;
        des--;
        desNode = new Node(des); // สร้าง list ที่เหมือนกันมา เพื่อจะได้ชี้
        src --;
        if (array[src].head == NULL) {
            array[src].head = desNode;
            array[src].last = desNode;
        }
        else {
            desNode -> next = array[src].last -> next;
            array[src].last -> next = desNode;
            array[src].last = desNode;
        }
    }
    void printGraph()
    {
        for (int i = 0; i < numofvertex; i++) {
            printf("%d :", i + 1);
            Node *currNode = array[i].head;
            while (currNode != NULL) {
                printf("%d ", currNode -> data+1);
                currNode = currNode -> next;
            }
            printf("\n");
        }
    }
};

struct Queue
{
    int Q[1000];
    int f;
    int r;
    int temp;
    Queue(int i){
        f = i;
        r = -1;
    }
    void enqueue(int value)
    {
        r ++;
        Q[r] = value;
        
    }
    bool dequeue()
    {
        if (r == -1 or f > r) { // Q ว่าง
            return false;
        }
        else {
            temp = Q[f];
            f++;
            return true;
        }
    }
    bool isEmpty(){
        if(r == -1 or f > r)
            return true;
        return false;
    }
    void printQueue(){
        for(int i = f; i <= r; i++) {
            cout << Q[i] << endl;
        }
        cout << endl;
    }
};

bool unqueueAry[1000];
bool visitNode[1000];
Queue q(0);

void BFS(Graph g, int start)
{
    Node *currNode;
    q.enqueue(start);
    unqueueAry[start] = false;
    while(!q.isEmpty()) {
        if(q.dequeue()) {
            printf("%d ", q.temp+1);
            currNode = g.array[q.temp].head;
            while(currNode != NULL){
                if(unqueueAry[currNode -> data]) {
                    q.enqueue(currNode -> data);
                    unqueueAry[currNode -> data] = false;
                }
                currNode = currNode -> next;
            }
        }
    }
}

void DFS(Graph g, int start)
{
    Node *currNode;
    currNode = g.array[start].head;
    if (visitNode[start])
        printf("%d ", start+1);
    visitNode[start] = false;
    while(currNode != NULL) {
        if (visitNode[currNode -> data] == true)
            DFS(g, currNode -> data);
        currNode = currNode -> next;
    }
}

int main()
{
    int n_node, n_edge, value1, value2, start;
    scanf("%d", &n_node);
    scanf("%d", &n_edge);
    Graph g(n_node);
    for (int i = 0; i < n_edge; i++) {
        scanf("%d", &value1);
        scanf("%d", &value2);
        g.addEdge(value1, value2);
    }
    scanf("%d", &start);
    
    for (int i = 0; i < n_node; i++) { // ทำให้เป็นสีขาวทั้งหมด
        unqueueAry[i] = true;
        visitNode[i] = true;
    }

    BFS(g, start-1);
    printf("\n");
    DFS(g, start-1);

    return 0;
}
