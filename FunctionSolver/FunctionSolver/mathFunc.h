// Extentions header for mathematical functions for this project 

#ifndef MATHFUNC_H
#define MATHFUNC_H
#include <stdio.h>
#include <math.h>

#include "FractionType.h"

int const NOT_FOUND = -100;

//new root function. NumInput is the number to perform check, deg is the degree of checking
int mRoot(int numInput, int deg); 
//gcd function - return gcd of two numbers
//http://snipplr.com/view/42917/
int gcd(int, int);
int lcd(int, int);
int is_squared(int, int); 


int gcd(int n, int m) {
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

int mRoot(int numInput, int deg) {
	int ans;
	int found= 0; 
	if (deg == 2) {
		double stopPoint = sqrt((double)numInput); 
		for (int i = 0; i <= (int)stopPoint; i++) {
			if (i*i == numInput) {
				ans = i;
				found = 1; 
				break; 
			}
		}
		
	}
	else {
		if (numInput > 2) {
			int stopPoint = numInput / deg;
			for (int i = 0; i <= stopPoint; i++) {
				if ((int) pow( (double)i, (double)deg)  == numInput) {
					ans = i;
					found = 1; 
					break;
				}
			}
		}
	}
	if (found == 0) {
		ans = NOT_FOUND; // saying that there's no answer that is an integer for the inquired number 
	}

	return ans;
}

int is_squared(int num, int deg) {
	int ans =0 ; 
	for (int i = 2; i < num / 2; i++) {
		if ((int)pow((double)i, (double)deg) == num) {
			ans = 1;
		}
	}
	return ans;
}


#endif 