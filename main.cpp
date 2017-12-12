/* 
 * File:   main.cpp
 * Author: Marcus Burton
 * Created on December 11th 10:32PM
 * Purpose:  Battleship!
 */

//System Libraries Here
#include <iostream>
#include <cstdlib> //random generator
#include <time.h> // for random
using namespace std;

 
//User Libraries Here

//Global Constants Only, No Global Variables
 // COL, ROW
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void mkegrid(char[][10]);
void dsplygd(char[][10]);
void player(char[][10]);
void victory();
void loss();
void aiShips();
int disp();
void plceshp(char[][10],char, int,int,int);
int check(char[][10],int,int,int);
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
 cout<<"BATTLESHIP"<<endl;;
    
    
    
    char name = '_';
 char grid[10][10];
 
    char board[10][10];
    char plays[10][10];
     // to check and stuff
    mkegrid(grid);
    mkegrid(plays);
    mkegrid(board);
    
    //All the ships for the AI
    plceshp(grid,'C',5,4,2);
    plceshp(grid,'B',4,4,3);
    plceshp(grid,'S',3,7,1);
    plceshp(grid,'D',2,8,1);
    plceshp(grid,'c',3,7,1);
    
    play(grid,board,plays);
    
  
        
    
   
   
    return 0;
}

void mkegrid(char grid[][10])
{
     for(int row=0;row<=10;row++) //loop for rows
    {
        for(int col=0;col<=10;col++) //loop for columns
        {
            
            grid[col][row]='_';
            
        }
    }
}

void dsplygd(char grid[][10])
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


void plceshp(char grid[][10],char name, int size,int limitm,int limitL)
{
    srand (time(NULL));
    int place1=0;
    int place2=0;
    int dis = disp(); // checks which axis the ship will take
    int place=1;
    do
    {
             place1=(rand()%limitm)+limitL; // between the min and max limit of the ship
             place2=(rand()%limitm)+limitL;
            place=check(grid,place2,place1,dis);
    }while(place==1);
    if(dis>=25) // checking the iteration
    {
    for(int i = 0; i <size;i++)
    {
        
        grid[place1][place2+i]=name;//vertical
        
    }
    }
    else
    {
     for(int i = 0;i<size;i++)
     {
         grid[place1+i][place2]=name; // horizontal
     }
   
}
}


int disp()
{
 int xory=0;
 xory=rand()%50;//random number between 0 and 50 to make the odds a little better
 return xory;
}

int check(char grid[][10],int r, int c, int disp)
{
    char check;
    if(disp>25) // vertical
    {
        // checks all the vertical sides
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
        // checks all the horizontal sides
        for(int i=r;i<10;i++)
        {
            check=grid[i][r];
            if(check!='_')
                return 1;
        }
        return 0;
    }
    
}
int hit(char grid[][10],char name) // checking for a hit.
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

    
    
