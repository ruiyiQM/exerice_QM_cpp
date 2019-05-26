#include "Eigen/Dense"
#include "Eigen/Eigenvalues"
#include "Eigen/Core"
#include "iostream"
using namespace std;
using namespace Eigen;


typedef Matrix<double, Dynamic, Dynamic,RowMajor> MatrixI;
extern "C" {
   void *dot(double *A,double *B,double *C,int size_m,int size_n, int size_l);
}
void *dot(double *A,double *B,double *C,int size_m,int size_n, int size_l)
{
  Map<MatrixI>( C, size_m, size_l)=Map<MatrixI>( A, size_m, size_n)*Map<MatrixI>( B, size_n, size_l);
}
