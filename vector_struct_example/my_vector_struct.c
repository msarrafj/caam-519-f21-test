#include "my_vector_struct.h"
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
    
    // for loop for scalar multiplication
    // continue ... [use vector_set() here]
    for (int i = 0; i < w.length ; i++) {
      vector_set(ptr_w, i, num * vector_get(v, i));
    }

  }
  else{
    printf("vector_scalar_multiplication: this is an invalid vector we have inputted");
  }

  return w;
}

// continue ...
// implement vector_addition and vector_dot_product

// vector_addtion
my_vector vector_addition(my_vector *v, my_vector *u){
  // set w to store the value of v + u
  my_vector w = vector_constructor(v->length);
 if (v->status == 0 && u->status == 0 && v->length == u->length) {
    my_vector* ptr_w = &w;
    for (int i = 0; i < w.length ; i++) {
      vector_set(ptr_w, i, vector_get(v, i) + vector_get(u, i));
    }
  }
  else {
    printf("One of conditions that is not obeyed: 1: Both status of input ventors should be 0. (which means vectors can be used) 2: Two input vectors should have same size in order to addtion");
  }
  return w;
}

// vector_dot_product
double vector_dot_product(my_vector *v, my_vector *u){
  double dot_product = 0;
  if (v->status == 0 && u->status == 0 && v->length == u->length) {
    for (int i = 0; i < u->length ; i++) {
      dot_product += vector_get(v, i) * vector_get(u, i);
    }
  }
  else {
    printf("One of conditions that is not obeyed: 1: Both status of input ventors should be 0. (which means vectors can be used) 2: Two input vectors should have same size in order to addtion");
  }

  return dot_product;
}