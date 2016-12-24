#ifndef STRINGHANDLER_H
#define STRINGHANDLER_H
#include <stdio.h>


void testFunc();
void greetingsMsg();
void paraMsgs(Fraction paraList[4] ); 
void oneRtMsg(Composite_RootFraction_Fraction_Pair, Fraction paraList[4] );
void repeatedRtMsg(Fraction delta_sqr);
void threeRtMsg(Fraction, Fraction, Fraction);

void greetingsMsg() {
	printf("This is the program to give out solution for a cubic function in Latex form.\n");
	printf("The program will accept integer or rational number(x/y with x,y are integers).\n");
	printf("________________________________________________________________________________\n");
	printf("The program use integer as a base starage type for operation.\n");
	printf("It can reduce fractions to its irreducible form.\n");
	printf("Root reduction is not an available feature.\n");
	printf("The result is in Latex format.\n");
	printf("Please copy the result in this program to https ://www.codecogs.com/latex/eqneditor.php \nin order to get a mathematical expression of that result.\n");
	printf("Accepted input methods: a, a/b with a, b are integers.\n");
	printf("________________________________________________________________________________\n");
	printf("Equation to solve: A*X^3 + B*X^2 + C*X + D = 0\n");

}

void testFunc() {
	Fraction sum, offsets, pro, div, pow;
	Fraction frac1, frac2;
	int deg, num;
	int cont = 1;

	printf("Hello World!\n");
	frac1 = FractionInput("What fraction do you want to input: ");
	frac2 = FractionInput("What fraction do you want to input 2: ");

	sum = fAdd(frac1, frac2);
	printf("Addition: %d/%d\n", sum.numerator, sum.denominator);

	offsets = fSubtract(frac1, frac2);
	printf("Subtraction: %d/%d\n", offsets.numerator, offsets.denominator);

	pro = fMul(frac1, frac2);
	printf("Multiplication: %d/%d\n", pro.numerator, pro.denominator);

	div = fDiv(frac1, frac2);
	printf("Division: %d/%d\n", div.numerator, div.denominator);

	printf("Please enter degree for power of input 1: ");
	scanf_s("  %d", &deg);
	pow = fPow(frac1, deg);
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
}

void paraMsgs(Fraction paraList[4]) {
	printf("_______________________________________________________________\n");
	for (int index = 0; index < 4; index++) {
		char temp[100];
		char paraNames[] = { 'A', 'B', 'C', 'D' };
		char constMsg[] = "Value of parameter ";
		sprintf_s(temp, 100, "%s%c%s", constMsg, paraNames[index], ": ");
		printf("%s%d/%d.\n", temp, paraList[index].numerator, paraList[4].denominator);
	}
	printf("_______________________________________________________________\n");
}

void oneRtMsg(Composite_RootFraction_Fraction_Pair root, Fraction paraList[4]) {
	Fraction trans; 

	trans = fReduce(fDiv(fMul_Frac_Int(paraList[1], -1), fMul_Frac_Int(paraList[0], 3)));

	if (paraList[1].numerator == 0) {
		printf("The given parameters result in one real root: \\sqrt[3]{\\frac{%d}{%d}+ \\frac{%d}{%d}\\sqrt{\\frac{%d}{%d}}}- \\sqrt[3]{\\frac{%d}{%d}+ \\frac{%d}{%d}\\sqrt{\\frac{%d}{%d}}}.\n",
			root.s_cube.component1.numerator, root.s_cube.component1.denominator, root.s_cube.component2.para.numerator, root.s_cube.component2.para.denominator, root.s_cube.component2.base.numerator, root.s_cube.component2.base.denominator,
			root.t_cube.component1.numerator, root.t_cube.component1.denominator, root.t_cube.component2.para.numerator, root.t_cube.component2.para.denominator, root.t_cube.component2.base.numerator, root.t_cube.component2.base.denominator);
	}
	else {
		printf("The given parameters result in one real root: \\sqrt[3]{\\frac{%d}{%d}+ \\frac{%d}{%d}\\sqrt{\\frac{%d}{%d}}}- \\sqrt[3]{\\frac{%d}{%d}+ \\frac{%d}{%d}\\sqrt{\\frac{%d}{%d}}} +\\frac{%d}{%d}.\n",
			root.s_cube.component1.numerator, root.s_cube.component1.denominator, root.s_cube.component2.para.numerator, root.s_cube.component2.para.denominator, root.s_cube.component2.base.numerator, root.s_cube.component2.base.denominator,
			root.t_cube.component1.numerator, root.t_cube.component1.denominator, root.t_cube.component2.para.numerator, root.t_cube.component2.para.denominator, root.t_cube.component2.base.numerator, root.t_cube.component2.base.denominator,
			trans.numerator, trans.denominator);
	}

}

void repeatedRtMsg(Fraction delta_sqr) {
	if (delta_sqr.denominator == 1) {
		printf("The given parameters result in 2 distinct real roots: \\sqrt{%d} and 2\\sqrt{%d}.\n", delta_sqr.numerator, delta_sqr.numerator);
	}
	else {
		printf("The given parameters result in 2 distinct real roots: \\sqrt{%d/%d} and 2\\sqrt{%d/%d}.\n", delta_sqr.numerator, delta_sqr.denominator, delta_sqr.numerator, delta_sqr.denominator);
	}
}

void threeRtMsg(Fraction h_sqr, Fraction delta_sqr, Fraction d) {
	Root_Fraction d_over_h; 
	d_over_h.base = fDiv(fIntToFrac_numAdd(1), h_sqr);
	d_over_h.degree = 2;
	d_over_h.para = fMul_Frac_Int(d, -1); 
	printf("The given parameters result in 3 real roots: \n");
	printf("\\theta = \\frac{1}{3}\\arccos{-\\frac{%d}{%d}\\sqrt{\\frac{%d}{%d}}.\n",
		d.numerator, d.denominator, h_sqr.denominator, h_sqr.numerator);
	printf("x_1 = 2\\sqrt{\\frac{%d}{%d}}\\cos{\\theta}\n",delta_sqr.numerator, delta_sqr.denominator);
	printf("x_2 = 2\\sqrt{\\frac{%d}{%d}}\\cos{\\frac{2\\pi}{3}- \\theta}\n", delta_sqr.numerator, delta_sqr.denominator);
	printf("x_2 = 2\\sqrt{\\frac{%d}{%d}}\\cos{\\frac{2\\pi}{3}+ \\theta}\n", delta_sqr.numerator, delta_sqr.denominator);
}

#endif // !STRINGHANDLER_H
