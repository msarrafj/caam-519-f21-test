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
  
  // lets make w
  my_vector w = vector_constructor(len);
  my_vector* ptr_w = &w;
  int w_array[4] = {1,-1,1,-2};
  for (int i = 0; i < sizeof(w_array)/sizeof(int) ; i++) {
    vector_set(ptr_w,i,w_array[i]);
  }
  
  // v - w
  my_vector neg_w = vector_scalar_multiplication(ptr_w, -1.0);
  my_vector* ptr_neg_w = &neg_w;
  my_vector u = vector_addition(ptr_v, ptr_neg_w);
  printf("v - w = {");
  for (int i = 0; i < len-1; i++) {
    printf("%f, ", u.v[i]);
  }
  printf("%f}\n", u.v[len-1]);
  vector_destructor(&u);
  vector_destructor(ptr_neg_w);

  // dot(v,w)
  double dot = vector_dot_product(ptr_v, ptr_w);
  printf("v dotted with w is %f\n", dot);
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
}
