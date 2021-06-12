#include<stdio.h>
#include<stdlib.h>

struct node
{
	char ssn[10],name[10],dept[15],desig[10],phno[15];
	int sal;
	struct node*llink;
	struct node*rlink;
};
typedef struct node *NODE;
NODE temp,FIRST=NULL,END=NULL;

NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	return x;
}
void read()
{
	temp=getnode();
	temp->llink=NULL;
	temp->rlink=NULL;
	printf("Enter SSN:");
	scanf("%s",temp->ssn);
	printf("Enter Name:");
	scanf("%s",temp->name);
	printf("Enter Dept:");
	scanf("%s",temp->dept);
	printf("Enter Designation:");
	scanf("%s",temp->desig);
	printf("Enter Phno:");
	scanf("%s",temp->phno);
	printf("Enter Salary:");
	scanf("%d",&temp->sal);
	return;
}
void Create_DLL()
{
	int n,i=1;
 	printf("Enter the number of Employees\n");
	scanf("%d",&n);
	while(i<=n)
	{
		printf("Enter the details of the %d employee\n",i++);
		read();
		if(FIRST==NULL)
			{
				FIRST=temp;
				END=temp;
			}
			else
			{
				END->rlink=temp;
				temp->llink=END;
				END=temp;
			}
	}
}
void Display_count()
{
	temp=FIRST;
	int count=1;
	printf("Employee details:\n");
	if(FIRST==NULL)
	{
		printf("The employee detail is NULL and count is %d\n",count-1);
	}
	else
	{
		while(temp!=END)
		{
			count++;
			printf("%s\t%s\t%s\t%s\t%s\t%d\n",temp->ssn,temp->name,temp->dept,temp->desig,temp->phno,temp->sal);
			temp=temp->rlink;
		}
			printf("%s\t%s\t%s\t%s\t%s\t%d\n",temp->ssn,temp->name,temp->dept,temp->desig,temp->phno,temp->sal);
			printf("student count is %d\n",count);
	}
	return;
}
void Insertionfront()
{
	printf("Enter the details of the employee\n");
	read();
	if(FIRST==NULL)
		FIRST=temp;
	else
	{
		temp->rlink=FIRST;
		FIRST->llink=temp;
		FIRST=temp;
	}
}
void Insertionend()
{
	printf("Enter the details of the new employee\n");
	read();
	if(FIRST==NULL)
	{
		FIRST=temp;
		END=temp;
	}
	else
	{
		END->rlink=temp;
		temp->llink=END;
		END=temp;
	}
	return;
}
void Deletionfront()
{
	temp=FIRST;
	if(FIRST==NULL)
	{
		printf("List is empty\n");
	}
	else if(FIRST==END)
	{
		printf("Deleted element is %s\n",temp->ssn);
		FIRST=NULL;
		END=NULL;
		free(temp);
	}
	else
	{
		printf("Deleted element is %s\n",temp->ssn);
		FIRST=FIRST->rlink;
		FIRST->llink=NULL;
		free(temp);
	}
	return;
}
void Deletionend()
{
	temp=END;
	if(FIRST==NULL)
	{
		printf("List is empty\n");
	}
	else if(FIRST==END)
	{

		printf("Deleted element is %s\n",temp->ssn);
		FIRST=NULL;
		END=NULL;
		free(temp);
	}
	else
	{
		printf("Deleted element is %s\n",temp->ssn);
		END=END->llink;
		END->rlink=NULL;
		free(temp);
	}
	return;
}
void main()
{
	int choice;
	while(1)
	{
		printf("------------------MENU---------------\n");
		printf("-------------------------------------\n");
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:Create_DLL();
					break;
				case 2:Display_count(FIRST);
					break;
				case 3:Insertionfront();
					break;
				case 4:FIRST=Insertionend(FIRST);
					break;
				case 5:Deletionfront();
					break;
				case 6:Deletionend();
					break;
				case 7:return;
				default:printf("\n Invalid Choice\n");
			}
	}
} 


		

