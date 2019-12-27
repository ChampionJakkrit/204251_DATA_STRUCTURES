#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LINK
{
    int data;
    struct LINK *prev;
    struct LINK *next;
};

LINK *head = (LINK*)malloc(sizeof(LINK)); // สร้างกล่องก่อนตัวแรกขึ้นมา
LINK *trail = (LINK*)malloc(sizeof(LINK)); // สร้างกล่องหลังตัวสุดท้ายขึ้นมา

void isEmpty() // 1
{
     if (head -> next == trail) // ถ้าตัวแรกเท่ากับ NULL ปริ้น yes
    {
        printf("yes\n");
    }else
    {
        printf("no\n");
    }
}

int getSize() // 2
{
    LINK *cur = head;
    int count = 0;
    if (head -> next == trail) // ถ้าโหนดแรก = null
    {  
        return count; // return 0
    }
    while (cur -> next != trail) // ถ้าตัวถัดไป ไม่ใช่ null
    { 
        count ++; // นับขึ้น 1
        cur = cur -> next; //ชี้ตัวถัดไป
    }
    return count;
}

void insertFirst(int newitem) // 3
{
    LINK *newNode = (LINK*)malloc(sizeof(LINK)); // สร้างกล่องแรกขึ้นมา
    newNode -> data = newitem; // set ค่า newNode

// ถ้าเพิ่มข้างหน้า newnode จะต้องชี้ตัวถัดไปก่อน ไม่งั้นสายจะขาด ข้อมูลจะหาย
    head -> next -> prev = newNode; // prev กล่องแรกชี้ไป newnode
    newNode -> next = head -> next; // next ของ newnode ชี้ไปกล่องแรก
    head -> next = newNode; // head ชี้ไป newnode ( head ไม่ใช่ตัวแรก)
    newNode -> prev = head; // prev ของ newnode ชี้ไป head
}

void insertLast(int newitem) // 4
{
    LINK *newNode = (LINK*)malloc(sizeof(LINK)); // สร้างกล่องแรกขึ้นมา
    newNode -> data = newitem; // set ค่า newNode

// // ถ้าเพิ่มข้าหลัง newnode จะต้องชี้ตัวก่อนหน้าก่อน ไม่งั้นสายจะขาด ข้อมูลจะหาย
    trail -> prev -> next = newNode; // ตัว next ของตัวสุดท้ายชี้ไป newnode (trail ไม่ใช่ตัวสุดท้าย)
    newNode -> prev = trail -> prev; // prev ของ newnode ชี้ไปตัวรองสุดท้าย
    newNode -> next = trail; // next ของ newnode ชี้ไปที่ trail
    trail -> prev = newNode; // prev ของ trail ชี้ไป newnode

}

void removeFirst() // 5
{
    if (head -> next != trail) // ถ้าตัวแรกไม่ใช่ null 
    {
        head -> next = head -> next -> next; // next ของ head ชี้ไปตัวที่สอง
        head -> next -> prev = head; // prev ของตัวที่สองชี้กลับมาที่ head
    }
}

void removeLast() // 6
{
    if (head -> next != trail) // มีข้อมูลอยู่
    {
        trail -> prev = trail -> prev -> prev; // prev ของ trail ชี้ไปตัวรองสุดท้าย
        trail -> prev -> next =  trail; // next ของตัวรองสุดท้ายชี้ไป trail
    }
}

void displayList() // 7
{
    LINK* curNode = head; // curnode = head
    if (head -> next != trail) { // มีข้อมูล
        while (curNode -> next != trail)
       {
            curNode = curNode -> next; // ชี้ตัวถัดไปเรื่อยๆ
            printf("%d ", curNode -> data) ; // แสดงค่าข้อมูลทุกตัว
       }
    }
    printf("\n");
}

void traverseList(int step, char word[]) // 8
{

    LINK *curNode = head -> next; // ให้ curnode เป็นตัวแรก
    if (head -> next != trail) { // ถ้าไม่ใช่ตัวสุดท้าย
        for (int i = 0; i < step; i++)
        {
            if(word[i] == 'R') { // ถ้าใส่ R
                if (curNode -> next == trail) // ถ้า curnode เป็นตัวสุดท้าย ให้ผ่านไป
                {
                    continue;
                }
                else
                    curNode = curNode -> next; // ชี้ตัวถัดไป
            }
            else if(word[i] == 'L') { // ถ้าใส่ L
                if (curNode -> prev == head) // ถ้า curnode เป็นตัวแรก ให้ผ่านไป
                { 
                    continue;
                }
                else
                    curNode = curNode -> prev; // ชี้ไปตัวก่อนหน้า

            }
       }
       printf("%d\n", curNode -> data); // แสดงค่า
    }
    else
        printf("no\n"); // ไม่มีข้อมูล แสดง no
}

int main() 
{
    head -> next = trail;
    trail -> prev = head;
    int n, x;
    while (n != 9) { // 9 = exit
        scanf("%d", &n);

        if (n == 1){
            isEmpty();
        }
        else if (n == 2){
            printf("%d\n", getSize());
        }
        else if (n == 3){
            scanf("%d", &x);
            insertFirst(x);
        }
        else if (n == 4){
            scanf("%d", &x);
            insertLast(x);
        }
        else if (n == 5){
            removeFirst();
        }
        else if (n == 6){
            removeLast();
        }
        else if (n == 7){
            displayList();
        }
        else if (n == 8){
            scanf("%d", &x);

            char word[x]; // สร้าง char จำนวน x ช่อง ชื่อ word

            scanf("%s", word);
            traverseList(x, word); 
        }
    } 

    return 0;
}