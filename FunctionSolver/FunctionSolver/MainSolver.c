#include <stdio.h>
#include <stdlib.h>

#include "FractionHandler.h"
#include "mathFunc.h"
#include "RootHandler.h"
#include "CubicSolver.h"
#include "StringHandler.h"

void main() {

	Fraction paraList[4]; 	
	Fraction dh_Diff, h_sqr, delta_squr;
	Fraction A, B, c_1; 
	char paraNames[] = { 'A', 'B', 'C', 'D' };
	int ans = 1; 

	do {
		system("cls");
		greetingsMsg();

		for (int index = 0; index < 4; index++) {
			//char temp = sprintf_s("Please enter value for parameter ", "%s: ", paraNames[index]);
			char temp[100];
			char constMsg[] = "Please enter value for parameter ";
			sprintf_s(temp, 100, "%s%c%s", constMsg, paraNames[index], ": ");
			paraList[index] = FractionInput(temp);
		}

		c_1 = cuDepressedPara(paraList, &A, &B);
		delta_squr = cuDeltaCal(paraList, &dh_Diff, &h_sqr);
		/* Debugging
		printf("dhDiff: %d/%d.\n", dh_Diff);
		printf("Delta squared: %d/%d.\n", delta_squr);
		printf("h squared: %d/%d.\n", h_sqr.numerator, h_sqr.denominator);
		printf("c_1: %d/%d.\n", c_1.numerator, c_1.denominator);
		printf("A: %d/%d.\n", A.numerator, A.denominator);
		printf("B: %d/%d.\n", B.numerator, B.denominator);
		*/

		if (dh_Diff.numerator > 0 && dh_Diff.denominator >0) {
			//printf("One real root!\n");
			oneRtMsg(cuOneRealRt(delta_squr, h_sqr, paraList), paraList);
		}
		else if ((dh_Diff.numerator < 0 && dh_Diff.denominator >0) || (dh_Diff.numerator > 0 && dh_Diff.denominator <0)) {
			//printf("Three real roots!\n");
			threeRtMsg(h_sqr, delta_squr, c_1);
		}
		else {
			//printf("Repeated roots!\n");
			repeatedRtMsg(cuDeltaCal(paraList, &A, &B));
		}

		getchar();
		printf("Continue?(1/0): ");
		scanf_s("%d", &ans);
	} while (ans == 1);
	

	printf("This concludes the program!\n");
	getchar();

}



