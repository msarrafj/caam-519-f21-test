#include "my_vector_struct.h"
#include <stdio.h>

int main(){

  // lets start making vector v
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector* ptr_v = &v;

  // this is the vector v
  double v_array[4] = {-1,5,2,3};
  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(double) ;++i){
    vector_set(ptr_v,i,v_array[i]);
  }

  // Vector w
  my_vector w = vector_constructor(len);
  double w_array[4] = {1,-1,1,-2};
  for (int i=0; i < sizeof(w_array)/sizeof(double) ;++i){
    vector_set(&w,i,w_array[i]);
  }

  // v - w
  my_vector minus_w = vector_scalar_multiplication(&w, -1.);
  my_vector z1 = vector_addition(&v, &minus_w);
  printf("v - w = ");
  vector_pretty_print(&z1);
  printf("\n");

  // v dot w
  double z2 = vector_dot_product(&v, &w);
  printf("<v,w> = %f\n", z2);

  // Unnecessary to clean up the heap at the end of the program,
  // but it makes valgrind happy.
  vector_destructor(&v);
  vector_destructor(&w);
  vector_destructor(&minus_w);
  vector_destructor(&z1);
}
