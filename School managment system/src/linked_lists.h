#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>
#include "data_types.h"

typedef struct student{
    sint8  name[100];
    sint8  address[100];
    sint8  phone_number[20];
    sint8  date_of_birth[40];
    uint32 ID;
    uint32 math_grade;
    uint32 science_grade;
}student;

typedef struct node{
    student st;
    struct node * next;
}node;



void delete_element(uint32 ID,node**head);
void add_element_end(student*st,node**head);
void add_element_start(student*st,node**head);
void print_linked_list(node*head);
uint8 add_at_location(student*st,node**head,uint32 position);
node * search_for_element(uint32 ID,node*head);
#endif
