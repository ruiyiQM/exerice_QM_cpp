#include "molecule.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>

Molecule::Molecule(const char *filename, int q)
{
  charge=q;
  std::ifstream is(filename);
  is>>natom;
  zvals=new int[natom];
  geom = new double*[natom];
  for (int i=0;i<natom;i++)
  {
    geom[i]=new double[3];
  }
  for (int i=0;i<natom;i++)
  {
    is>>zvals[i]>>geom[i][0]>>geom[i][1]>>geom[i][2];
  }
  is.close();

}
