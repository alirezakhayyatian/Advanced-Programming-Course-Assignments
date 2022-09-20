#include<iostream>
#include<cmath>
#include<iomanip>
#include "CGaussSolver.h"

using namespace std;

long double aFunction(const long double&);

int main(int argc, char* argv[]) {

  long double a{ 0 }, b{ 1 };
  int n{ atoi(argv[1])};
  //int n = 3;
  long double(*pf)(const long double&);
  pf = aFunction; // Pointer initialized
  CGaussSolver aSolver(pf, a, b, n);
  aSolver.exec(); // Calculate the integral
  cout.precision(20);
  cout << "Result of C++ code (n = "<< setw(2) << n << "): "<< aSolver.getResult() << endl;

  return 0;

}

long double aFunction(const long double& x){
  long double xN = 0.5 * x + 0.5;
  return (pow(xN, 3) / (xN + 1))*cos(pow(xN, 2));
}