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
  //vector constructor returns a struct variable.
  //initialize a double variable.
  double multiplication;
  my_vector w = vector_constructor(v->length);
  //get the address of w for the pointer
    my_vector* ptr_w = &w;

  // here the input is the scalar num and we have checked that v is a usable vector
  if (v->status == 0){

    
    
    // for loop for scalar multiplication
    // continue ... [use vector_set() here]
    for(int ii=0;ii< v->length;ii++){
      //get the value after element is multiplied with scalr.
      multiplication=vector_get(v,ii)*num;
      //update this multiplication into w.
      vector_set(ptr_w,ii, multiplication);
    }

  }
  else{
    printf("vector_scalar_multiplication: this is an invalid vector we have inputted");
  }
  //return w
  return w;
  // destruct the intermediate struct w (and free the memory for storying w.)
  vector_destructor(ptr_w);
}

// continue ...
// implement vector_addition and vector_dot_product

//function:vector_addition
my_vector vector_addition(my_vector* v, my_vector* u){
  //get the value of length.
  my_vector result1 = vector_constructor(v->length);
  //define pointer
  my_vector* ptr_result1=&result1;
  //if the length of vectors is different, we should change the status.
  if (v->length != u->length){
    printf("vector_addition: two vector length must be the same");
    v->status=1;
    u->status=1;
  }
  else{
    //define a double variable addition (for elementwise addtion.)
    double addition;
    
    for (int ii=0;ii < v->length; ii++)
    {
      //get element value and then add togther.
      addition=vector_get(v, ii)+vector_get(u,ii);
      //set the addition number into result1
      vector_set(ptr_result1, ii, addition);
    }
    
  }
  return result1;
  //destruct the intermidiate struct result1.(and also free the memory for storing memory.)
  vector_destructor(ptr_result1);


}

//function: vector_dot_product for dot producation.
double vector_dot_product(my_vector* v, my_vector* u){
  //initialize summation to 0.
  double summation=0;
  //initialize a struct
  my_vector result3=vector_constructor(v->length);
  //define a pointer.
  my_vector* ptr_result3=&result3;
  //check whether the length is same.
  if (v->length != u->length){
    printf("vector_dot_product: two vector length must be the same.");
    //if not the same, change the stauts.
    v->status=1;
    u->status=1;
  }
  else{
    //define elementwise product variable.
    double elemtwiseproduct;
    
    for (int ii=0; ii<= v->length-1; ii++)
    {
      //get the value and multiply with each other.
      elemtwiseproduct=vector_get(v,ii)*vector_get(u,ii);
      //set the result of elementwiseproduct into result3.
      vector_set(ptr_result3,ii,elemtwiseproduct);
    }
    summation=0;
    for (int jj=0; jj<= v->length-1;jj++)
    {
      //implement the summation of element for result3.
      summation+=vector_get(ptr_result3,jj);
    }
  }
  return summation;
  //destruct the result3 (and free the memory for storing this vector.)
  vector_destructor(ptr_result3);
}

