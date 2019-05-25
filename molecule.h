/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<string>
using namespace std;

class Molecule
{
  public:
    int natom;
    int charge;
    int *zvals;
    double **geom;
    string point_group;

    void print_geom();
    void rotate(double phi);
    void translate(double x,double y,double z);
    double bond (int atom1,int atom2);
    double angle (int atom1,int atom2, int atom3);
    double torsion (int atom1, int atom2,int atom3,int atom4);
    double oop(int atom1, int atom2,int atom3,int atom4);
    Molecule(const char *filename, int q);
    ~Molecule();
};
