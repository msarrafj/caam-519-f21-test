#include "my_vector_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// implementation of the functions

// constructor
my_vector vector_constructor(const int length){

  // declaring a vector
  my_vector vec;
  vec.v = NULL;
  
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
    if(vec.v != NULL){ //A == NULL means out of memory
      vec.status = 0;
    }
    else{
      vec.status = 1;
    }
    return vec;
  }
}

// Constructor for creating an uninitialized vector.
// Sets the length field but does not attempt to malloc
// any memory. Can be used to avoid unnecessary mallocs 
// whenever an operation that must return a vector errors
// out.
my_vector uninitialized_vector(const int length){
  my_vector vec;
  vec.v = NULL;
  vec.length = length;
  vec.status = 1;
  return vec;
}


// destructor
void vector_destructor(my_vector* vec){
  free(vec->v);
  vec->v = NULL; // Prevent anyone from trying to access this anymore. Also prevents multiple calls to `free`.
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
my_vector vector_scalar_multiplication(my_vector* v, double num){
  // Use a length variable so it is obvious w and v have the same   // length.
  int length = v->length;

  // here the input is the scalar num and we have checked that v is a usable vector
  if (v->status != 0) {
    printf("vector_scalar_multiplication: this is an invalid vector we have inputted"); 
    return uninitialized_vector(length);
  }
  
  // Check for NaN. Something went wrong if we are multiplying 
  // by a NaN, so it's best to catch it early.
  if (isnan(num)) {
    printf("vector_scalar_multiplication: attempted to multiply by NaN");
    return uninitialized_vector(length);
  }

  // initialized a new vector called w
  my_vector w = vector_constructor(length);

  // Verify we are able to initialize w
  if (w.status != 0) {
    printf("vector_scalar_multiplication: unable to initialize new vector");
    return w;
  }

  // Set the values in a loop.
  for (int i = 0; i < length; i++) {
   vector_set(&w, i, vector_get(v, i) * num); 
  }

  return w;
}


// Vector addition.
my_vector vector_addition(my_vector* v, my_vector* u) {
  
  // Verify u and v have the same length
  if (v->length != u->length) {
    printf("vector_addition: Cannot add vectors with different lengths.");
  } 
 
  // Use a length variable so it is obvious the vectors have 
  // the same length.
  int length = v->length;

  // Verify input vectors are valid.
  if (v->status != 0 || u->status != 0) {
    printf("vector_addition: this is an invalid vector we have inputted"); 
    return uninitialized_vector(length);
  }
  
  // initialized a new vector called w
  my_vector w = vector_constructor(length);

  // Verify we are able to initialize w
  if (w.status != 0) {
    printf("vector_addition: unable to initialize new vector");
    return w;
  }

  // Set the values in a loop.
  for (int i = 0; i < length; i++) {
   vector_set(&w, i, vector_get(v, i) + vector_get(u, i)); 
  }

  return w;
}


// Vector dot product
double vector_dot_product(my_vector* v, my_vector* u) {
  
  // Verify u and v have the same length
  if (v->length != u->length) {
    printf("vector_dot_product: Cannot add vectors with different lengths.");
  } 
 
  // Use a length variable so it is obvious the vectors have 
  // the same length.
  int length = v->length;

  // Verify input vectors are valid.
  if (v->status != 0 || u->status != 0) {
    printf("vector_dot_product: this is an invalid vector we have inputted"); 
    return 0.0;
  }
  
  double tol = 0.0;
  
  // Calculate dot product.
  for (int i = 0; i < length; i++) {
   tol += vector_get(v, i) * vector_get(u, i); 
  }

  return tol;
}

void vector_pretty_print(my_vector* v) {
	printf("{");
	if (v->length > 0) {
		printf("%f", vector_get(v, 0));	
	}
	for (int i = 1; i < v->length; i++) {
		printf(", %f", vector_get(v, i));
	}
	printf("}");
}

