/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 19, 2016, 9:07 AM
 * Purpose:  Hello World Template
 */

//System Libraries Here
#include <iostream>
#include <cstdlib> //random generator
#include <time.h> // for random
using namespace std;
/***
 * TO DO: ENSURE THAT THERE'S A CHECK IF THE CHARACTERS ARE OUT OF BOUNDS
 * 
 */
 
//User Libraries Here

//Global Constants Only, No Global Variables
 // COL, ROW
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void makeGrid(char[][10]);
void displayGrid(char[][10]);
void player(char[][10]);
void victory();
void loss();
void aiShips();
int disp();
void placeship(char[][10],char, int,int,int);
int check(char[][10],int,int,int);
int boathit(int,int, char);
int Dcount(int);
int Scount(int);
int Bcount(int);
int CCount(int);
int ccount(int);
int aid(int);
int ais(int);
int aib(int);
int aiC(int);
int aic(int);
int win(int);
void fire(char[][10],char[][10],int,int);
void ai(char[][10]);
void play(char[][10],char[][10],char[][10]);
int hit(char&,char);

//Program Execution Begins Here
int main(int argc, char** argv) {
    char name = '_';
 char grid[10][10];
 
    char board[10][10];
    char plays[10][10];
     // to check and stuff
      makeGrid(grid);
    
    makeGrid(plays);
    
       makeGrid(board);
    
    
    placeship(grid,'C',5,4,2);
    placeship(grid,'B',4,4,3);
    placeship(grid,'S',3,7,1);
    placeship(grid,'D',2,8,1);
    placeship(grid,'c',3,7,1);
    
    play(grid,board,plays);
    
  
        
    
   
   
    return 0;
}

void makeGrid(char grid[][10])
{
     for(int row=0;row<=10;row++) //loop for rows
    {
        for(int col=0;col<=10;col++) //loop for columns
        {
            
            grid[col][row]='_';
            
        }
    }
}

void displayGrid(char grid[][10])
{
    
    cout<<"  0 1 2 3 4 5 6 7 8 9 "<<endl;
    
    for(int row=0;row<10;row++)
    {
       
        cout<<row<<" ";
        for(int col=0;col<10;col++)
        {
            
            cout<<grid[col][row]<<" ";
            
        }
        
        
        cout<<endl;
    }
}


void placeship(char grid[][10],char name, int size,int limitm,int limitL)
{
         srand (time(NULL));
    int place1=0;
    int place2=0;
    int dis = disp();
    int place=1;
    do
    {
        
             place1=(rand()%limitm)+limitL;
             place2=(rand()%limitm)+limitL;
            place=check(grid,place2,place1,dis);
    }while(place==1);
    if(dis>=25)
    {
    for(int i = 0; i <size;i++)
    {
        
        grid[place1][place2+i]=name;
        
    }
    }
    else
    {
     for(int i = 0;i<size;i++)
     {
         grid[place1+i][place2]=name;
     }
   
}
}


int disp()
{
 int xory=0;
 xory=rand()%50;
 return xory;
}

int check(char grid[][10],int r, int c, int disp)
{
    char check;
    if(disp>25) // vertical
    {
        for(int i=c;i<10;i++)
        {
            check=grid[c][i];
                    if(check!='_')
                        return 1;
        }
        return 0;
    }
    
    else
    {
        for(int i=r;i<10;i++)
        {
            check=grid[i][r];
            if(check!='_')
                return 1;
        }
        return 0;
    }
    
}
int hit(char grid[][10],char name)
{
   for(int col=0;col<10;col++)
   {
       for(int row=0;row<10;row++)
       {
           int j = 0;
           if(grid[col][row]!=name)
               return 1;
           else
               return 0;
       }
   }
   
}
int boathit(int col, int row)
{
    int D =0;
    char name;
   int  sunk=0;
    switch(name)
    {
        case 'D':
            do{
            cout<<"Destroyer hit!"<<endl;
            }while(D<3);
    }
    
    
}
int win(int A)
{
    static int W=A;
    W++;
    return W;
}   
int Dcount(int A)
{
    
    static int D = 0;
    D++;
    cout<<D<<endl;
    return D;
}
int Scount(int sub)
{
    static int S = sub;
    S++;
    return S;
}
int ccount(int cruise)
{
    static int c = cruise;
    c++;
    return c;
}
int Bcount(int Btl)
{
    static int B=Btl;
    B++;
    return B;
}
int CCount(int Car)
{
    static int C = Car;
    C++;
    return C;
}
int awin(int A)
{
    static int W=A;
    W++;
    return W;
}   

