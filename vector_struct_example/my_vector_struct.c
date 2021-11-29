#include "my_vector_struct.h"
#include <stdlib.h>
#include <stdio.h>

// implementation of the functions

// constructor
my_vector vector_constructor(const int length){

  // declaring a vector
  my_vector vec;
  vec.v = NULL; // initializes to a vector of zeroes
  
  // return if a bad length value is given
  if (length <= 0){
    printf("vector_constructor: the vector length is negative!\n");
    vec.length = length;
    vec.status = 1;
    return vec;
  }
  else{ // length > 0 and we try to allocate memory
    vec.length = length;
    vec.v = (double*) calloc(length, sizeof(double));
    if(vec.v != NULL){ //A == NULL means out of memory; memory assignment comes after calloc in the above line
      vec.status = 0;
    }
    else{
      vec.status = 1;
    }
    return vec;
  }
}

// destructor
void vector_destructor(my_vector* vec){
  free(vec->v);
  // status is nonzero indicating the vector cannot be used.
  vec->status = 1;
}

// set <-- this function writes to a value in a given index, in the vector
void vector_set(my_vector* vec, const int index, const double value){
  if (vec->status == 0){
    if (index > vec->length - 1){
      printf("vector_set: index exceeds vector length\n");
    }
    else{
      // set value.
      vec->v[index] = value;
    }
  }
  else {
    printf("vector_set: this vector cannot be used now\n");
  }
}

// get <-- this function reads the a value from a given index, from the vector
double vector_get(my_vector* vec, const int index){
  double value = 0.0;
  if (vec->status == 0){
    if (index > vec->length - 1){
      printf("vector_get: index exceeds vector length\n");
    }
    else{
      // set value.
      value = vec->v[index];
    }
  }
  else {
    printf("vector_get: this vector cannot be used now\n");
  }
  return value;
}


// vector scalar multiplication
my_vector vector_scalar_multiplication(my_vector* v, double num){ // num is our scalar!
  // initialized a new vector called w
  my_vector w = vector_constructor(v->length);

  // here the input is the scalar num and we have checked that v is a usable vector
  if (v->status == 0){

    //get the address of w for the pointer
    my_vector* ptr_w = &w; // ptr_w points to the address of the vector w
    

    // ptr_w is used since this is the only way we can access the heap
    // for loop for scalar multiplication
    // continue ... [use vector_set() here]

    for (int i = 0; i < v->length; i++) {
	vector_set(ptr_w, i, num*vector_get(v, i)); // setting the scaled version of the ith entry of v as the ith entry of new vector w
    }
  }
  else{
    printf("vector_scalar_multiplication: this is an invalid vector we have inputted");
  }

  return w;
}

// vector addition
my_vector vector_addition(my_vector* v, my_vector* u){
	my_vector w = vector_constructor(v->length); // initialize a vector called w

	if (v->status == 0 && u->status == 0 && v->length == u->length) { // if both vectors are usable and are the same length

	//get the address of w for the pointer
	my_vector* ptr_w = &w; // ptr_w points to the address of the vector w

    		for (int i = 0; i < v->length; i++) {
			vector_set(ptr_w, i, vector_get(v, i) + vector_get(u, i)); // setting the sum of the ith entries of vectors v and u as the ith 											 // entry of the new vector w 
    		}
	}
  	else{
		printf("vector_addition: either one of the inputted vectors is invalid or the length of the vectors do not match");
	}

  return w;
}

// vector dot product
double vector_dot_product(my_vector* v, my_vector* u){ // this is the only of the three vector operation functions that has a return type of double,							     // since the output of the dot product of two same-sized vectors is a scalar
	double dot_product = 0.0; // initializing the value of the dot product to 0.0
        if (v->status == 0 && u->status == 0 && v->length == u->length) { // if both vectors are usable and are the same length
		for (int i = 0; i < v->length; i++) {
			dot_product += vector_get(v, i)*vector_get(u, i); // entrywise multiplication the vectors v and u, which are added to the
									  // running total dot_product
		}
        }
  	else{
    		printf("vector_dot_product: either one of the inputted vectors is invalid or the length of the vectors do not match");
	}

  return dot_product;
}

