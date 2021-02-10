#include"RECUSION.h"

//RECUSION---------------------------------------------------------------------------------------
// Find the total value of all integers that less than or equal to n: S = 1^2 + 2^2 + ... + n^2
int SumOfSquares(int n)            // S(n) = 1^2+....+(n-1)^2+n^2
{
	if(n == 0) return 0;
	if(n == 1) return 1;
	return (SumOfSquares((n-1))+n*n);
}
// Find the greatest common divisor of 2 integers a and b:
int GCD(int a, int b)                           // vd: a = 12, b =18: 18-12 = 6, xét tiep 6 va 12: 12-6 = 6; xet tiep 6 và 6-6 = 0(dk dung)    
{
	if(a == 0 || b == 0) return a+b;
	if(a>b)
		return GCD(a-b, b);
	else
		return GCD(b-a,a);           
	
}
//Find the n^th Fibonacci number using by the following formular: F(n) = F(n - 1) + F(n - 2).
int FIB (int n)
{
	if(n == 0) return 0;
	if(n == 1) return 1;
	return FIB(n-1) + FIB(n-2);
}

