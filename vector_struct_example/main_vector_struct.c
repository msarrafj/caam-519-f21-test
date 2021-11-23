#include "my_vector_struct.h"
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
  // continue ...

  my_vector w = vector_constructor(len);
  my_vector *ptr_w = &w;
  int w_array[4] = {1, -1, 1, -2};
  for (int i = 0; i < sizeof(w_array) / sizeof(int); ++i)
    vector_set(ptr_w, i, w_array[i]);

  my_vector scalar = vector_scalar_multiplication(ptr_w, -1.0);
  my_vector addition = vector_addition(ptr_v, &scalar);
  
  printf("the result of vector addition is:");
  
  for (int i = 0; i < addition.length; ++i)
    printf("\n  %g", vector_get(&addition, i));
  
    
  double dot_product = vector_dot_product(ptr_w, ptr_v);
  printf("\nthe result of dot product is: %g\n", dot_product);
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
  vector_destructor(&scalar);
  vector_destructor(&addition);
  
}
