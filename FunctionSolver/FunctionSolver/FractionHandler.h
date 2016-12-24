#ifndef FRACTIONHANDLER_H
#define FRACTIONHANDLER_H
#include <stdio.h>
#include "mathFunc.h"

//Basic data type of fraction 
typedef struct Fraction{
int numerator;
int denominator;
}Fraction;



Fraction FractionInput(char Msg[100]);
Fraction fReduce(Fraction);
Fraction fAdd(Fraction, Fraction);
Fraction fSubtract(Fraction, Fraction);
Fraction fMul(Fraction, Fraction);
Fraction fDiv(Fraction, Fraction);
Fraction fPow(Fraction, int);

//Functions turning Int to Fraction

//Turn an integer into it fraction form(numerator addition).
Fraction fIntToFrac_numAdd(int); 
//Turn an integer into it fraction form(denominator addition). 
Fraction fIntToFrac_denAdd(int);
//Turn an integer into it fraction form(numerator and denominator addition). 
Fraction fIntToFrac_num_den_add(int, int);

//Functions performing operations between int and fraction 

//Multiply a number with a fraction type 
Fraction fMul_Frac_Int(Fraction, int);


Fraction FractionInput(char Msg[100]) {
	Fraction Frac;
	int init = 0; 

	Frac.numerator = 1;
	Frac.denominator = 1; 

	do {		
		if (init >= 1) {
			printf("Syntax Error. Please enter denominator other than 0.\n");
		}
		printf("%s", Msg);
		scanf_s("%d/%d", &Frac.numerator, &Frac.denominator);
		init++;	
	} while (Frac.denominator == 0);

	return Frac;
}

Fraction fReduce(Fraction a) {
	int t_gcd = gcd(abs(a.numerator), abs(a.denominator));
	a.numerator = a.numerator / t_gcd;
	a.denominator = a.denominator / t_gcd;
	return a;
}

//Ideas for these following functions from: http://stackoverflow.com/questions/33887484/c-fraction-arithmetic
//Basic Operations for functions with both numerator and denominator are int data type

Fraction fAdd(Fraction a, Fraction b) {
	Fraction sum;
	sum.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
	sum.denominator = a.denominator * b.denominator;
	return fReduce(sum);
}

Fraction fSubtract(Fraction a, Fraction b) {
	Fraction offsets;
	offsets.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
	offsets.denominator = a.denominator * b.denominator;
	return fReduce(offsets);
}

Fraction fMul(Fraction a, Fraction b) {
	Fraction pro;
	pro.numerator = a.numerator*b.numerator;
	pro.denominator = a.denominator*b.denominator;
	return fReduce(pro);
}

Fraction fDiv(Fraction a, Fraction b) {
	Fraction quot;
	quot.numerator = a.numerator*b.denominator;
	quot.denominator = a.denominator*b.numerator;
	return fReduce(quot);
}

Fraction fPow(Fraction a, int deg) {
	Fraction ans, base;
	a = fReduce(a);
	base = a;
	ans = base;
	if (deg == 0) {
		ans.numerator = 1;
		ans.denominator = 1;
	}
	else if (a.numerator == 0) {
		ans.numerator = 0;
		ans.denominator = 1; 
	}
	else {
		for (int i = 1; i < deg; i++) {
			ans.numerator = ans.numerator*base.numerator;
			ans.denominator = ans.denominator*base.denominator;
		}
	}

	return ans;
}

Fraction fIntToFrac_numAdd(int num) {
	Fraction ans;
	ans.numerator = num;
	ans.denominator = 1;
	return ans;
}

Fraction fIntToFrac_denAdd(int num) {
	Fraction ans;
	ans.numerator = 1; 
	ans.denominator = num;
	return ans;
}

Fraction fIntToFrac_num_den_add(int num, int den) {
	Fraction ans; 
	ans.numerator = num;
	ans.denominator = den;
	return ans;
}

Fraction fMul_Frac_Int(Fraction a, int num) {
	a.numerator = a.numerator*num;
	return fReduce(a);
}

//Need to add a function taking root of a whole fraction. E.g: Root(144/169, 2) return 12/13

#endif 