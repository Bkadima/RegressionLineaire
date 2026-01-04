<<<<<<< HEAD
#ifndef RegressionLineaire_h
#define RegressionLineaire_h

double prediction(double x, double a, double b);
double fonctionCout(const double *X,const double *Y, int m, double a, double b);
void gradients(const double *X,const double *Y, int m, double a, double b, double *da, double *db);
void MAJ(double *a, double *b, double da, double db, double alpha );
void test(const double *X,const double *Y, int m, double *a, double *b, double alpha, int nb);

=======
#ifndef RegressionLineaire_h
#define RegressionLineaire_h

double prediction(double x, double a, double b);
double fonctionCout(const double *X,const double *Y, int m, double a, double b);
void gradients(const double *X,const double *Y, int m, double a, double b, double *da, double *db);
void MAJ(double *a, double *b, double da, double db, double alpha );
void test(const double *X,const double *Y, int m, double *a, double *b, double alpha, int nb);

>>>>>>> 509ea09ef4d39942801ac79255abba91eb8369d1
#endif