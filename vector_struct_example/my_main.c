#include "my_vector_struct.h"
#include <stdio.h>

int main() {

	// lets start making vector v
	const int len = 4;
	my_vector v = vector_constructor(len);
	my_vector* ptr_v = &v;

	// this is the vector v
	int v_array[4] = { -1,5,2,3 };
	// putting in vector v into the structure of my_vector using vector_set
	for (int i = 0; i < sizeof(v_array) / sizeof(int);++i) {
		vector_set(ptr_v, i, v_array[i]);
	}
	// continue ...
	my_vector w = vector_constructor(len);
	my_vector* ptr_w = &w;

	// this is the vector v
	int w_array[4] = {1,-1,1,-2 };
	// putting in vector v into the structure of my_vector using vector_set
	for (int i = 0; i < sizeof(w_array) / sizeof(int);++i) {
		vector_set(ptr_w, i, w_array[i]);
	}

	double product;
	product = vector_dot_product(ptr_v, ptr_w);
	printf("v*w equals to: %g\n", product);

	my_vector minus;
	my_vector neg_w = vector_scalar_multiplication(ptr_w, -1.0);
	my_vector* ptr_neg_w = &neg_w;
	minus = vector_addition(ptr_v, ptr_neg_w);
	printf("v - w equals to: ");
	for (int i = 0; i < minus.length; i++) {
		printf("%g ", vector_get(&minus, i));
		
	}
	printf("\n");

	return 0;




}