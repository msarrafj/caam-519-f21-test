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
  double vec_mult = 0;

  // here the input is the scalar num and we have checked that v is a usable vector
  if (v->status == 0){

    //get the address of w for the pointer
    my_vector* ptr_w = &w;
    int vector1_len = v->length;
    
    // for loop for scalar multiplication
    for( int a = 0; a < vector1_len; a = a + 1 ){
        vec_mult = num*vector_get(v,a);
        vector_set(&w,a,vec_mult);
      }
    }

  // printing falure statment 
  else{
    printf("vector_scalar_multiplication: this is an invalid vector we have inputted");
  }

  return w;
}


my_vector vector_addition(my_vector* v, my_vector* u){
  // initialized a new vector called w
  my_vector w = vector_constructor(v->length);

  // getting both vectors lengths
  int vector1_len = v->length;
  int vector2_len = u->length;
  // setting a useful variable
  double vec_add = 0;

  // checking that vectors are of the same lenght and have correct status
  if (vector1_len == vector2_len && v->status == 0 && u->status == 0){
      
      // looping through each componenet and adding each together
      for( int a = 0; a < vector1_len; a = a + 1 ){
        vec_add = vector_get(v,a)+vector_get(u,a);
        // setting new vectors componenets
        vector_set(&w,a,vec_add);
      }
  }
  // printing failure statment
  else{
    printf("vector_addition: this is an invalid vector we have inputed");
  }
  return w;
  
}

double vector_dot_product(my_vector* v, my_vector* u){
  // getting lenght of both vectors
  int vector1_len = v->length;
  int vector2_len = u->length;

  //intizalizing the dot product
  double w = 0;

  // checking that vectors are of the same lenght and have correct status
  if (vector1_len == vector2_len && v->status == 0 && u->status == 0){

      // looping through each componenet and adding each together and adding that to the current value of w
      for( int a = 0; a < vector1_len; a = a + 1 ){
        w = w + vector_get(v,a)*vector_get(u,a);
      }
  }
  // printing failure statment
  else{
    printf("vector_dot_product: this is an invalid vector we have inputted");
  }
  
  return w;

}

