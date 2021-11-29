#include "inc/my_vector_struct.h"
#include <stdio.h>

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

  // lets start making vector w
  my_vector w = vector_constructor(len);
  my_vector* ptr_w = &w;

  // this is the vector w
  int w_array[4] = {1,-1,1,-2};
  // putting in vector w into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    vector_set(ptr_w,i,w_array[i]);
  }
  
  // calculations
  my_vector minus_w = vector_scalar_multiplication(&w,-1);
  my_vector result_1 = vector_addition(&v,&minus_w);
  double result_2 = vector_dot_product(&v,&w);

  // output
  printf("Vector V:\t");
  vector_print(&v);

  printf("Vector W:\t");
  vector_print(&w);

  printf("\nV - W:\t");
  vector_print(&result_1);

  printf("V * W:\t%2.f\n", result_2);

  // cleanup
  vector_destructor(&v);
  vector_destructor(&w);
  vector_destructor(&minus_w);
  vector_destructor(&result_1);
}
