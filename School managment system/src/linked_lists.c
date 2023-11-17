#include <stdio.h>
#include <stdlib.h>
#include "data_types.h"
#include "linked_lists.h"

void print_linked_list(node*head){
	node*temp=head;
	if(head==NULL){
		printf("Data base is empty.\n");
	}
	while(temp!=NULL){
		printf("Name : %s ,Date of birth : %s ,ID : %lu ,Math grade : %lu ,Science grade : %lu , Address : %s "
				", Phone number : %s\n",temp->st.name,temp->st.date_of_birth,temp->st.ID,temp->st.math_grade,temp->st.science_grade\
				,temp->st.address,temp->st.phone_number);
		temp=temp->next;
	}
}
node * search_for_element(uint32 ID,node*head){
	node * temp=head;
	if(head==NULL){
		return NULL;
	}
	while(temp!=NULL){
		if(temp->st.ID==ID){
			return temp;
		}else{
			temp=temp->next;
		}
	}
	return NULL;
}
void delete_element(uint32 ID,node**head){
	/*TOFIX*/
	if(*head==NULL){
		printf("Data base is empty !!");
		return;
	}
	node *now=*head,*prev=NULL;
	while(now!=NULL){
		if(ID == now->st.ID && now==(*head)){
			free(*head);
			(*head)=now->next;
			if(ID!=0){
				printf("Student deleted.\n");
			}

			if (*head==NULL){
				printf("Data base is now empty !!");
			}
			return;
		}else if (now->st.ID==ID){
			prev->next=now->next;
			free(now);
			if(ID!=0){
				printf("Student deleted.\n");

			}
			return;
		}else{
			prev=now;
			now=now->next;
		}
	}
	printf("Not Found !!\n");
}

void add_element_end(student*st,node**head){
	node*temp=NULL;
	if(*head==NULL){
		*head=(node*)calloc(1,sizeof(node));
		(*head)->st=*st;
		(*head)->next=NULL;
	}else{
		temp=*head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=(node*)calloc(1,sizeof(node));
		temp=temp->next;
		temp->next=NULL;
		temp->st=*st;
	}
}
void add_element_start(student*st,node**head){
	node*temp=NULL;
	if(*head==NULL){
		*head=(node*)calloc(1,sizeof(node));
		(*head)->st=*st;
		(*head)->next=NULL;
	}else{
		temp=(node*)calloc(1,sizeof(node));
		temp->next=*head;
		temp->st=*st;
		(*head)=temp;
	}
}
uint8 add_at_location(student*st,node**head,uint32 position){
	node*temp=*head;
	if(position==0){
		add_element_start(st,head);
		return 1;
	}
	for(int i=1;i<position;i++){
		if(temp->next==NULL){
			return 0;
		}
		temp=temp->next;
	}
	node*new=(node*)calloc(1,sizeof(node));
	new->st=*st;
	new->next=temp->next;
	temp->next=new;
	return 1;
}
