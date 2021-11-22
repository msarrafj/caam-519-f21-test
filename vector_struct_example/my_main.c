#include "my_vector_struct.h"
#include <stdio.h>

int main(){

  // lets start by making vector v
  const int lenv = 4;
  my_vector v = vector_constructor(lenv);
  my_vector* ptr_v = &v;

  // this is the vector v
  int v_array[4] = {-1,5,2,3};
  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    vector_set(ptr_v,i,v_array[i]);
  }

  // now lets make vector w
  const int lenw = 4;
  my_vector w = vector_constructor(lenw);
  my_vector* ptr_w = &w;

  // this is the vector w
  int w_array[4] = {1,-1,1,-2};
  // putting in vector w into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(w_array)/sizeof(int) ;++i){
    vector_set(ptr_w,i,w_array[i]);
  }

  // subtracting w from v by multiplying w by -1
  my_vector u = vector_scalar_multiplication(ptr_w, -1);
  my_vector* ptr_u = &u;
  my_vector x = vector_addition(ptr_v, ptr_u);
  my_vector* ptr_x = &x;
  printf("v - w = [%f,%f,%f,%f]\n", vector_get(ptr_x,0), vector_get(ptr_x,1), vector_get(ptr_x,2), vector_get(ptr_x,3));

  // multiplying v and w via dot product
  printf("v * w = %f\n", vector_dot_product(ptr_v, ptr_w));

  return 0;
}
