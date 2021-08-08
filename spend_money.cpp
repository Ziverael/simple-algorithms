
//PREPROCESSING//
#include<iostream>
#include<limits>
#include<cstdlib>
#include<iomanip>
//#define denomination []{1,2,5,10,20,50,100,200,500,1000,2000,5000,10000,20000}//in bob 

//NAMESPACE//
using namespace std;

//VARIABLES//
const unsigned short denomination[14]={1,2,5,10,20,50,100,200,500,1000,2000,5000,10000,20000};//in bob

//FUNCTIONS: HEADERS//
unsigned short* spend(int value);
int* safeRead();
int zl2gr(float zl);

//BODY//
int main()
{ 
    int* ammount= safeRead();
    unsigned short* results=spend(*ammount);

    cout<<"Steps: "<<results[0]<<endl;
    for(char i=0;i<14;i++)
    cout<<setw(8)<<internal<<(float)(denomination[i])/100;
    cout<<endl;
    cout<<setw(8*14)<<setfill('-')<<'-'<<endl;
    cout<<endl;
    for(char i=0;i<14;i++)
    cout<<setw(8)<<setfill(' ')<<internal<<results[i+1];
    
    delete ammount;
    return 0;
}

//FUNCTIONS: BODIES//
int zl2gr(float zl)
{
    float buff=100*zl;
    return (int)buff; //Why return (int)(zl*100) doesn't work properly?
}

int* safeRead()
{
        float val=-1;
        while(val<0)
        {
            cout<<"Pass ammount in zloty:\n";
            while(!(cin>>val))
            {
                cerr<<"Invalid input! Pass positive number!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            if(val<0)cout<<"Ammount cannot be negative number!\n";
        }
        
        int outp=zl2gr(val);
        int* output=&outp;
        return output;
}

unsigned short* spend(int value)
//Output: Table with first value equal to steps number in algorithm and 14 buckets
//corespondind with denominals representing numbers of returned nominals
{
    char i=13;
    unsigned short* output=new unsigned short[15];
    for(char j=0;j<15;j++)output[j]=0;

    while(value>0)
    {
        while(value>=denomination[i])
        {
            value-=denomination[i];
            output[i+1]++;
            output[0]++;
        }
        i--;
    }
    return output;
}