#ifndef CUBICSOLVER_H
#define CUBICSOLVER_H
#include <math.h>

#include "RootHandler.h"
#include "mathFunc.h"
#include "FractionHandler.h"
#include "StringHandler.h"

//Calculate value of delta and d^2 - h^2 
Fraction cuDeltaCal(Fraction paraList[4], Fraction *, Fraction *);

//Carnado's method reduced a cubic function ax^3 + b^2 +cx^2 +d to y^3 + Ay +B 
Fraction cuDepressedPara(Fraction paraList[4], Fraction*, Fraction *);

//Function that solve d^2 -h^2 >0 case. return 1 distinct root. 
Composite_RootFraction_Fraction_Pair cuOneRealRt(Fraction, Fraction, Fraction paraList[4]);

//Function for d^2 - h^2 <0 case 
//FracRootTrigCombi cuThreeRealTrigRt(Fraction, Fraction, Fraction paraList[4]);

//Function for d^2 -h^2 = 0 case 
//FracRoot cuThreeRealRt(Fraction Delta_sqr); 

//small funtion for raising the power y of a number x in INT 
int Pow(int, int);

int Pow(int base, int deg) {
	int ans; 
	ans = (int)pow((double)base, (double)deg);
	return ans; 
}

Fraction cuDeltaCal(Fraction paraList[4], Fraction *dhDiff, Fraction *h_sqr) {
	Fraction delta_sqr;//Main variables for this function 

	//Temp para for calculate delta_sqr 
	Fraction delta_sqr_nu, delta_sqr_nu1, delta_sqr_nu2, delta_sqr_de;

	//Prelim for para. Make sure input para are irreducible 
	for (int index = 0; index < 3; index++) {
		paraList[index] = fReduce(paraList[index]);
	}
	/*
	delta_sqr_nu1 = fPow(paraList[1],2 );
	delta_sqr_nu2 = fReduce(fMul( fIntToFrac_numAdd(3), fMul(paraList[0], paraList[2])));
	delta_sqr_nu = fReduce(fSubtract(fPow(paraList[1],2 ), fReduce(fMul(fIntToFrac_numAdd(3), fMul(paraList[0], paraList[2])))));
	delta_sqr_de = fReduce(fMul(fIntToFrac_numAdd(9), fPow(paraList[0], 2))); 
	delta_sqr = fReduce(fDiv(delta_sqr_nu, delta_sqr_de));
	printf("Value of delta_sqr: %d/%d.\n", delta_sqr); 
	*/

	delta_sqr = fReduce(fDiv(fReduce(fSubtract(fPow(paraList[1], 2), fReduce(fMul(fIntToFrac_numAdd(3), fMul(paraList[0], paraList[2]))))), fReduce(fMul(fIntToFrac_numAdd(9), fPow(paraList[0], 2)))));

	*h_sqr = fReduce(fMul(fIntToFrac_numAdd(4), fReduce(fMul(fPow(paraList[0], 2), fPow(delta_sqr, 3)))));

	*dhDiff = fReduce(fSubtract(fPow(paraList[3], 2), *h_sqr));

	/*
	paraMsgs(paraList);
	printf("Value of  delta_sqr_nu: %d/%d.\n", delta_sqr_nu);
	printf("Value of  delta_sqr_nu1: %d/%d.\n", delta_sqr_nu1);
	printf("Value of  delta_sqr_nu2: %d/%d.\n", delta_sqr_nu2);
	printf("Value of  delta_sqr_de: %d/%d.\n", delta_sqr_de);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	printf("fPow 3: %d/%d.\n",fPow(delta_sqr, 3).numerator, fPow(delta_sqr, 3).denominator);
	printf("4 to frac: %d/%d.\n", fIntToFrac_numAdd(4).numerator, fIntToFrac_numAdd(4).denominator);	
	printf("a^2del^6: %d/%d.\n", fReduce(fMul(fPow(paraList[0], 2), fPow(delta_sqr, 3))).numerator, fReduce(fMul(fPow(paraList[0], 2), fPow(delta_sqr, 3))).denominator);
	printf("hsqr LHS: %d/%d.\n", *h_sqr);
	printf("hsqr RHS: %d/%d.\n", fReduce(fMul(fIntToFrac_numAdd(4), fReduce(fMul(fPow(paraList[0], 2), fPow(delta_sqr, 3))))));
	printf("_______________________________________________________________\n");
	*/

	return delta_sqr; 
}

