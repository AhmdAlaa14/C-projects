#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "school_operations.h"

int main(){
	setbuf(stdout, NULL);
	unsigned int operation=1;
	unsigned int data_change=1;
	sint8 name[100];
	student temp;
	node * found=NULL;
	Linked_data *data_base=NULL;
	read_data_base(&data_base);
	printf("Main Menu \nInsert the number of the operation :\n1 Add new student\n2 Delete student\n3 List students\n4 Edit student data\n5 List students according to a subject\n6 Update students scores \n7 Print student data\n0 EXIT\n");
	while(operation!=EXIT){
		scanf("%d",&operation);
		if(operation<EXIT || operation >PRINT_STUDENT_DATA){
			printf("Invalid option !!\n");
		}
		switch (operation)
		{
		case PRINT_STUDENT_DATA:{
			printf("Enter student's ID : ");
			scanf("%lu",&temp.ID);
			print_student_data(temp.ID,&data_base);
			break;
		}
		case NEW_STUDENT:{
			printf("Name : ");
			getchar();
			fgets(name,100,stdin);
			name[strlen(name)-1]='\0';
			strcpy(temp.name,name);

			printf("Date of birth : ");
			getchar();
			fgets(name,100,stdin);
			name[strlen(name)-1]='\0';
			strcpy(temp.date_of_birth,name);

			printf("Phone number : ");
			//getchar();
			fgets(name,100,stdin);
			name[strlen(name)-1]='\0';
			strcpy(temp.phone_number,name);

			printf("Address : ");
			fgets(name,100,stdin);
			name[strlen(name)-1]='\0';
			strcpy(temp.address,name);

			printf("ID : ");
			scanf("%lu",&temp.ID);

			printf("Math grade : ");
			scanf("%lu",&temp.math_grade);

			printf("Science grade : ");
			scanf("%lu",&temp.science_grade);

			new_student(&temp,&data_base);

			break;
		}
		case DELETE_STUDENT:{
			printf("Enter Student's ID : ");
			scanf("%lu",&temp.ID);
			delete_student(temp.ID,&data_base);
			break;
		}
		case STUDENTS_LIST:{
			sort(STUDENT_NAME,&data_base);
			print_students(data_base);
			break;
		}
		case STUDENT_EDIT:{
			printf("Enter the ID of the student : ");
			scanf("%lu",&temp.ID);
			data_change=1;
			while(data_change!=EXIT){
				printf("Enter what you want to change : "
						"\n1- Name."
						"\n2- ID."
						"\n3- Math grade."
						"\n4- Science grade."
						"\n5- Address."
						"\n6- Date of birth."
						"\n7- Phone number."
						"\n0- Done.\n");
				scanf("%d",&data_change);
				if(data_change<EXIT||data_change>PHONE_NUMBER){
					printf("Invalid option !\n");
					break;
				}
				found=search_for_element(temp.ID,data_base);

				if(found==NULL){
					printf("No such ID !!");
					continue;
				}

				switch(data_change){
				case CHANGE_NAME:{
					printf("Enter new Name : ");
					getchar();
					fgets(name,100,stdin);
					name[strlen(name)-1]='\0';
					strcpy(temp.name,name);
					strcpy(found->st.name,temp.name);
					break;
				}
				case ADDRESS:{
					printf("Enter new address : ");
					getchar();
					fgets(name,100,stdin);
					name[strlen(name)-1]='\0';
					strcpy(found->st.address,name);
					break;
				}
				case PHONE_NUMBER:{
					printf("Enter new date of birth : ");
					getchar();
					fgets(name,100,stdin);
					name[strlen(name)-1]='\0';
					strcpy(found->st.phone_number,name);
					break;
				}
				case DATE_OF_BIRTH:{
					printf("Enter new date of birth : ");
					getchar();
					fgets(name,100,stdin);
					name[strlen(name)-1]='\0';
					strcpy(found->st.date_of_birth,name);
					break;
				}
				case CHANGE_ID:{
					printf("Enter new ID : ");
					scanf("%lu",&temp.ID);
					found->st.ID=temp.ID;
					break;
				}
				case CHANGE_MATH_GRADE:{
					printf("Enter new Math grade : ");
					scanf("%lu",&temp.math_grade);
					found->st.math_grade=temp.math_grade;
					break;
				}
				case CHANGE_SCIENCE_GRADE:{
					printf("Enter new Science grade : ");
					scanf("%lu",&temp.science_grade);
					found->st.science_grade=temp.science_grade;
					break;
				}
				}
			}
			break;
		}
		case RANK_STUDENT:{
			sint32 subject=0;
			printf("Choose the subject \n"
					"3 Math\n"
					"4 Science\n");
			scanf("%ld",&subject);
			if(subject<3 || subject >4){
				printf("Invalid option !!\n");
				break;
			}
			sort(subject,&data_base);
			print_linked_list(data_base);
			break;
		}
		case STUDENT_SCORE:{
			update_score(&data_base);
			break;
		}
		case EXIT:{

			break;
		}
		default:{
			break;
		}
		}
		if(operation!=EXIT){
			printf("Main Menu \nInsert the number of the operation :\n1 Add new student\n2 Delete student\n3 List students\n4 Edit student data\n5 List students according to a subject\n6 Update students scores \n7 Print student data\n0 EXIT\n");
		}

	}
	return 0;
}
