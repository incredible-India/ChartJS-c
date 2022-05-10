void exitFn(void);
void takeInfo(void);
//function for chnaging the co-ordinates
void gotoxy(int xPos,int yPos)
{
   COORD c;

    c.X = xPos;
    c.Y = yPos;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);


}


//function for changing the forground color
void setcolor(int ForgC)
{
     WORD wColor;


     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

//function for Creating  menu option

void Menu(char *data,int xPos,int yPos,int color)
{
	
	gotoxy(xPos,yPos);
	setcolor(color);
	printf("%s",data);
	
	
	
}

//function for showing the menu option

void showMenu()
{
	char choice;
	
	SetConsoleTitle("ChartJs");
	
	system("cls");
	
	Menu("1 : Create Chart",20,6,3);
	Menu("2 : See Old Chart",20,8,6);
	Menu("3 : Exit",20,10,4);
	
	//date
	gotoxy(50,4);
	printf("%s",__DATE__);
	
	again:
	choice = getch();
	
	if(choice == '1')
	{
		takeInfo();
		
	}else if(choice == '2')
	{
		
	}else if (choice == '3')
	{
		exitFn();
	
		
		}else{
			
			goto again;
			
		}	
	
}



void exitFn()
{
	    system("cls");
		gotoxy(40,12);
		printf("Thanx For Your Time..");
		getch();
		exit(0);
}
