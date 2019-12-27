#include <stdio.h>
#include <stdlib.h>
struct LINK 
{
    int data;
    struct LINK* next;
};

LINK *head = (LINK*)malloc(sizeof(LINK)); // สร้างกล่องขึ้นมาเพื่อชี้ไปยังตัวแรก

void isEmpty() // 1
{

    if (head -> next == NULL) // ถ้าว่าง ปริ้น yes
    {
        printf("yes\n");
    }else
    {
        printf("no\n");
    }

}

int getSize() // 2
{
    LINK *currNode = head;
    int count = 0;
    if (head -> next == NULL) // ถ้าโหนดแรก = null
    {  
        return count; // return 0
    }
    while (currNode -> next != NULL) // ถ้าตัวถัดไป ไม่ใช่ null
    { 
        count ++; // นับขึ้น 1
        currNode = currNode -> next; //ชี้ตัวถัดไป
    }
    return count;
}

void insertList(int index, int newitem) // 3
{
    LINK *newNode = (LINK*)malloc(sizeof(LINK)); // สร้างกล่องขึ้นมา
    if (index >= 1 && index <= (getSize()) + 1 ) // ถ้าอยู่ในช่วงจน.ข้อมูล (กล่อง)
    {
        newNode -> data = newitem; // set ค่า newNode
        if (index == 1){ // ตน.แรก
            newNode -> next = head -> next; // สลับไม่ได้เพราะสายจะขาด ข้อมูลจะหาย
            head -> next = newNode;

        }
        else
        {
            LINK *curNode = head;
            for (int i = 1 ; i <= index-1; i++) // หาตน.ก่อนหน้าที่จะแทรก
            {
                curNode = curNode -> next;
            }
            newNode -> next = curNode -> next; // ให้ newnode ชี้ตัวถัดไปก่อน เพราะสายจะขาด
            curNode -> next = newNode;
            
        }
    }
} 

void removeList(int index) // 4
{
    
    LINK *curNode = head -> next; // เริ่มต้น cur = ตัวแรก
    if (index >= 1 && index <= (getSize())) // ถ้าอยู่ในช่วงจน.ข้อมูล (กล่อง)
    { 
        if (index == 1) // ตน.แรก
        {
            head -> next = curNode -> next ; // head ชี้ไปตัวที่ 2 (ข้ามตัวแรก)
        }
        else {

            for (int i = 1; i < index-1;i++) // หาตน.ก่อนหน้าที่จะลบ
            {
                curNode = curNode -> next;
            }
            curNode -> next = curNode -> next -> next; // ชี้ข้ามตัวที่จะลบ
        }
    }
    
}

void retrieveList(int x) // 5 (รับ index แสดง data)
{
    LINK *curNode = head -> next; // เริ่มต้น cur = ตัวแรก
    if (x >= 1 && x <= (getSize())) // ถ้าอยู่ในช่วงจน.ข้อมูล (กล่อง)
    {
        for (int i = 1;i < x; i++) // หาตน.ก่อนหน้าที่จะหา
        {
            curNode = curNode -> next;
        }
        printf("%d\n", curNode -> data); // แสดง data
    }else
    {
        printf("no\n");
    }
}

void findList(int data) // 6 (รับ data แสดง index)
{
    LINK *curNode = head; // เริ่มต้น cur ยังไม่ใช่โหนดแรก
    if (head -> next != NULL) {
        int count = 0;
        while(curNode -> next != NULL){
            curNode = curNode -> next;
            count++;
            if(curNode -> data == data){
                printf("%d\n", count);
                break;
            }
        }
        if(curNode -> data != data)
            printf("no\n");
    }
    else
        printf("no\n");
} 

void displayList() // 7
{
    LINK* cur = head;
    if(head -> next != NULL) {
        while (cur -> next != NULL)
       {
            cur = cur -> next;
            printf("%d ", cur -> data) ;
       }
       printf("\n");
    }
}

int main() 
{
    int n, x, y;
    while (n != 8) {
        scanf("%d", &n);

        if (n == 1){
            isEmpty();
        }
        else if (n == 2){
            printf("%d\n", getSize());
        }
        else if (n == 3){
            scanf("%d", &x);
            scanf("%d", &y);
            insertList(x, y);
        }
        else if (n == 4){
            scanf("%d", &x);
            removeList(x);
        }
        else if (n == 5){
            scanf("%d", &x);
            retrieveList(x);
        }
        else if (n == 6){
            scanf("%d", &x);
            findList(x);
        }
        else if (n == 7){
            displayList();
        }
    } 

    return 0;
}