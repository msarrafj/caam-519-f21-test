#include "my_vector_struct.h"
#include <stdio.h>

int main(){

  // lets start making vector v
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector* ptr_v = &v;
  my_vector w = vector_constructor(len);
  my_vector* ptr_w = &w;

  // this is the vector v
  int v_array[4] = {-1,5,2,3};
  int w_array[4] = {1,-1,1,-2};
  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    vector_set(ptr_v,i,v_array[i]);
    vector_set(ptr_w,i,w_array[i]);
  }
  // continue ...

  my_vector u = vector_scalar_multiplication(ptr_w, -1.0);
  my_vector* ptr_u = &u;
  my_vector diff = vector_addition(ptr_v, ptr_u);
  my_vector* ptr_diff = &diff;
  double dot = vector_dot_product(ptr_v, ptr_w);

  printf("v-w=(%f,", vector_get(ptr_diff, 0));
  printf("%f,", vector_get(ptr_diff, 1));
  printf("%f,", vector_get(ptr_diff, 2));
  printf("%f)\n", vector_get(ptr_diff, 3));
  printf("dot(v,w)=%f\n", dot);

  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
  vector_destructor(ptr_u);
  vector_destructor(ptr_diff);
}


