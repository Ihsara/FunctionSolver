/*
#include <stdio.h>
#include "FractionType.h"




int gcd(int , int );
int lcd(int , int );
Fraction FractionInput(char Msg[100]);
Fraction fReduce(Fraction );
Fraction Add(Fraction , Fraction );
Fraction Subtract(Fraction , Fraction );
Fraction Mul(Fraction , Fraction );
Fraction Div(Fraction , Fraction );
Fraction Pow(Fraction , int);


//gcd function - return gcd of two numbers
//http://snipplr.com/view/42917/

int gcd(int n, int m){
	int gcd, remainder;
	while (n != 0)
	{
		remainder = m % n;
		m = n;
		n = remainder;
	}
	gcd = m;
	return gcd;
}//end gcd function

int lcd(int n, int m) {
	return n*m / gcd(n, m);
}

Fraction FractionInput(char Msg[100]) {
	Fraction Frac;
	printf("%s", Msg);
	scanf("%d/%d", &Frac.numerator, &Frac.denominator);
	return Frac;
}

Fraction fReduce(Fraction a) {
	a.numerator = a.numerator / gcd(a.numerator, a.denominator);
	a.denominator = a.denominator / gcd(a.numerator, a.denominator);
	return a;
}

//Ideas for these following functions from: http://stackoverflow.com/questions/33887484/c-fraction-arithmetic
//Basic Operations for functions with both numerator and denominator are int data type

Fraction fAdd(Fraction a, Fraction b) {
	Fraction sum;
	sum.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
	sum.denominator = a.denominator * b.denominator;
	return (fReduce(sum));
}

Fraction fSubtract(Fraction a, Fraction b) {
	Fraction offsets;
	offsets.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
	offsets.denominator = a.denominator * b.denominator;
	return (fReduce(offsets));
}

Fraction fMul(Fraction a, Fraction b) {
	Fraction pro;
	pro.numerator = a.numerator*b.numerator;
	pro.denominator = a.numerator*b.denominator;
	return fReduce(pro);
}

Fraction fDiv(Fraction a, Fraction b) {
	Fraction quot;
	quot.numerator = a.numerator*b.denominator;
	quot.denominator = a.denominator*b.denominator;
	return fReduce(quot);
}

Fraction fPow(Fraction a, int deg) {
	Fraction ans; 
	a = fReduce(a);
	ans.numerator = a.numerator*a.numerator;
	ans.denominator = a.denominator*a.denominator;
	return ans;
}

//Need to add a function taking root of a whole fraction. E.g: Root(144/169, 2) return 12/13

*/