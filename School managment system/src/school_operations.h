#ifndef SCHOOL_OPERATIONS
#define SCHOOL_OPERATIONS

#include "linked_lists.h"

#define 	EXIT            		0
#define 	NEW_STUDENT     		1
#define 	DELETE_STUDENT  		2
#define 	STUDENTS_LIST   		3
#define 	STUDENT_EDIT    		4
#define 	RANK_STUDENT    		5
#define 	STUDENT_SCORE   		6
#define 	PRINT_STUDENT_DATA		7

#define 	CHANGE_NAME				1
#define 	CHANGE_ID				2
#define 	CHANGE_MATH_GRADE		3
#define		CHANGE_SCIENCE_GRADE	4

#define		STUDENT_NAME			1
#define		STUDENT_ID				2
#define 	MATH_GRADE				3
#define		SCIENCE_GRADE			4
#define		ADDRESS					5
#define 	DATE_OF_BIRTH			6
#define 	PHONE_NUMBER			7

typedef node Linked_data;

void print_student_data(uint32 ID,node**data_base);
void read_data_base(node**data_base);
void new_student(student*st,node**data_base);
void delete_student(uint32 criteria,node**data_base);
void print_students(node *data_base);
void sort(uint8 criteria,node**data_base);
void update_score(node**data_base);
#endif
