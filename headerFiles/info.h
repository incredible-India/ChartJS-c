//creating Node 
#include<windows.h>
struct node
{
	char dataName[100];
	float dataVal;
	int *ptr;
};

void takeInfo()
{
	int no_of_data;
	
	system("cls");
	
	//taking the number of subjects..	
	gotoxy(40,12);
	printf("Enter the number of data : ");
	scanf("%d",&no_of_data);
	
	
}
