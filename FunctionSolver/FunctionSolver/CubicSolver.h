#ifndef CUBICSOLVER_H
#define CUBICSOLVER_H
#include <math.h>

#include "RootHandler.h"
#include "mathFunc.h"
#include "FractionHandler.h"

//Calculate value of delta and d^2 - h^2 
Fraction cuDeltaCal(Fraction paraList[4], Fraction *);
//Carnado's method reduced a cubic function ax^3 + b^2 +cx^2 +d to y^3 + Ay +B 
Fraction cuDepressedPara(Fraction paraList[4], Fraction*, Fraction *);


//small funtion for raising the power y of a number x in INT 
int Pow(int, int);

int Pow(int base, int deg) {
	int ans; 
	ans = (int)pow((double)base, (double)deg);
	return ans; 
}

Fraction cuDeltaCal(Fraction paraList[4], Fraction *dhDiff) {
	Fraction delta_sqr, delta_cub, h_sqr;//Main variables for this function 

	//Temp para for calculate delta_sqr 
	Fraction delta_sqr_nu, delta_sqr_nu1, delta_sqr_nu2, delta_sqr_de;

	//Prelim for para. Make sure input para are irreducible 
	for (int index = 0; index < 3; index++) {
		paraList[index] = fReduce(paraList[index]);
	}

	//delta_sqr_nu1 = fPow(paraList[1],2 );
	//delta_sqr_nu2 = fReduce(fMul( fFracTrans(2), fMul(paraList[0], paraList[2])));
	//delta_sqr_nu = fReduce(fDiv(fPow(paraList[1],2 ), fReduce(fMul(fFracTrans(2), fMul(paraList[0], paraList[2])))));
	//delta_sqr_de = fReduce(fMul(fFracTrans(9), fPow(paraList[0], 2))); 
	//delta_sqr = fReduce(fDiv(delta_sqr_nu, delta_sqr_de));
	delta_sqr = fReduce(fDiv(fReduce(fDiv(fPow(paraList[1], 2), fReduce(fMul(fFracTrans(2), fMul(paraList[0], paraList[2]))))), fReduce(fMul(fFracTrans(9), fPow(paraList[0], 2)))));

	h_sqr = fReduce(fMul(fFracTrans(4), fReduce(fMul(fPow(paraList[0], 2), fPow(delta_sqr, 3)))));

	*dhDiff = fReduce(fSubtract(fPow(paraList[3], 2), h_sqr));

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

	b_11 = paraList[2]; 
	b_12_nu = fPow(paraList[1], 2);
	b_12_de.numerator = 3 * paraList[0].numerator;
	b_12_de.denominator = paraList[0].denominator;
	b_12_de = fReduce(b_12_de);
	b_12 = fReduce(fDiv(b_12_nu, b_12_de));
	b_1 = fReduce(fSubtract(b_11, b_12));

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

	//Step 2: 
	*A = fReduce(fDiv(b_1, a_1)); // as in y^3 + Ay +B
	*B = fReduce(fDiv(c_1, a_1)); //as in y^3 + Ay +B
}






#endif