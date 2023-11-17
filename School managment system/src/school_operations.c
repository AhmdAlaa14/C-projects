/*
 * school_operations.c
 *
 *  Created on: Oct 16, 2023
 *      Author: Ahmed Alaa
 */
#include "school_operations.h"
#include "linked_lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void print_student_data(uint32 ID,node**data_base){
	node*temp;
	temp=search_for_element(ID,*data_base);
	if(temp==NULL){
		printf("Not found !!");
		return;
	}
	printf("Name : %s ,Date of birth : %s ,ID : %lu ,Math grade : %lu ,Science grade : %lu , Address : %s "
					", Phone number : %s\n",temp->st.name,temp->st.date_of_birth,temp->st.ID,temp->st.math_grade,temp->st.science_grade\
					,temp->st.address,temp->st.phone_number);
}
void new_student(student*st,node**data_base){
	add_element_start(st,data_base);
}

void delete_student(uint32 ID,node**data_base){
	delete_element(ID,data_base);
}

void print_students(node *data_base){
	print_linked_list(data_base);
}

void sort(uint8 criteria,node**data_base){
	student temp;
	node*i;
	node*j;
	switch(criteria){
	case STUDENT_NAME:{
		for(i=*data_base;i->next!=NULL;i=i->next){
			for(j=i->next;j!=NULL;j=j->next){
				if(strcmp(i->st.name,j->st.name)>0){
					temp=i->st;
					i->st=j->st;
					j->st=temp;
				}
			}
		}
		break;
	}
	case STUDENT_ID:{
		for(i=*data_base;i->next!=NULL;i=i->next){
			for(j=i->next;j!=NULL;j=j->next){
				if(i->st.ID>j->st.ID){
					temp=i->st;
					i->st=j->st;
					j->st=temp;
				}
			}
		}
		break;
	}
	case MATH_GRADE:{
		for(i=*data_base;i->next!=NULL;i=i->next){
			for(j=i->next;j!=NULL;j=j->next){
				if(i->st.math_grade<j->st.math_grade){
					temp=i->st;
					i->st=j->st;
					j->st=temp;
				}
			}
		}
		break;
	}
	case SCIENCE_GRADE:{
		for(i=*data_base;i->next!=NULL;i=i->next){
			for(j=i->next;j!=NULL;j=j->next){
				if(i->st.science_grade<j->st.science_grade){
					temp=i->st;
					i->st=j->st;
					j->st=temp;
				}
			}
		}
		break;
	}
	default:{
		break;
	}
	}

}

void update_score(node**data_base){
	uint8 subject;
	node* temp=*data_base;
	printf("Enter the subject \n"
			"3 MATH\n"
			"4 Science\n");
	scanf("%hhu",&subject);
	printf("Enter the score with respect to Students ID (Ascending)\n");
	sort(STUDENT_ID,data_base);
	switch(subject){
	case MATH_GRADE :{
		while(temp!=NULL){
			scanf("%lu",&(temp->st.math_grade));
			temp=temp->next;
		}
		break;
	}
	case SCIENCE_GRADE:{
		while(temp!=NULL){
			scanf("%lu",&(temp->st.science_grade));
		}
		break;
	}
	}

}

void read_data_base(node**data_base){
	FILE *file=fopen("initial_data_base.csv","r");
	char line[2000];
	student temp;
	(*data_base)=(node*)calloc(1,sizeof(node));
	if(file==NULL){
		perror("Error opening file !!");
		return;
	}

	while (fgets(line, sizeof(line), file) != NULL) {
		char *token;
		token = strtok(line, ",");
		strcpy(temp.name, token);

		token = strtok(NULL, ",");
		strcpy(temp.date_of_birth, token);

		token = strtok(NULL, ",");
		strcpy(temp.address, token);

		token = strtok(NULL, ",");
		temp.ID = atoi(token);

		token = strtok(NULL, ",");
		strcpy(temp.phone_number,token);

		token = strtok(NULL, ",");
		temp.math_grade = atoi(token);

		token = strtok(NULL, ",");
		temp.science_grade = atoi(token);

		new_student(&temp,data_base);
	}
	delete_student(0,data_base);
	fclose(file);
}
