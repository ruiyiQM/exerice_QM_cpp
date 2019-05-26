/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "molecule.h"
#include "math.h"
#include "tool.h"
const double pi  =3.141592653589793238463;
void Molecule::print_geom()
{
    for (int i=0; i<natom; i++)
       printf("%d %8.5f %8.5f %8.5f\n", zvals[i],geom[i][0],geom[i][1],geom[i][2]);
}
void Molecule::translate(double x,double y,double z)
{
  for (int i=0;i<natom;i++)
  {
      geom[i][0] +=x;
      geom[i][1] +=y;
      geom[i][2] +=z;

  }
}

Molecule::~Molecule()
 {
   delete[] zvals;
   for (int i=0;i<natom;i++)
   {
     delete[] geom[i];
   }
   delete geom;
 }

double Molecule::bond(int atom1,int atom2)
{
  double length,distance;
  double diff[3];
  for (int i=0;i<3;i++)
  {
    diff[i]= geom[atom1][i]-geom[atom2][i];


  }
  distance=dot_product(diff,diff);
  length=pow(distance,0.5);
  return length;
}


double Molecule::angle(int atom1,int atom2, int atom3)
{
  double Rij,Rjk;
  Rij=bond(atom1,atom2);
  Rjk=bond(atom2,atom3);
  double eij[3];
  double ejk[3];
  for (int i=0;i<3;i++)
  {
    eij[i]=-1*(geom[atom1][i]-geom[atom2][i])/Rij;
    ejk[i]=-1*(geom[atom2][i]-geom[atom3][i])/Rjk;
  }
  double cos_value=-dot_product(eij,ejk);
  return acos(cos_value)/pi*180;
}
double Molecule::oop (int atom1, int atom2,int atom3,int atom4)
{
  double Rkj,Rkl,Rki;
  Rkj=bond(atom1,atom2);
  Rkl=bond(atom2,atom3);
  Rki=bond(atom4,atom1);
  double ekj[3],ekl[3],eki[3];
  for (int i=0;i<3;i++)
  {
    ekj[i]-=(geom[atom3][i]-geom[atom2][i])/Rkj;
    ekl[i]-=(geom[atom3][i]-geom[atom4][i])/Rkl;
    eki[i]-=(geom[atom3][i]-geom[atom1][i])/Rki;
  }
  double cross_vecotr[3];
  cross_product(ekl,ekl,cross_vecotr);
  double inner;
  inner =angle(atom2,atom3,atom4);
  double result=dot_product(eki,cross_vecotr);
  result = result/sin(inner/180*pi);
  result = asin(result)/pi*180;
  return result;
}

double Molecule::torsion(int atom1,int atom2,int atom3,int atom4)
{
  double Rij,Rjk,Rkl;
  double eij[3],ejk[3],ekl[3];
  Rij =bond(atom1,atom2);
  Rjk =bond(atom2,atom3);
  Rkl =bond(atom3,atom4);
  for (int i=0;i<3;i++)
  {
    eij[i]=-1*(geom[atom1][i]-geom[atom2][i])/Rij;
    ejk[i]=-1*(geom[atom2][i]-geom[atom3][i])/Rjk;
    ekl[i]=-1*(geom[atom3][i]-geom[atom4][i])/Rkl;
  }
  double inner1,inner2;
  inner1=sin(angle(atom1,atom2,atom3)/180*pi);
  inner2=sin(angle(atom2,atom3,atom4)/180*pi);
  double cross1[3],cross2[3];
  cross_product(eij,ejk,cross1);
  cross_product(ejk,ekl,cross2);
  double result1=dot_product(cross1,cross2);
  double result2=result1/inner1/inner2;
  if (result2>0)
  {
    double tor;
    tor = acos(result2)/pi*180;
    return tor;
  }

  else
  {
    double tor;
    tor = -1*acos(-1*result2)/pi*180;
    return tor;
  }
}
