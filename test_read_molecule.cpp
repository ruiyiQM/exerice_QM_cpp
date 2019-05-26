#include "molecule.h"
#include "Eigen/Dense"
using namespace std;

int main(int argc, char const *argv[]) {
  Molecule C6H6("benzene.xyz",0);
  C6H6.print_geom();
  C6H6.translate(5,0,0);
  C6H6.print_geom();
  C6H6.~Molecule();
  return 0;
}
