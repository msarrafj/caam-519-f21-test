#include "my_vector_struct.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

  // lets start making vector v
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector* ptr_v = &v;

  // this is the vector v
  int v_array[4] = {-1,5,2,3};
  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    vector_set(ptr_v,i,v_array[i]);
  }

  // making vector w
  my_vector w = vector_constructor(len);
  my_vector* ptr_w = &w;

  // this is the vector w
  int w_array[4] = {1,-1,1,-2};
  // putting in vector w into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    vector_set(ptr_w,i,w_array[i]);
  }

  // making a negtive w vector
  my_vector neg_w = vector_scalar_multiplication(ptr_w, -1);
  my_vector* ptr_neg_w = &neg_w;

  // adding v and negtive w to get v-w
  my_vector v_minus_w = vector_addition(ptr_v, ptr_neg_w);
  my_vector* ptr_v_minus_w = &v_minus_w;

  // getting dot porduct between v and w
  double v_dot_w = vector_dot_product(ptr_v, ptr_w);

  // printing each component of the v-w vector
  printf("The vector v-w is: \n");
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    printf("%f \n", vector_get(ptr_v_minus_w,i));
  }

  // printing the dot product of the two vectors
  printf("\n The dot product between v and w is: \n");
  printf("%f \n",v_dot_w);

  // destroying all vector pointers
  vector_destructor(ptr_neg_w);
  vector_destructor(ptr_v_minus_w);
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
}
