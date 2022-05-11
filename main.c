/*Himanshu Sharma 6th sem B.E */

//inbuild header file
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
//macro define 
#define ENTER 13
#define TAB 9
#define BKSP 8
#define ESC 27
//checking OS type
#ifdef _WIN32
#define win 1
#include<windows.h>
#else 
#define win 0
#endif

//userdefine header files
#include"./headerFiles/func.h"
#include"./headerFiles/info.h"

//global varables
 int i,j;

//function declaration
void gotoxy(int,int);
void Menu(char*,int,int,int);
void setcolor(int);
void showMenu();

//label name cant be blank ka code likhna hai
//main function 
int main()
{
    //checking the type os 
    
    if(win)
    {
   		showMenu();
    	
	}else{
		
		printf("This Software is not supported in linux and its version..");
		getch();
	}

    return 0;

}
