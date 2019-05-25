#include "molecule.h"
#include "iostream"
#include "fstream"
#include <cstdio>
#include <cassert>
#include "mass.h"
using namespace std;
int main(int argc, char const *argv[]) {
  Molecule C6H6("benzene.xyz",0);
  for (int i=0;i<C6H6.natom;i++)
  {
    for (int j=0;j<i;j++)
    {
      std::cout<<"atom\t"<<i<<"\t"<<j<<"\t"<<C6H6.bond(i,j)<<endl;
    }
  }


  for (int i=0;i<C6H6.natom;i++)
  {
    for (int j=0;j<i;j++)
    {
      for(int k=0;k<j;k++)
      {
        double Rij=C6H6.bond(i,j);
        double Rjk=C6H6.bond(j,k);
        if (Rij<4.0&&Rjk<4.0)
        {
          cout<<"atom\t"<<i<<'\t'<<j<<'\t'<<k<<'\t'<<C6H6.angle(i,j,k)<<endl;
        }
      }
    }
  }


  for (int i=0;i<C6H6.natom;i++)
  {
    for (int j=0;j<C6H6.natom;j++)
    {
      for (int k=0;k<C6H6.natom;k++)
      {
        for (int l=0;l<C6H6.natom;l++)
        {
          if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l)
          {
            double Rik=C6H6.bond(i,k);
            double Rkj=C6H6.bond(k,j);
            double Rkl=C6H6.bond(k,l);
            if(Rik < 4.0 && Rkj < 4.0 && Rkl < 4.0)
            {
              cout<<"atom\t"<<i<<'\t'<<j<<'\t'<<k<<'\t'<<l<<"\t"<<C6H6.oop(i,j,k,l)<<endl;
            }
          }
        }
      }
    }
  }


  for (int i=0;i<C6H6.natom;i++)
  {
    for (int j=0;j<i;j++)
    {
      for (int k=0;k<j;k++)
      {
        for (int l=0;l<k;l++)
        {
          double Rij=C6H6.bond(i,j);
          double Rjk=C6H6.bond(j,k);
          double Rkl=C6H6.bond(k,l);
          if(Rij < 4.0 && Rjk < 4.0 && Rkl < 4.0)
          {
            cout<<"atom\t"<<i<<'\t'<<j<<'\t'<<k<<'\t'<<l<<"\t"<<C6H6.torsion(i,j,k,l)<<endl;
          }
        }
      }
    }
  }

  double COM[3];
  double mx[3],m[3];
  for (int i=0;i<C6H6.natom;i++)
  {
    for (int j=0;j<3;j++)
    {
      mx[j]+=masses[int(C6H6.zvals[i])]*C6H6.geom[i][j];
      mx[j]+=masses[int(C6H6.zvals[i])];
    }
  }
  for (int i=0;i<3;i++)
  {
    COM[i]=mx[i]/m[i];
  }
  return 0;
}
