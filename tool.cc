#include <stdio.h>
#include "tool.h"
#include "math.h"
#include <iostream>

using namespace std;
double dot_product(double* a, double* b)
{
  double result=0;
  for (int i=0;i<3;i++)
  {
    result+=a[i]*b[i];
  }
  return result;
}
void cross_product(double* a,double* b,double* c)
{
  c[0]= a[1]*b[2]-a[2]*b[1];
  c[1]= -a[0]*b[2]+a[2]*b[0];
  c[2]= a[0]*b[1]-a[1]*b[0];
}