int aid(int A)
{
    
    static int D = 0;
    D++;
    cout<<D<<endl;
    return D;
}
int ais(int sub)
{
    static int S = sub;
    S++;
    return S;
}
int aic(int cruise)
{
    static int c = cruise;
    c++;
    return c;
}
int aib(int Btl)
{
    static int B=Btl;
    B++;
    return B;
}
int aiC(int Car)
{
    static int C = Car;
    C++;
    return C;
}

void fire(char grid[][10],char board[][10],int col, int row)
{
    int first=0;
    int vict;
    int D,c,S,B,C;
    char name=grid[col][row];
    if(name!='_'&&name!='H'&&name!='M')
    {
        vict=win(first);
    cout<<"Game counter in fire function "<<vict<<endl;
    }
    
   
    switch(name)
    {
   
        case 'D':
        
    {
            grid[col][row]='H';
            board[col][row]='H';
            
           
            D=Dcount(first);
            cout<<D<<endl;
            
            if(D==2)
            {
                cout<<"Destroyer sunk!"<<endl;
                 if(vict==18)
    {
         
        victory();
    }
            }
            else
                cout<<"You hit the Destroyer!"<<endl;
          
    
    break;
        }
        case 'c':
        {
            grid[col][row]='H';
            board[col][row]='H';
            c=ccount(first);
            if(c==3){
                cout<<"Cruiser sunk!!"<<endl;
                 if(vict==18)
    {
         
        victory();
    }
            }
            else
                cout<<"Cruise hit!"<<endl;
            break;
        }
        case 'S':
        {
            grid[col][row]='H';
            board[col][row]='H';
            S=Scount(first);
            if(S==3)
            {
                cout<<"Submarine sunk!"<<endl;
              if(vict==18)
    {

        victory();
    }   
            }
            else
                cout<<"Submarine hit!"<<endl;
            break;
        }
        case 'B':
        {
            grid[col][row]='H';
            board[col][row]='H';
            B=Bcount(first);
            if(B==4)
            {
                cout<<"You sunk my battleship!"<<endl;
              if(vict==18)
    {
         
      
        victory();
    }   
            }
            else
                cout<<"Battleship hit!"<<endl;
            break;
            case 'C':
            {
                grid[col][row]='H';
                board[col][row]='H';
                C=CCount(first);
                
                if(C==5)
                {
                    cout<<"Carrier sunk!"<<endl;
                     if(vict==18)
    {
         
     
        victory();
    }
                }
                else
                    cout<<"Carrier hit!"<<endl;
                break;
            }
            case '_':
            {
                cout<<"Miss!"<<endl;
                board[col][row]='M';
                break;
            }
            case 'H':
            {
                cout<<"You already hit that target!!!"<<endl;
                break;
            }
        }
      
    

    
    }
}

void play(char grid[][10],char board[][10],char play[][10])
{
    int col,row;
    int uh=0;
    bool game=true;
    cout<<"First, place down your positions onto the board!"<<endl;
    player(play);
      int y = win(uh);
    do
    {
      
     displayGrid(grid);
     displayGrid(board);
        cout<<"Where would you like to fire! Enter the Column, then the row"<<endl;
    cin>>col;
    cin>>row;
     fire(grid,board,col,row);
     cout<<"Now the AI shall take their shot!"<<endl;
     displayGrid(play);
     ai(play);
     
     
      
      
    }while(game);
}

void victory()
{
    cout<<"You have vanquished your enemies. You won, nigga!"<<endl;
    exit(EXIT_SUCCESS);
}
void loss()
{
    cout<<"You have lost!"<<endl;
    exit(EXIT_SUCCESS);
}

