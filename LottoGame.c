//Program that plays a lotto game with 6 modularised menu options and uses pointer notation when dealing with arrays, option 1-selecting numbers,option 2-displaying the numbers,option 3-sorting the numbers,option 4-comparing to the winning numbers,option 5-display the frequency of inputted numbers,option 6-terminating the program
//  assignment2.c
//  assignment2
//  Created by Josh O'Leary on 23/02/2020.
//  Copyright © 2020 Josh O'Leary. All rights reserved.
// winning numbers: 1,3,5,7,9,11
// Prizes - 3 matches=Cinema Pass, 4 matches=Weekend Away, 5 matches=New Car, 6 matches=Jackpot

#include <stdio.h>
#define SIZE 6
#define RANGE 42
int opt1(int*);
void opt2(int*);
int opt3(int*);
void opt4(int*);
void opt5(int*);
int opt6(int);
int win[SIZE]={1,3,5,7,9,11};

int main()
{
    int menu;
    int pnums[SIZE];
    int i=0;
    
    while(i==0)//continues program till termination
    {
        printf("----Main menu----\n");
        printf("1-Select your 6 numbers between 1-42\n");
        printf("2-Display your 6 numbers\n");
        printf("3-Sort your numbers in smallest to largest\n");
        printf("4-Compare your numbers to the winning numbers\n");
        printf("5-Display the frequency of the numbers inputted\n");
        printf("6-Quit\n");
        
        
        scanf("%d",&menu);
        while(menu<1 || menu>6)
        {
            printf("Invalid input menu is between 1-6\n");
            scanf("%d",&menu);
        }
    
        switch(menu) //All functions run through the main switch statement
        {
            case 1:
            {
                opt1(pnums);
                break;
            }//end case 1
                
            case 2:
            {
                opt2(pnums);
                break;
            }//end case 2
            
            case 3:
            {
                opt3(pnums);
                break;
            }//end case 3
            
            case 4:
            {
                opt4(pnums);
                break;
            }//end case 4
                
            case 5:
            {
                opt5(pnums);
                break;
            }//end case case 5
                
            case 6:
            {
                int count=0;
                i=opt6(count);
            }//end case 6
            
        }//end switch
    }//end while
}//end main





int opt1(int* playern) //MENU OPTION 1:INPUTTING PLAYER NUMBERS
{
    int i;
    int *ptr=playern;
    
    printf("Enter your 6 numbers\n");
    for(i=0;i<SIZE;i++)
    {
        scanf("%d",ptr);
        while(*ptr>42 || *ptr<1)//error checking for numbers below or above the range
        {//start if
            printf("Invalid number must stay between 1-42 range,enter another number\n");
            scanf("%d",ptr);
        }//end if
        ptr++;
    }//end for
    
    printf("All 6 numbers entered\n");
    
    return playern[SIZE]; //returning array to main
}//end opt1


void opt2(int* playern) //MENU OPTION 2:DISPLAYING PLAYER NUMBERS
{
    int *ptr=playern; //point to playern
    int i;
    
    printf("Your numbers are:\n");
    
    for(i=0;i<SIZE;i++)
    {
        printf("%d\n",*ptr);
        ptr++;
    }
} //end opt2

int opt3(int* playern) //MENU OPTION 3: SORTING PLAYER NUMBERS IN ORDER
{
    int i,j;
    int temp;
    
    //sorting the numbers through the use of bubble sort
    for(j=0;j<SIZE-1;j++)
    {//start outer for
        for(i=0;i<SIZE-1;i++)
        {//start inner for
            if(*(playern+i)>*(playern+(i+1)))
            {//start if
                temp=*(playern+i);
                *(playern+i)=*(playern+i+1);
                *(playern+i+1)=temp;
            }//end if
        }//end inner for
    }//end outer for
    
    return playern[SIZE];
}//end opt3


void opt4(int* playern) //MENU OPTION 4: COMPARING PLAYER NUMBERS TO WINNING NUMBERS
{
    int matchcounter=0;
    int i,j;
       
    for(i=0;i<SIZE;i++)
    {//start outer for
        for(j=0;j<SIZE;j++)
        {//start inner for
            if(*(playern+i)==*(win+j))
            {
                matchcounter++;
            }//end if
        }//end inner for
    }//end outer for
    
    if(matchcounter==0)
    {
        printf("You have 0 match-No prizes try playing again :(\n");
    }
    
    if(matchcounter==1)
    {
        printf("You have 1 match-No prizes try playing again :(\n");
    }
    
    if(matchcounter==2)
    {
        printf("You have 2 matches-No prizes try playing again :(\n");
    }
    
    if(matchcounter==3)
    {
        printf("You have 3 matches-Congratulations you win a Cinema pass\n");
    }//end if
    
    if(matchcounter==4)
    {
        printf("You have 4 matches-Congratulations you win a Weekend away\n");
    }//end if
    
    if(matchcounter==5)
    {
        printf("You have 5 matches-Congratulations you win a new car\n");
    }//end if
    
    if(matchcounter==6)
    {
        printf("You have all 6 matches-Congratulations you win the jackpot!\n");
    }
    
}//end opt4

void opt5(int* playern) //MENU OPTION 5: DISPLAY THE FREQUENCY OF PLAYER NUMBERS INPUTTED
{
    int i,j;
    static int frequency[RANGE]={0};
    
    for(i=0;i<RANGE;i++)
    {//start outer for
        for(j=0;j<RANGE;j++)
        {//start inner for
            if(*(playern+i)==j)
            {//startif
                *(frequency+j)=*(frequency+j)+1;
            }//end if
        }//end inner for
    }//end outer for
    
    for(i=1;i<RANGE;i++)
    {//start for
        if(i==1)//Error prevention as a bug occured where an extra 1 was added to the frequency for number 1
        {//start if
        *(frequency+i)=*(frequency+i)-1;
        }//end if
        if(*(frequency+i)>0)
        {//start if
            printf("%d has been inputted %d times\n",i,*(frequency+i));
        }//end if
    }//end for
}//end opt5

int opt6(int counter) //MENU OPTION 6: GRACEFULLY TERMINATES THE PROGRAM
{
    counter=1;
    return counter;
}//end opt6

