#ifndef RLMultiple_h
#define RLMultiple_h
double prediction(double *X, double *coef,double b, int m);
double fonctionCout(const double *X, const double *Y, int m, int n, const double *A, double b);
void gradients(const double *X,const double *Y, int m, int n, double *A, double *b, double *dA, double *db);
void MAJ(double *A, double *b, double *dA, double db, double alpha ,int n);
void test(const double *X, const double *Y, int m, int n, double *A, double *b, double alpha, int nb);
#endif