#pragma once
class CGaussSolver
{
	public:
		CGaussSolver(long double(*pf)(const long double&), long double a, long double b, int n);
		void exec(void);
		long double getResult();

	private:
		long double(*m_Pf)(const long double&);
		long double m_A, m_B;
		int m_N;
		long double m_Result;

		long double legendre(int, long double );
		long double dLegendre(int, long double );
		long double legendreZeroes(int, int );
		long double weight(int, long double );
	};
