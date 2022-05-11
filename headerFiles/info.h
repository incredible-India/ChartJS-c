

char showGraphOption();
struct node* insertDataInNode(struct node*);
void showConfirmationPage(struct node*);
void SaveAndAhowGraph(struct node*,char);

//creating Node 
struct node
{
    char *label;
    float value;

    struct node *next;


};


void takeInfo()
{
	
	struct node *d1 = (struct node*) malloc(sizeof(struct node));
	
	char *info =  (char*) malloc(200*sizeof(char));
	
	char userChoice;
	
	system("cls");
	setcolor(2);
	fflush(stdin);
	printf("Enter Label Name (ex: price)\n");
	
	
	//taking label  value 
	
	gets(info);
	
	d1->label =   info;
	
	printf("Enter The value of %s (*only numbers)\n",d1->label);
	//taking label`s value
	
	scanf("%f",&d1->value);
	
	d1->next = NULL;
	
	//asking permission for continue or exit 

	askAgain:
	printf("\nEnter : Continue   Backspace : Menu    Esc: Exit    TAB: Show Chart \n");

		
	userChoice = getch();
	
	if(userChoice == ESC)
	{
		exitFn();
		
	}else if(userChoice == ENTER)
	{
		
		d1 = insertDataInNode(d1);//taking the data
		//after insert data in asking for the permission(continue exit show Graph)
		
		goto askAgain;
		
	}else if(userChoice == BKSP)
	{
		showMenu();
		
	}else if(userChoice == TAB)
	{
		showConfirmationPage(d1);
		
	}
	else{
		goto askAgain;
	}
	
	
	

	
	
}

//inserting more data
struct node* insertDataInNode(struct node* d1)
{
	struct node *ptr ;
	char *info = (char *)malloc(100*sizeof(char));
	struct node *tempNode;
	
	ptr = (struct node*)malloc(sizeof(struct node));
	
	tempNode = d1;
	
	while(tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}
	

	
	fflush(stdin);
	printf("\nEnter  Label Name (ex: price)\n");
	
	
	//taking label  value 
	
	gets(info);
	
	ptr->label =   info;
	
	printf("\nEnter The value of %s (*only numbers)\n",ptr->label);
	
	scanf("%f",&ptr->value);
	
	tempNode->next = ptr;
	
	ptr->next = NULL;
	
	return d1;
	
}

//showing the entered data
void showConfirmationPage(struct node* ptr)
{
	struct node *userinfo; //we will pass for file handling coz ptr become null after using while loop for the displaying the user data
	userinfo = ptr;
	char user_choice;
	char graphType;
	system("cls");
	while(ptr!=NULL)
	{
		if(strlen(ptr->label) == 0 ) 
		printf("\nLabel : No Data Given   Value: %f\n",ptr->label,ptr->value);
		else
		printf("\nLabel : %s   Value: %f\n",ptr->label,ptr->value);
		ptr = ptr->next;
	}
	
	printf("\n Enter: Show Graph    BKSP: Main Menu     ESC: Exit   \n");
		readAgain:
		user_choice = getch();
		
		if(	user_choice == ENTER)
		{
			//show the graph option
		 graphType = showGraphOption();
			//In FileHanling.h
			
			SaveAndAhowGraph(userinfo,graphType)	;
			
		}else if(user_choice == BKSP)
		{
			showMenu();
			
		}else if(user_choice == ESC)
		{
			exitFn();
		}else
		{
			goto readAgain;
		}
}



char showGraphOption()
{
	
	char choice;
	system("cls");
	Menu("1 : Line Graph",20,5,1);
	Menu("2 : Bar Graph",20,7,2);
	Menu("3 : Pie Graph",20,9,3);
	Menu("4 : Doughnut Graph",20,11,4);
	Menu("5 : Polar Area Graph",20,13,5);
	
	enterAgain:
	choice =  getch();
	
	if(choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' )
		return choice;
		else 
		goto enterAgain;
		
}	


//for saving the data and showing the graph in html file
 void SaveAndAhowGraph(struct node *ptr,char graphType)
 {
 	struct node *userinfo;
 	
 	userinfo =  ptr; //copying the useinfo in other node 
 	
 	FILE *OpenHTMLFile,*SaveFile;
 	
 	//first saving data in txt file
 	SaveFile = fopen("./TXT/MyChart.text","a");
 
 	fprintf(SaveFile,__DATE__);
 	
 	while(ptr != NULL)
 	{
 		
 		fprintf(SaveFile,"\nLABEL : %s  VALUE : %f \n",ptr->label,ptr->value);
 		ptr = ptr->next;
	 }
 	fprintf(SaveFile,"\n-----------------\n");
 	
 	fclose(SaveFile);
 	/*Saved in txt File now we will save in html file */
 	
 	
 	
 	
	 }	
