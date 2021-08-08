/*
Average by Ziverael
--------------------
Simple code containing only basic structures of cpp
Program can get unlimited number of arguments without using vectors, because of simple
math properties
*/

//PREPROCESSING//
#include <iostream>
#define maxCapacity 4

using namespace std;

//FUNCTIONS HEADERS//
double averege(double* tab, unsigned int number);
double sum(double* tab,unsigned int number);

//BODY//
int main()
{
    unsigned int i=0,total=0;
    double* vars=new double[maxCapacity];

    cout<<"Pass numbers\nTo break pass none number value.";

    while(cin>>vars[i])
    {
        i++;
        if(i>=maxCapacity)
        {
        vars[0]=sum(vars,maxCapacity);
        total+=maxCapacity-1;
        i=1;
        }
    }
    total+=i;

    if(!total) cout<<"Averege value: "<<0;
    else       cout<<"Averege value: "<<showpos<<averege(vars,total);
    delete [] vars;

    return 0;
}


//FUNCTIONS BODIES//
double sum(double* tab,unsigned int number)
{
    unsigned int i=0;
    double output=0;
    
    while(i<number)
    {
        output+=tab[i];
        i++;
    }
    return output;
}

double averege(double* tab, unsigned int number)
{
    if(number%maxCapacity)
    {
        double output=0;
        unsigned int i=0;
        unsigned int cond;

        if(number>=maxCapacity)cond=(number+1)%maxCapacity;
        else cond=number%maxCapacity;
        
        while(i<cond)
            {
                output+=tab[i];
                i++;
            }
        return output/number;
    }
    else    return tab[0]/number;
    
}
