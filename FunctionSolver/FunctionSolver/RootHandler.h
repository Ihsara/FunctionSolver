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

//Functions in this header files:

//Basic addtion. E.g: 5\sqrt{2} + 15\sqrt{2} = 20\sqrt{2} 
Root rAdd(Root, Root); 
//Basic subtraction. E.g: 5\sqrt{2} - 15\sqrt{2} = -10\sqrt{2}
Root rSubtract(Root, Root);
//Basic multiplication. E.g: 5\sqrt{2}*15\sqrt{11} = 75\sqrt{22} 
Root rMul(Root, Root);
//Basic devision. TBD
Root rDiv(Root, Root);
Root rPow(Root, int);
Root rReduce(Root);

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




#endif // !ROOTHANDLER_H
