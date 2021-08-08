//PREPROCESSING//
#include<iostream>

//NAMESPACE//
using namespace std;

//FUNCTIONS HEADERS//
unsigned int factorial(unsigned int n);
float power(float base, int index);
float power_triv(float base, int index);
int abs(int var);
int sgn(int var);

//BODY//
int main()
{
  cout<<"fac: "<<factorial(6)<<endl;
  cout<<"pow: "<<power(2,-3);
  return 0;

}

//FUNCTIONS BODIES//
int abs(int var)
{
  return var>=0 ? var : var*(-1);
}

int sgn(int var)
{
  return var>=0 ? 1: -1;
}

unsigned int factorial(unsigned int n)
{
  return n==0 ? 1 : n*factorial(n-1);
}

float power(float base, int index)
{
  return index<0 ? power_triv(1/base,abs(index)) : power_triv(base,index);
}

float power_triv(float base, int index)
{
  return index==1 ? base : base*power_triv(base,index-1);
}