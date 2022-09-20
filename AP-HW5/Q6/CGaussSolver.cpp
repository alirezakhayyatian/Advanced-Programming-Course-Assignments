#include "CGaussSolver.h"
#include<math.h>
#include<iostream>
using namespace std;

CGaussSolver::CGaussSolver(long double(*pf)(const long double& x), long double a, long double b, int n):
  m_Pf(pf), m_A(a), m_B(b), m_N(n)
{

}

long double CGaussSolver::legendre(int m_N, long double x){
  if (m_N == 0)
    return 1;
  else if (m_N == 1)
    return x;
  else
    return ((2.0 * m_N - 1) / m_N) * x * legendre(m_N - 1, x) - ((1.0 * m_N - 1) / m_N) * legendre(m_N - 2, x);
}

long double CGaussSolver::dLegendre(int m_N, long double x){
  long double dLegendre{};
  dLegendre = (1.0 * m_N / (x * x - 1)) * ((x * legendre(m_N, x)) - legendre(m_N - 1, x));
  return dLegendre;

}

long double CGaussSolver::legendreZeroes(int m_N, int i){
  long double xnew1{}, xold1{};
  long double pi = 3.141592655;
  xold1 = cos(pi * (i - 1 / 4.0) / (m_N + 1 / 2.0));
  int iteration{ 1 };

  do {
    if (iteration != 1)
      xold1 = xnew1;
    xnew1 = xold1 - legendre(m_N, xold1) / dLegendre(m_N, xold1);
    iteration++;
  } while (1 + fabs((xnew1 - xold1)) > 1.);
  return xnew1;

}

long double CGaussSolver::weight(int m_N, long double x){
  long double weightI{};
  weightI = 2 / ((1 - pow(x, 2)) * pow(dLegendre(m_N, x), 2));
  return weightI;

}

void  CGaussSolver::exec(void){
  long double integral{ 0 };
  int iteration{ 1 };
  iteration++;
  integral = 0;
  //n++;
  for (int i{ 1 }; i <= m_N; i++)
    integral = integral + m_Pf(legendreZeroes(m_N, i)) * weight(m_N, legendreZeroes(m_N, i));

  m_Result = ((m_B - m_A) / 2.0) * integral;

}

long double CGaussSolver:: getResult(void){
  return m_Result;
}