Fraction cuDepressedPara(Fraction paraList[4], Fraction* A, Fraction* B) {
	Fraction a_1, b_1, c_1; // main para for step 1 

	//Temp para for processing in step 1 
	Fraction b_11, b_12, b_12_nu, b_12_de, c_11, c_12, c_12_nu, c_12_de, c_13, c_13_nu, c_13_de; 

	//Prelim for para. Make sure input para are irreducible 
	for (int index = 0; index < 3; index++) {
		paraList[index] = fReduce(paraList[index]);
	}

	/* There are 2 main steps in this transformation: 
		1/ Change ax^3 + b^2 +cx^2 +d  to a_1y^3 + b_1y +c_1 
		2/ Change a_1y^3 + b_1y +c_1   to y^3 + Ay +B
		*/

	//Step 1: 
	a_1 = paraList[0];
	//printf("_______________________________________________________________\n");
	//printf("a_1: %d/%d.\n", a_1);

	/*
	b_11 = paraList[2]; 
	b_12_nu = fPow(paraList[1], 2);
	b_12_de.numerator = 3 * paraList[0].numerator;
	b_12_de.denominator = paraList[0].denominator;
	b_12_de = fReduce(b_12_de);
	b_12 = fReduce(fDiv(b_12_nu, b_12_de));
	b_1 = fReduce(fSubtract(b_11, b_12));
	b_12_de = fReduce(fMul(fIntToFrac(3), paraList[0]));//middle work	
	b_12 = fReduce(fDiv(fPow(paraList[1], 2), fReduce(fMul(fIntToFrac_numAdd(3), paraList[0]))));
	*/
	b_1 = fReduce(fSubtract(paraList[2], fReduce(fDiv(fPow(paraList[1], 2), fReduce(fMul(fIntToFrac_numAdd(3), paraList[0]))))));
	//printf("b_1: %d/%d.\n", b_1);
	/*
	c_11 = paraList[3];
	c_12_nu = fPow(paraList[1], 3);
	c_12_nu.numerator = c_12_nu.numerator * 2; 
	c_12_de = fPow(paraList[0], 2);
	c_12_de.numerator = 27 * c_12_de.numerator;
	c_12 = fReduce(fDiv(fReduce(c_12_nu), fReduce(c_12_de)));
	c_13_nu = fReduce(fMul(paraList[1], paraList[2])); 
	c_13_de.numerator = 3 * paraList[0].numerator;
	c_13_de.denominator = paraList[0].denominator; 
	c_13 = fReduce(fDiv(c_13_nu, fReduce(c_13_de))); 
	c_1 = fReduce(fSubtract(fReduce(fAdd(c_11, c_12)), c_13));


	c_11 = paraList[3];
	c_12_nu = fMul(fPow(paraList[1], 3), fIntToFrac_numAdd(2));
	c_12_de = fMul(fPow(paraList[1], 3), fIntToFrac_numAdd(27));
	c_12 = fReduce(fDiv(fReduce(fMul(fPow(paraList[1], 3), fIntToFrac_numAdd(2))), fReduce(fMul(fPow(paraList[0], 2), fIntToFrac_numAdd(27)))));
	c_13_de = fMul(fIntToFrac_numAdd(3), paraList[0]);
	c_13 = fReduce(fDiv(fReduce(fMul(paraList[1], paraList[2])), fReduce(fMul(fIntToFrac_numAdd(3), paraList[0]))));
	c_1 = fReduce(fSubtract(fReduce(fAdd(c_11, c_12)), c_13));
	*/
	c_1 = fReduce(fSubtract(fReduce(fAdd(paraList[3], fReduce(fDiv(fReduce(fMul(fPow(paraList[1], 3), fIntToFrac_numAdd(2))), fReduce(fMul(fPow(paraList[0], 2), fIntToFrac_numAdd(27))))))), fReduce(fDiv(fReduce(fMul(paraList[1], paraList[2])), fReduce(fMul(fIntToFrac_numAdd(3), paraList[0]))))));
	//printf("c_1: %d/%d.\n", c_1);
	//printf("_______________________________________________________________\n");

	//Step 2: 
	*A = fReduce(fDiv(b_1, a_1)); // as in y^3 + Ay +B
	*B = fReduce(fDiv(c_1, a_1)); //as in y^3 + Ay +B

	return c_1;
}

Composite_RootFraction_Fraction_Pair cuOneRealRt(Fraction delta, Fraction h_sqr, Fraction paraList[4]) {
	Composite_RootFraction_Fraction_Pair ans; 
	Fraction delta_power6 , d, temp; 
	Fraction A, B;

	delta_power6 = fPow(delta, 3); 
	d = cuDepressedPara(paraList, &A, &B );

	ans.t_cube.component1 = fReduce(fDiv(d , fMul_Frac_Int(paraList[0], 2) ));
	ans.t_cube.component2.degree = 2;
	ans.t_cube.component2.base = fReduce(fSubtract(fPow(d, 2), h_sqr));
	temp = fReduce(fDiv(fPow(A, 3), fIntToFrac_numAdd(27))); 
	ans.t_cube.component2.para = fReduce(fDiv(fIntToFrac_denAdd(1), fMul_Frac_Int(paraList[0], 2)));

	//ans.s_cube.component1 = fReduce(fSubtract(ans.t_cube.component1, delta_power6));
	ans.s_cube.component1 = fReduce(fSubtract(ans.t_cube.component1, fReduce(fDiv(d, paraList[0]))));
	ans.s_cube.component2 = ans.t_cube.component2;

	return ans; 
}




#endif