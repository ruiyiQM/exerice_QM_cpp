#include "Eigen/Dense"
#include "Eigen/Eigenvalues"
#include "Eigen/Core"
#include "iostream"
#include "omp.h"
using namespace std;
using namespace Eigen;


typedef Matrix<double, Dynamic, Dynamic,RowMajor> MatrixI;
extern "C" {
   void *dot(double *A,double *B,double *C,int size_m,int size_n, int size_l);
   void *peig(double **A, int *size, int length, double **eig_value, double **eig_vector);
}
void *dot(double *A,double *B,double *C,int size_m,int size_n, int size_l)
{
  Map<MatrixI>( C, size_m, size_l)=Map<MatrixI>( A, size_m, size_n)*Map<MatrixI>( B, size_n, size_l);
}
void *peig(double **A, int *size, int length, double **eig_value, double **eig_vector)
{
  #pragma omp parallel
  {
    int nthreads, tid;
    tid = omp_get_thread_num();
    nthreads = omp_get_num_threads();
    #pragma omp for schedule(dynamic,nthreads)
    for (int i=0;i<length;i++)
    {
       SelfAdjointEigenSolver<MatrixI> es(Map<MatrixI>( A[i],size[i],size[i]));

       if (es.info() != Success) abort();

       Map<MatrixI>(eig_value[i],size[i],1)=es.eigenvalues();
       Map<MatrixI>( eig_vector[i],size[i], size[i])=es.eigenvectors();
    }
  }
}
void *test_eig(double *A, int size, int length, double *eig_value, double *eig_vector)
{
    SelfAdjointEigenSolver<MatrixI> es(Map<MatrixI>( A,size,size));
    if (es.info() != Success) abort();
    Map<MatrixI>(eig_value,size,1)=es.eigenvalues();
    Map<MatrixI>( eig_vector,size, size)=es.eigenvectors();

}
