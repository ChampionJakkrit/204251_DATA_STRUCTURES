#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PQ[1000];
int lastindex = -1;

bool isEmpty();
int size();
void insert(int x);
int min();
int parent(int x);
int leftChild(int x);
int rightChild(int x);
void showPriorityQueue();
void removeMin();

int main()
{
    int n, x;
    while (n != 10) {
        scanf("%d", &n);
        if (n == 1) {
            if (isEmpty()) {
                printf("yes\n");
            }
            else {
                printf("no\n");
            }
        }
        else if (n == 2) {
            printf("%d\n", size());
        }
        else if (n == 3) {
            if (isEmpty()) {
                printf("no\n");
            }
            else 
                printf("%d\n", min());
        }
        else if (n == 4) {
            scanf("%d\n", &x);
            insert(x);
        }
        else if (n == 5) {
            if (isEmpty())
                printf("no\n");
            else {
                printf("yes\n");
                removeMin();
            }
        }
        else if (n == 6) {
            if (isEmpty())
                printf("no\n");
            else
                showPriorityQueue();
        }
        else if (n == 7) {
            scanf("%d", &x);
            if (isEmpty() or x > lastindex or x == 0) // x เกินขอบเขต, x เป็นตัวแรก
                printf("no\n");
            else
                printf("%d\n", parent(x));
        }
        else if (n == 8) {
            scanf("%d", &x);
            if (leftChild(x) > lastindex) // ลูกทางซ้ายเกินขอบเขต แสดง no 
                printf("no\n");
            else
                printf("%d\n", PQ[leftChild(x)]); // แสดงลูกทางซ้ายของ ตน.x
        }
        else if (n == 9) {
            scanf("%d", &x);
            if (rightChild(x) > lastindex) // ลูกทางขวาเกินขอบเขต แสดง no 
                printf("no\n");
            else
                printf("%d\n", PQ[rightChild(x)]); // แสดงลูกทางขวาของ ตน.x
        }
    }
    return 0;
}

bool isEmpty() // 1
{
    if (size() == 0) {
        return true;
    }
    else {
        return false;
    }
}

int size() // 2
{
    int count = 0;
    count = lastindex + 1;
    return count;
}

int min() // 3
{
    return PQ[0]; // เพราะเรียงน้อยไปมากอยู่แล้ว
}

void insert(int x) // 4
{
    PQ[lastindex + 1] = x; // เพิ่ม index ที่ 0
    lastindex += 1;

    int temp, currindex; 
    currindex = lastindex; // ถ้าไม่จำลอง lastindex จะเพั้ยน
    while (currindex > 0 and PQ[currindex] < PQ[((currindex - 1) / 2)]) { // ถ้าถ้าพ่อเป็นตัวแรกและลูกน้อยกว่าพ่อให้ทำ 
        temp = PQ[((currindex - 1) / 2)]; // ฝากค่าไว้ (แบบนี้เรียก upheap)
        PQ[((currindex - 1) / 2)] = PQ[currindex]; // สลับค่าลูกกับพ่อ
        PQ[currindex] = temp; // สลับค่าพ่อกับลูก
        currindex = ((currindex - 1) / 2); // สลับ index
    }
}

void removeMin() // 5
{
    int temp;
    temp = PQ[0]; // ฝากค่า
    PQ[0] = PQ[lastindex]; // สลับตัวแรกกับตัวสุดท้าย
    PQ[lastindex] = temp;
    lastindex = lastindex - 1; // ลบตัวสุดท้าย
    int dad = 0, next;
    while (dad <= lastindex) {

        next = dad; // หาตน. min
        if (2*dad + 1 <= lastindex and PQ[next] > PQ[2*dad + 1]) // มีซ้ายมั้ย และ ถ้าซ้ายน้อยไปหาซ้ายต่อ
            next = 2*dad + 1;
        if (2*dad + 2 <= lastindex and PQ[next] > PQ[2*dad + 2]) // มีขวามั้ย และ ถ้าขวาน้อยไปหาขวายต่อ
            next = 2*dad + 2;
         if (dad == next) { // ถ้าพ่อเท่ากับ ไม่ต้องไปไหน
            break;
        }

        temp = PQ[dad]; // สลับค่าพ่อกับลูก
        PQ[dad] = PQ[next];
        PQ[next] = temp;
        dad = next;
    }
}

void showPriorityQueue() // 6
{
    for (int i = 0; i <= lastindex; i++) {
        printf("%d ", PQ[i]);
    }
    printf("\n");
}

int parent(int x) // 7
{
    return PQ[(x - 1) / 2]; // คืนค่าพ่อ
}

int leftChild(int x) // 8
{
    return (2*x + 1); // คืนค่า index
}

int rightChild(int x) // 9
{
    return (2*x + 2); // คืนค่า index
}

