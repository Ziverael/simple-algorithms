//PREPROCESSING//
#include<iostream>
#include<limits>
#include<iomanip>

//FUNCTIONS HEADERS//
short* readSize();
void drawTable(unsigned short sizev,unsigned short sizeh);

//BODY//
int main()
{
    short* borders=readSize();
    drawTable(borders[0],borders[1]);
    delete [] borders;
    return 0;
}

//FUNCTIONS BODIES//
short* readSize()
{
    short* output=new short[2];
    char i=0;
    while(i<2)
    {
        output[i]=0;
        while(output[i]<=0)
        {
            std::cout<<"Enter "<<i+1<<". parameter:";
            if(!(std::cin>>output[i]))
            {
                std::cerr<<"Invalid input! Pass natural number."<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
            else if(output[i]<=0)std::cerr<<"Invalid input! Pass natural number."<<std::endl;
        }
        i++;
    }
    return output;
}

void drawTable(unsigned short sizev,unsigned short sizeh)
{
    std::cout<<std::endl;
    short i,j;
    for(i=0;i<sizev;i++)
    {    
        for(j=0;j<sizeh;j++)std::cout<<std::setw(5)<<std::internal<<(i+1)*(j+1)<<"\t ";
        std::cout<<std::endl;
    }
}