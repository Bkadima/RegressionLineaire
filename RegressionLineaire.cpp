#include <iostream>

using namespace std;

/*
    Prediction du modele 
*/
double prediction(double x, double a, double b){
    return a*x+b;
}
/*
    Calcul du cout (Main Squared Error)
*/
double fonctionCout(const double *X,const double *Y, int m, double a, double b){
    double cout=0.0;
    for (int i=0; i<m; i++){
        double y= a*X[i]+b;
        double er= y-Y[i];
        cout+=er*er;
    }

    return cout / (2.0 * m);
}

/*
    calcul des gradients
*/
void gradients(const double *X,const double *Y, int m, double a, double b, double *da, double *db){
    double tota =0.0;
    double totb=0.0;

    for(int i=0; i<m; i++){
        double y= a*X[i]+b;
        double er= y-Y[i];

        tota+=er*X[i];
        totb+=er;
    }

    *da=tota/m;
    *db=totb/m;
}
/*
    Mise a Jour des parametres
*/
void MAJ(double *a, double *b, double da, double db, double alpha ){
    *a-=alpha*da;
    *b-=alpha*db;
}
/*
    Entrainement du model 
*/
void test(const double *X, const double *Y, int m, double *a, double *b, double alpha, int nb){
    for(int i=0; i<nb; i++){
        double da=0.0;
        double db=0.0;

        gradients(X,Y,m,*a, *b, &da, &db);
        MAJ(a,b,da,db, alpha);

        
    }
}

