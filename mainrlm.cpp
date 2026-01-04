#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "RLMultiple.h"
using namespace std;

int main(){
   double X[60]={0.0,1.0,-1.0,0.5,-0.5,-4.5,10.0,-5.0,-3.0,5.0,-10.0,60.0,3.33,0.8,-1.245,7.8,-0.999999,5.5555,2.783,-999,0.0,0.555555,6.843,-2.431,7.99999,-19.0,-0.64,9.89999,7.0,0.333333,4.0,-3.333,1.0,-1.0,0.5,-0.5,-4.5,10.0,-5.0,-3.0,0.0,1.0,-1.0,0.5,-0.5,7.432,0.789,-3.21,9.9999,0.564,6.006,3.333333,0.2,1.704,-8.0,-4.5,10.0,-5.0,-3.0,5.0};
   double Y[20];
   for (int i=0; i<20;i++){
    Y[i]=(3*X[i])-(2*X[i+20])+X[i+40];
   }
   int m=20;
   int n=3;
   double A[3];
   for (int i=0; i<3; i++){
    A[i]=0.0;
   }
   double b=0.0;
   double alpha=0.000001;
   int nb=100000;

   test(X,Y,m,n,A,&b,alpha,nb);
   cout<< "Pret"<<endl;
   for(int i=0;i<3;i++){
    cout<< 'A'<<i+1<<"= "<< A[i]<<endl;
   }
   cout<< "b= "<< b<< endl;

}