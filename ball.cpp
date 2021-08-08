//
//MACROS//
#include<iostream>
#include<iomanip>
#include<limits>
#include<ctime>
#include<cstdlib>
#include<windows.h>

#define INPUTERR {  cerr<<"Wrong input";\
                    cin.clear();\
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');}
#define CLS (cout<<"\033[2J")
#define LOCATE(x,y) (cout<<"\033["<<y<<';'<<x<<'H')

//NAMESPACE//
using namespace std;

//FUNCTIONS HEADERS//
void move(int* pos,int* vel);

//BODY//
int main()
{

    string floor(79, '-'), header("JUMPING BALL");

    srand((unsigned)time(NULL));
    int position[]={rand()%78+1,rand()%24+1};
    int speed[]={rand()<0.5 ? 1:-1,1};
    
    
    CLS;
    LOCATE(25,1);   cout<<header;
    LOCATE(1,25);   cout<<floor ;

    while(true)move(position,speed);

    return 0;
}

//FUNCTIONS BODIES//
void move(int* pos,int* vel)
{
    LOCATE(pos[0],pos[1]);    cout<<'o'<<endl;
    Sleep(250);

    if(pos[0]<=1||pos[0]>=79)vel[0]=-vel[0];
    if(pos[1]>=19)
    {
        vel[1]=-vel[1];
        if(!vel[1])vel[1]=-7;
    }
    vel[1]+=1;

    LOCATE(pos[0],pos[1]);    cout<<' ';
    pos[0]+=vel[0];
    pos[1]+=vel[1];
}
