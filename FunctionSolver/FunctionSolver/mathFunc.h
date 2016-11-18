// Extentions header for mathematical functions for this project 

#ifndef MATHFUNC_H
#define MATHFUNC_H
#include <math.h>
#include "FractionHandler.h"

int const NOT_FOUND = -100;

//new root function. NumInput is the number to perform check, deg is the degree of checking
int mRoot(int numInput, int deg);

int mRoot(int numInput, int deg) {
	int ans;
	int found = 0;
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
				if ((int)pow((double)i, (double)deg) == numInput) {
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

#endif 