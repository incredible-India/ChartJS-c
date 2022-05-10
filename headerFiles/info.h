//creating Node 
struct node* insertDataInNode(struct node*);
void showConfirmationPage(struct node*);
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
	char user_choice;
	system("cls");
	while(ptr!=NULL)
	{
		printf("\nLabel : %s   Value: %f\n",ptr->label,ptr->value);
		ptr = ptr->next;
	}
	
	printf("\n Enter: Show Graph    BKSP: Main Menu     ESC: Exit   \n");
		readAgain:
		user_choice = getch();
		
		if(	user_choice == ENTER)
		{
			
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