// Checks for a win. if 17 positions are hit that occupy ships, the user wins
int win(int A)
{
    static int W=A;
    W++;
    return W;
}   
// the following 6 programs count how many times the enemy ship type was hit
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
// The same as above, except for the AI
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
//Firing at the enemy ship
// one of the arrays is for diagnostics, to make sure everything ran fine
void fire(char grid[][10],char board[][10],int col, int row)
{
    int first=0;
    int vict; // declare variables that will be sent to other functions
    int D,c,S,B,C;
    char name=grid[col][row];
    if(name!='_'&&name!='H'&&name!='M')
    {
        vict=win(first); // if a ship is hit, points get added to the users win
    cout<<"Game counter in fire function "<<vict<<endl;
    }
    
   
    switch(name)
    {
   
        case 'D':
        
    {
            grid[col][row]='H';
            board[col][row]='H';
            // again, grid is for diagnostics
            
           
            D=Dcount(first);
            cout<<D<<endl;
            
            if(D==2)
            {
                cout<<"Destroyer sunk!"<<endl;
                 if(vict==17)
    {
         
        victory(); // display victory message if all ships are killed
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
                 if(vict==17)
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
              if(vict==17)
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
              if(vict==17)
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
                     if(vict==17)
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
// the function that plays the actual game. it calls other functions mainly
void play(char grid[][10],char board[][10],char play[][10])
{
    int col,row;
    bool game=true;
    // the user places their ships
    cout<<"First, place down your positions onto the board!"<<endl;
    player(play);
      
    do
    {
      // This loop goes through the game until a victor is chosen.
        // the game value doesn't change on purpose
     dsplygd(grid);
     dsplygd(board);
        cout<<"Where would you like to fire! Enter the Column, then the row"<<endl;
    cin>>col;
    cin>>row;
     fire(grid,board,col,row);
     cout<<"Now the AI shall take their shot!"<<endl;
     dsplygd(play);
     ai(play);
     
     
      
      
    }while(game);
}

void victory()
{
    // and here is your generic victory message
    cout<<"You have vanquished your enemies! Congratulations!"<<endl;
    exit(EXIT_SUCCESS);
}
void loss()
{
    //Generic loss message
    cout<<"You have lost! better luck next time!"<<endl;
    exit(EXIT_SUCCESS);
}

void player(char player[][10])
{
    cout<<"Now you shall create your board!"<<endl;
    int choice,col,row;
    int counter=0;
    
    // Loop goes through every ship(There's five);
    while(counter<5)
    {
        for(int i =0;i<2;i++) // several for loops go through the ship sizes and place the markers down, changing the grid for the AI.
        {
            dsplygd(player);
            cout<<"Please enter position "<<i+1<<" for your DESTROYER"<<endl;
            cout<<"Column, then row, and then again"<<endl;
            cin>>col;
            cin>>row;
            player[col][row]='D';
            
                    
            
        }
        counter++;
        dsplygd(player);
        for(int i = 0;i<3;i++)
        {
            cout<<"Please enter position "<<i+1<<" for your SUB. same as before!"<<endl;
            cin>>col;
            cin>>row;
            player[col][row]='S';
            dsplygd(player);
            
        }
        counter++;
        for(int i=0;i<3;i++)
        {
            cout<<"Please enter position"<<i+1<<" for your cruiser"<<endl;
            cin>>col;
            cin>>row;
            player[col][row]='c';
            dsplygd(player);
            
                    
        }
        counter++;
        for(int i=0;i<4;i++)
        {
            cout<<"Please enter position "<<i+1<<" for your BATTLESHIP!"<<endl;
            cin>>col;
            cin>>row;
            player[col][row]='B';
            dsplygd(player);
        }
        counter++;
        for(int i=0;i<5;i++)
        {
            cout<<"Please enter position "<<i+1<<" for your CARRIER!"<<endl;
            cin>>col;
            cin>>row;
            player[col][row]='C';
            dsplygd(player);
        }
        counter++;
            
    }
    
   
}

void ai(char player[][10]) // this function is the AI attacking the players ships
{
    int col = rand()%10; // first declare the locations on the function
    int row=rand()%10;
    int first=0;
    int vict;
    int D,c,S,B,C;
    char name=player[col][row];// calls the name of the ship on the locale, or it can be a miss or a re-hit.
    
    do
    {
        col=rand()%10;
        row=rand()%10;
        
    }while(player[col][row]=='H'||player[col][row]=='M'||player[col][row]!='_');
    //Obviously any player wouldn't hit the same place twice, so I threw in this logic that makes the computer not make that mistake, to make the game more challenging.
   if(name!='_'&&name!='H'&&name!='M')
    {
        vict=awin(first); // every time a hit lands, the counter goes up. Max being 18.
    cout<<"Game counter in fire function "<<vict<<endl;
    }
    switch(name)
    {
   // same loop as for the player, but situated for the AI's function counters.
        case 'D':
        
    {
            
            player[col][row]='H';
            
           
            D=aid(first);
            cout<<D<<endl;
            
            if(D==2)
            {
                cout<<"Our Destroyer was sunk!"<<endl;
                 if(vict==17)
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
                 if(vict==17)
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
              if(vict==17)
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
              if(vict==17)
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
                     if(vict==17)
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

/**
 * 
 * End program. Hope it was decent, I had a lot of fun with this,
 * and have never been so challenged in my meagre life.
 
 */
