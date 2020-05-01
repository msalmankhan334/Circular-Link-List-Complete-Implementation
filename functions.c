#include <stdio.h>
#include <stdlib.h>
#include "funcheader.h"

int getValue(char *str) {
    int value;
    printf("%s", str);
    scanf("%d", &value);
    return value;
}
void printCList(Node **head) {
    Node *ilterator;
    ilterator = *head;
    if(ilterator == NULL) {
        printf("Circular List is Empty \n");
        return;
    }
    do {
        printf("%d  ", ilterator->number);
        ilterator = ilterator->next;
    }while(ilterator != *head);
    printf("\n");
}
 Node *createNodeList(Node *head, int size) {
     Node *temp,*ilterator;
     int i ;
     ilterator = head;
     for(i = 0; i<size; i++) {
         temp = (Node *)malloc(sizeof(Node));
         if(temp == NULL) {
             printf("Error in Allocating Memory\n");
             exit(0);
         }else if(head == NULL) {
             temp->number = getValue("Enter New Number: ");
             head = temp;
             temp->next = head;
         }
         else{
             ilterator = head;
             while(ilterator->next != head) {
                 ilterator = ilterator->next;
             }
             temp->number = getValue("Enter New Number: ");
             temp->next = head;
             ilterator->next = temp;
         }
     }
     return head;
 }
 void insertNodeAtStrt(Node **head) {
     Node *temp, *tp_head;
     tp_head = *head;
     temp = (Node *)malloc(sizeof(Node));
     if(temp == NULL) {
         printf("Error in Allocating Memory\n");
         exit(0);
     }
     temp->number = getValue("Enter New Number: ");
     temp->next = temp;
     temp->next = *head;
     while(tp_head->next != *head) {
         tp_head = tp_head->next;
     }
     tp_head->next = temp;
     *head = temp;
 }
 int Listlength(Node **head) {
     Node *ilteratot = *head;
     int count =0;
     if(*head == NULL) {
         return 0;
     }
     do
     {
         count++;
         ilteratot = ilteratot->next;
     } while (ilteratot != *head);
  return count;   
 }
 void insertNodeAtEnd(Node **head) {
     Node *temp, *ilterator;
     ilterator = *head;
     while(ilterator->next != *head) {
         ilterator = ilterator->next;
     }
     temp = (Node *)malloc(sizeof(Node));
     if(temp == NULL) {
         printf("Error in Allocating Memory\n");
         exit(0);
     }
     temp->number = getValue("Enter New Number: ");
     temp->next = temp;
     ilterator->next = temp;
     temp->next = *head;
 }
 void insertNodeAtPos(Node **head, int pos) {
     Node *temp, *p, *q;
     q = *head;
     int k = 1;
     temp = (Node *)malloc(sizeof(Node));
     if(temp == NULL) {
         printf("Error in Allocating Memory\n");
         exit(0);
     }
     if(pos == 1) {
         insertNodeAtStrt(head);
     }else if(pos >= Listlength(head)) {
         insertNodeAtEnd(head);
     }else {
         while(k < pos) {
             p = q;
             q = q->next;
             k++;
         }
         temp->number = getValue("Enter New Number: ");
         p->next = temp;
         temp->next = q;
     }
 }

void deleteNodeFrmStrt(Node **head) {
    Node *temp, *ilterator;
    ilterator = *head;
    temp = *head;
    while(ilterator->next != *head) {
        ilterator = ilterator->next;
    }
    *head = temp->next;
    ilterator->next = *head;
    free(temp);
}
void deleteNodeFrmEnd(Node **head) {
    Node *temp, *ilterator, *p;
    ilterator = *head;
    while(ilterator->next != *head) {
        p = ilterator;
        ilterator = ilterator->next;
    }
    p->next = *head;
    free(ilterator);
}
void deleteNodeFrmPos(Node **head, int pos) {
    Node *temp, *ilterator, *nextIlterator;
    int k = 1;
    ilterator = *head;
    if(pos == 1) {
        deleteNodeFrmStrt(head);
    }else if(pos >= Listlength(head)) {
        deleteNodeFrmEnd(head);
    }else {
        while( k < pos) {
            k++;
            temp = ilterator;
            ilterator = ilterator->next;
            nextIlterator = ilterator->next;
        }
        temp->next = nextIlterator;
        free(ilterator);
    }
}
void deleteCompleteCList(Node **head) {
    Node *temp, *ilterator;
    ilterator = *head;
    while(ilterator->next != *head) {
        temp = ilterator;
        ilterator = ilterator->next;
        free(temp);
    }
    *head = NULL;
}