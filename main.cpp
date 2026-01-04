#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "RegressionLineaire.h"
using namespace std;

int main(){
    string fic;
    cout<< "Nom du fichier: ";
    cin>>fic;
    ifstream file(fic);
    if(!file.is_open()){
        cout<<"Erreur fichier introuvable";
        return 0;
    }
    int m=0;
    string line;
    while(getline(file, line)) m++;
    file.clear();
    file.seekg(0);

    double *X=new double[m];
    double *Y=new double[m];
    int x=0;
    while(getline(file, line)){
        stringstream ss(line);
        string x_str, y_str;
        if(!getline(ss, x_str, ',')) continue;
        if(!getline(ss, y_str, ',')) continue;

        X[x]=stod(x_str);
        Y[x]=stod(y_str);
        x++;
    }
    file.close();

    double a =0.0, b=0.0, alpha=0.001, nb=20000;
    
    test(X, Y, m, &a, &b, alpha, nb);
    cout<< "Pret! " << "a= "<< a<< " b: "<< b<< endl;
    
    char yn='y';
    while(yn=='y' || yn=='Y'){
        double test;
        cout<< "Entrer un X pour predire Y: ";
        cin>>test;
        double res=prediction(test, a, b);
        cout<<" Y predit est: "<< res<< endl;
        cout<< "Nouveau test? (Y oui)";
        cin>> yn;
    }
    
    delete[] X;
    delete[] Y;
    
    return 0;

    
}