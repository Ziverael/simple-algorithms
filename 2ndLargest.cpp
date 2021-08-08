
//PREPROCESSING//
#include<iostream>
#include<limits>

//FUNCTIONS HEADERS//
unsigned int safeRead();
double* readVals(unsigned int times);
double* findMax(double* tab,unsigned int range);

//BODY//
int main()
{
    unsigned int i;
    unsigned int sizeVal=safeRead();
    double* vals=readVals(sizeVal);
    double* maxValNPos=findMax(vals,sizeVal);

    std::swap(vals[(unsigned int)maxValNPos[1]],vals[sizeVal-1]);
    double* _2ndMax=findMax(vals,sizeVal-1);
    
    std::cout<<"The 2nd largest is: "<<_2ndMax[0];
    
    delete [] vals;
    delete [] maxValNPos;
    
    return 0;
}


//FUNCTIONS: BODIES//
unsigned int safeRead()
{
        int output=-1;
        while(output<0)
        {
            std::cout<<"Pass positive number!\n";
            while(!(std::cin>>output))
            {
                std::cerr<<"Invalid input! Pass positive number!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
            if(output<0)std::cout<<"Invalid input! ";
        }
        return output;
}

double* readVals(unsigned int times)
{
    unsigned int i=0;
    double* output=new double[times];
    
    while(i<times)
    {
        std::cout<<"Enter "<<i+1<<". real number :";
        if(std::cin>>output[i])i++;
        else
        {
            std::cerr<<"Invalid value! Pass floating-point value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    return output;
}

double* findMax(double* tab,unsigned int range)
{
    double* maxVal=new double[2];
    maxVal[0]=tab[0];
    maxVal[1]=0;

      for(unsigned int i=0;i<range;i++)
        if(maxVal[0]<tab[i])
        {
            maxVal[0]=tab[i];
            maxVal[1]=i;
        }
    return maxVal;
}
