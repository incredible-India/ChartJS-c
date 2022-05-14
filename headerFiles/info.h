

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
			
			SaveAndAhowGraph(userinfo,graphType);
			
			//when html page is ready it will open this..
			system("start OUTPUT/index.html");
			
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
 	
 	struct node *userinfo,*one,*two;
 	
 	char *graph_type;
 	char datareading;
 	
 	userinfo =  ptr; //copying the useinfo in other node 
 	one =  ptr; //copying the useinfo in other node 
 	two =  ptr; //copying the useinfo in other node 
 	
 	FILE *OpenHTMLFile,*SaveFile,*WriteInHtml,*fourth;
 	
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
 	
 	//write the html code ..
 	
 	OpenHTMLFile = fopen("./HTMLTOPUT/first.txt","r");

 	
 	if(OpenHTMLFile == NULL)
 	{
 		system("cls");
 		gotoxy(40,12);
 		printf("File Html has not been found 404...");
 		exit(0);
 		exitFn();
 		
	 }else
	 {
	 	WriteInHtml = fopen("./OUTPUT/index.html","w");
	 	
	 	//writing in html file
	  while(!feof(OpenHTMLFile))
    {

       datareading = fgetc(OpenHTMLFile);

        fputc(datareading,WriteInHtml);

    }
	 	//creating table
	 	while(userinfo != NULL)
	 	{	
	 		if(strlen(userinfo->label) == 0)
	 		{
	 			fprintf(WriteInHtml,"\n<tr> <td> No Data Given </td>\n ");
			 }
			 else{
			 		fprintf(WriteInHtml,"\n<tr> <td> %s </td>\n ",userinfo->label);
			 }
	 	
	 		fprintf(WriteInHtml," <td> %f </td> </tr>\n ",userinfo->value);
	 		
	 		userinfo = userinfo->next;
	 		
		 }
	 	
		//graph type
		if(graphType == '1')
		{
			graph_type = "line";
		}else if(graphType == '2')
		{
			graph_type = "bar";
		}else if(graphType == '3')
		{
			graph_type = "pie";
		}else if(graphType == '4')
		{
			graph_type = "doughnut";
		}else if(graphType == '5')
		{
			graph_type = "polarArea";
		}else
		{
			graph_type = "bar";
		}
	
	 	fprintf(WriteInHtml,"</tbody>\n</table>\n</div>\n</body>\n<script src=\"https://cdn.jsdelivr.net/npm/chart.js\"></script>\n <script>  const ctx = document.getElementById(\'myChart\').getContext(\'2d\');\n  const myChart = new Chart(ctx, {\n type: \'%s\',\ndata: {labels: [",graph_type);
	 
	 	while(one !=NULL)
	 	{
	 		
	 		if(strlen(one->label) == 0)
	 		{
	 				fprintf(WriteInHtml,"\'No Data Given\',");
			 }else
			 {
			 		fprintf(WriteInHtml,"\'%s\',",one->label);
			 }
	 	
	 		one = one->next;
		 }
		 fprintf(WriteInHtml,"],\ndatasets: [{label: \'Your Data\',\ndata: [");
		 
		 while(two != NULL)
		 {
		 	fprintf(WriteInHtml,"%f,",two->value);
		 	
		 	two = two->next;
		 }
		  fprintf(WriteInHtml,"],");
		 
	 
	 	//last page
	 	
	 	fourth = fopen("./HTMLTOPUT/fouth.txt","r");
	 	
	 	datareading = fgetc(fourth);
	while(!feof(fourth))
    {

      
        fputc(datareading,WriteInHtml);
         datareading = fgetc(fourth);


    }
    
	 	fclose(fourth);
	 	fclose(OpenHTMLFile);

	 	fclose(WriteInHtml);
	 	
	 	
	 }
 	
 	
 	
 	
	 }	
	 
	 
 //now for the history pages
	 
//for showing history

void showHistory()
{
	FILE *History;
	
	char choice,datareading;
	system("cls");
	
	Menu("1 : See Raw Data",40,4,2);
	Menu("2 : See In Webpage",40,6,3);
	Menu("3 : Main Menu",40,8,4);
	Menu("4 : Exit",40,10,5);
	
	readaDATA:
	choice = getch();
	
	if(choice == '1')
	{
		History = fopen("./TXT/MyChart.text","r");
		
		if(History == NULL)
		{
			system("cls");
			gotoxy(40,12);
			printf("File Not Found 404..");
			getch();
			exit(0);
		}else
		{
			//shoing data in console
	while(!feof(History))
    {

       datareading = fgetc(History);

        printf("%c",datareading);

    }	
    getch();
    fclose(History);
		}
		
	}else if(choice == '2')
	{
			//when html page is ready it will open this..
			system("start OUTPUT/index.html");
	}else if(choice == '3')
	{
		
	showMenu();
	}else if(choice == '4')
	{
		exitFn();
	}else
	{
		goto readaDATA;
	}
}


