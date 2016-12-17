#include <stdio.h>
#include "FractionHandler.h"
#include "mathFunc.h"


void main() {
	Fraction sum, offsets, pro, div, pow;
	Fraction frac1, frac2;
	int deg, num;
	int cont = 1;

	printf("Hello World!\n");
	frac1 = FractionInput("What fraction do you want to input: ");
	frac2 = FractionInput("What fraction do you want to input 2: ");

	sum = fAdd( frac1, frac2);
	printf("Addition: %d/%d\n", sum.numerator, sum.denominator);

	offsets = fSubtract(frac1, frac2);
	printf("Subtraction: %d/%d\n", offsets.numerator, offsets.denominator);

	pro = fMul(frac1, frac2);
	printf("Multiplication: %d/%d\n", pro.numerator, pro.denominator);

	div = fDiv(frac1, frac2);
	printf("Division: %d/%d\n", div.numerator, div.denominator);

	printf("Please enter degree for power of input 1: ");
	scanf_s("  %d", &deg);
	pow = fPow(frac1, deg );
	printf("Power: %d/%d\n", pow.numerator, pow.denominator);

	do {
		printf("Check if int n is a power of k. \nPlease type in n: ");
		scanf_s(" %d", &num);
		printf("Please type in k: ");
		scanf_s(" %d", &deg);

		int result = mRoot(num, deg);
		if (result == NOT_FOUND) {
			printf("There is no result for a where a^k = n!\n ");
		}
		else {
			printf("Result = %d\n", result);
		}
		
		printf("Cont. ? (1/0)");
		scanf_s(" %d", &cont); 		
	} while (cont == 1);

	getchar();

}
  

