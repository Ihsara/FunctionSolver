/* 
#include <stdio.h>
#include <string.h>
#include "FractionHandler.c"

// Called when input is a fraction
Fraction FractionInput(char Msg[100] );

Fraction FractionInput(char Msg[100]) {
	Fraction Frac;
	printf("%s", Msg);
	scanf_s("%d/%d", &Frac.numerator, &Frac.denominator);
	return fReduce(Frac);
}

*/ 