void player(char player[][10])
{
    cout<<"Now you shall create your board!"<<endl;
    int choice,col,row;
    int counter=0;
    
    
    bool place=true;
    while(counter<5)
    {
        for(int i =0;i<2;i++)
        {
            displayGrid(player);
            cout<<"Please enter position "<<i+1<<" for your DESTROYER"<<endl;
            cout<<"Column, then row, and then again"<<endl;
            cin>>col;
            cin>>row;
            player[col][row]='D';
            
                    
            
        }
        counter++;
        displayGrid(player);
        for(int i = 0;i<3;i++)
        {
            cout<<"Please enter position "<<i+1<<" for your SUB. same as before!"<<endl;
            cin>>col;
            cin>>row;
            player[col][row]='S';
            displayGrid(player);
            
        }
        counter++;
        for(int i=0;i<3;i++)
        {
            cout<<"Please enter position"<<i+1<<" for your cruiser"<<endl;
            cin>>col;
            cin>>row;
            player[col][row]='c';
            displayGrid(player);
            
                    
        }
        counter++;
        for(int i=0;i<4;i++)
        {
            cout<<"Please enter position "<<i+1<<" for your BATTLESHIP!"<<endl;
            cin>>col;
            cin>>row;
            player[col][row]='B';
            displayGrid(player);
        }
        counter++;
        for(int i=0;i<5;i++)
        {
            cout<<"Please enter position "<<i+1<<" for your CARRIER!"<<endl;
            cin>>col;
            cin>>row;
            player[col][row]='C';
            displayGrid(player);
        }
        counter++;
            
    }
    
   
}

void ai(char player[][10])
{
    int col = rand()%10;
    int row=rand()%10;
    int first=0;
    int vict;
    int D,c,S,B,C;
    char name=player[col][row];
    
    do
    {
        col=rand()%10;
        row=rand()%10;
        
    }while(player[col][row]=='H'||player[col][row]=='M'||player[col][row]!='_');
   if(name!='_'&&name!='H'&&name!='M')
    {
        vict=awin(first);
    cout<<"Game counter in fire function "<<vict<<endl;
    }
    switch(name)
    {
   
        case 'D':
        
    {
            
            player[col][row]='H';
            
           
            D=aid(first);
            cout<<D<<endl;
            
            if(D==2)
            {
                cout<<"Our Destroyer was sunk!"<<endl;
                 if(vict==18)
    {
         
        loss();
    }
            }
            else
                cout<<"You hit the Destroyer!"<<endl;
          
    
    break;
        }
        case 'c':
        {
            
           player[col][row]='H';
            c=aic(first);
            if(c==3){
                cout<<" Our Cruiser sunk!!"<<endl;
                 if(vict==18)
    {
         
        loss();
    }
            }
            else
                cout<<"Our Cruiser hit!"<<endl;
            break;
        }
        case 'S':
        {
            
            player[col][row]='H';
            S=ais(first);
            if(S==3)
            {
                cout<<"Our Submarine sunk!"<<endl;
              if(vict==18)
    {

        loss();
    }   
            }
            else
                cout<<"Our Submarine hit!"<<endl;
            break;
        }
        case 'B':
        {
            
            player[col][row]='H';
            B=aib(first);
            if(B==4)
            {
                cout<<"They sunk our battleship!"<<endl;
              if(vict==18)
    {
         
      
        loss();
    }   
            }
            else
                cout<<"Battleship hit!"<<endl;
            break;
            case 'C':
            {
               
                player[col][row]='H';
                C=CCount(first);
                
                if(C==5)
                {
                    cout<<"Carrier sunk!"<<endl;
                     if(vict==18)
    {
         
     
       loss();
    }
                }
                else
                    cout<<"Carrier hit!"<<endl;
                break;
            }
            case '_':
            {
                cout<<"Miss!"<<endl;
                player[col][row]='M';
                break;
            }
            case 'H':
            {
                cout<<"They already hit that target!!!"<<endl;
                break;
            }
        }
      
    

    
    }
}