#ifndef ROOTHANDLER_H
#define ROOTHANDLER_H
#include <stdio.h>

//Basic data tpye of root https://en.wikipedia.org/wiki/Nth_root
typedef struct Root {
	//Root basic structure: a*root_n(b), all in integer 
	int degree; // is n 
	int base;// is b
	int para; // is a 
}Root;

//Root basic structure: a*root_n(b), with a,b is a fraction
typedef struct Root_Fraction {	
	int degree; // is n in a*root_n(b)
	Fraction base;// is b in a*root_n(b)
	Fraction para; // is a in a*root_n(b)
}Root_Fraction;

//Composite of 2 types(Root_Fraction and Fraction):x+ a*root_n(b), with a, b, x is a fraction
typedef struct Composite_RootFraction_Fraction {	
	Fraction component1; 
	Root_Fraction component2; 
}Composite_RootFraction_Fraction;

//a pair of Composite_RootFraction_Fraction
typedef struct Composite_RootFraction_Fraction_Pair {	
	//Composite of 2 types(Root_Fraction and Fraction):x+ a*root_n(b), with a, b, x is a fraction
	Composite_RootFraction_Fraction t_cube;
	Composite_RootFraction_Fraction s_cube;
}Composite_RootFraction_Fraction_Pair;


//Functions in this header files:
//____________________________________________________________________________________________// 
//Functions for Root struct

//Basic addtion. E.g: 5\sqrt{2} + 15\sqrt{2} = 20\sqrt{2} 
Root rAdd(Root, Root); 
//Basic subtraction. E.g: 5\sqrt{2} - 15\sqrt{2} = -10\sqrt{2}
Root rSubtract(Root, Root);
//Basic multiplication. E.g: 5\sqrt{2}*15\sqrt{11} = 75\sqrt{22} 
Root rMul(Root, Root);
//Basic devision. TBD
Root rDiv(Root, Root);
//Basic power
Root rPow(Root, int);
Root rReduce(Root);

//____________________________________________________________________________________________// 
//Functions for Root_Fraction struct

//Addition 
Root_Fraction rfAdd(Root_Fraction, Root_Fraction);
//Division from a Root_Fraction to a Fraction struct. There is only simple fraction reduction but not root reduction.  
Root_Fraction rfDiv_Fraction(Root_Fraction, Fraction);

Root rAdd(Root a, Root b) {
	Root ans;
	if (a.degree == b.degree) {
		if (a.base == b.base) {
			ans.degree = a.degree;
			ans.base = a.base;
			ans.para = a.para + b.para;
		}
	}
	return ans;
}

Root rSubtract(Root a, Root b) {
	Root ans;
	if (a.degree == b.degree) {
		if (a.base == b.base) {
			ans.degree = a.degree;
			ans.base = a.base;
			ans.para = a.para - b.para;
		}
	}
	return ans;
}

Root rPow(Root a, int deg) {
	Root ans;

	if (deg == 0) {
		ans.degree = 1;
		ans.base = 1;
		ans.para = 1;
	}
}

Root_Fraction rfDiv_Fraction(Root_Fraction divisor, Fraction dividend) {
	Root_Fraction ans; 
	int gcd_temp; 
	ans.degree = divisor.degree; 
	ans.base = divisor.base; 
	ans.para = fReduce(fDiv(divisor.para, dividend)); 
	return ans; 
}



#endif // !ROOTHANDLER_H
