#include "Eigen/Dense"
#include "Eigen/Eigenvalues"
#include "Eigen/Core"

void *dot(double *A,double *B,double *C,int size_m,int size_n, int size_l);
void peig(double *A, int *size, int length, double *eig_value, double * eig_vector);
