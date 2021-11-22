#include "inc/my_vector_struct.h"
#include <stdlib.h>
#include <stdio.h>

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
my_vector vector_scalar_multiplication(my_vector* v, double num){
  // initialized a new vector called w
  my_vector w = vector_constructor(v->length);

  // here the input is the scalar num and we have checked that v is a usable vector
  if (v->status == 0){

    //get the address of w for the pointer
    my_vector* ptr_w = &w;
    
    // for loop for vector-scalar multiplication
    // iterative scalar-scalar multiplication for each element
    for (int i = 0; i < v->length; i++){
      vector_set(ptr_w, i, num*vector_get(v,i));
    }
  
  }
  else{
    printf("vector_scalar_multiplication: this is an invalid vector we have inputted\n");
  }

  return w;
}

// vector addition
my_vector vector_addition(my_vector* v1, my_vector* v2){
  // initialize result vector
  my_vector result = vector_constructor(v1->length);
  my_vector* result_ptr = &result;

  // conditionals for error checking
  if (v1->status != 0){
    printf("vector_addition: Invalid input vector 1.\n");
    return result;
  }
  if (v2->status != 0){
    printf("vector_addition: Invalid input vector 2.\n");
    return result;
  }
  if (v1->length != v2->length){
    printf("vector_addition: Vector lengths do not match: %d vs %d\n", v1->length, v2->length);
    return result;
  }

  // element-wise addition loop
  for (int i = 0; i < v1->length; i++){
    vector_set(result_ptr, i, vector_get(v1,i)+vector_get(v2,i));
  }
  return result;
}

// vector dot product
double vector_dot_product(my_vector* v1, my_vector* v2){
  // initialize result value
  double result = 0;
  double* result_ptr = &result;

  // conditionals for error checking
  if (v1->status != 0){
    printf("vector_dot_product: Invalid input vector 1.\n");
    return result;
  }
  if (v2->status != 0){
    printf("vector_dot_product: Invalid input vector 2.\n");
    return result;
  }
  if (v1->length != v2->length){
    printf("vector_dot_product: Vector lengths do not match: %d vs %d\n", v1->length, v2->length);
    return result;
  }

  // element-wise multiplication loop
  // each iteration is added to the cumulative
  for (int i = 0; i < v1->length; i++){
    result += vector_get(v1,i)*vector_get(v2,i);
  }
  return result;
}

// vector printing
void vector_print(my_vector* v){
  for(int i = 0; i < v->length; i++){
    printf("%.2f\t", vector_get(v,i));
  }
  printf("\n");
}