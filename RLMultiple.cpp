#include <iostream>

using namespace std;

double prediction(double *X, double *coef,double b, int m){
    double tot=0.0;
    for(int i=0; i<m;i++){
        tot+=X[i]*coef[i];
    }
    return tot+b;
}
/*
Calcul du cout MSE
const double *X: m X n
const double *Y: m
int m: Nb d'observations
int n: Dimension
double *A: Coef des X
double b: coef independant x^0
    
*/
double fonctionCout(const double *X, const double *Y, int m, int n, const double *A, double b){
    double cout=0.0;
    for(int i=0; i<m; i++){
        double y=b;
        for(int j=0; j<n ; j++){
            y+=A[j]*X[i+j*m];
        }
        double er=y-Y[i];
        cout+=er*er;
    }
    return cout/(2.0*m);
}

void gradients(const double *X,const double *Y, int m, int n, double *A, double *b, double *dA, double *db){
    double tota[n];
    for(int i=0; i<n; i++){
        tota[i]=0.0;
    }
    double totb=0.0;
    for(int i=0; i<m; i++){
        double y=*b;
        
        for(int j=0; j<n ; j++){
            y+=A[j]*X[i+j*m];
        }
        double er=y-Y[i];
        for(int j=0; j<n;j++){
            tota[j]+=er*X[i+j*m];
        }
        totb+=er;
        
    }
    *db=totb/m;
    for(int i=0; i<n; i++){
        dA[i]=tota[i]/m;
    }

    
}

/*
    Mise a Jour des parametres
*/

void MAJ(double *A, double *b, double *dA, double db, double alpha ,int n){
    for(int i=0; i<n; i++){
        A[i]-=alpha*dA[i];
    }
    *b-=alpha*db;
}



void test(const double *X, const double *Y, int m, int n, double *A, double *b, double alpha, int nb){
    for(int i=0; i<nb; i++){
        double dA[n];
        for(int i=0; i<n; i++){
            dA[i]=0.0;
        }
        double db=0.0;

        gradients(X,Y,m,n,A,b,dA,&db);
        MAJ(A,b,dA,db,alpha,n);

    }
}