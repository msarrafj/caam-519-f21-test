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
  my_vector* ptr_w = &w;

  // this is the vector w
  int w_array[4] = {1,-1,1,-2};
  // putting in vector w into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(w_array)/sizeof(int) ;++i){
    vector_set(ptr_w,i,w_array[i]);
  }
  
  my_vector scalar = vector_scalar_multiplication(ptr_w,-1);
  my_vector* ptr_s = &scalar;
  my_vector a = vector_addition(ptr_v,ptr_s);
  my_vector* ptr_a = &a;
  double dot_product_result = vector_dot_product(ptr_v, ptr_w);
    
    
  printf("the result of v-w is: [");
  for(int i=0; i < a.length ;++i){
    printf("%f,",vector_get(ptr_a,i));
  }
  printf("]\n");
    
    
  printf("the result of v.w is: %f",dot_product_result);
    
  vector_destructor(ptr_a);
  vector_destructor(ptr_s);
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
}
