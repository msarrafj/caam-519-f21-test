#include "my_vector_struct.h"
#include <stdio.h>
#include <stdlib.h>


void print_vec(my_vector* v){
  // print entries in vector
  for (int i = 0; i < v->length; i++){
    printf("%f ", v->v[i]);
  }
  printf("\n");
}

int main(){

  // construct vectors v and w
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector* ptr_v = &v;
  
  my_vector w = vector_constructor(len);
  my_vector* ptr_w = &w;

  // set values for v and w
  int v_array[4] = {-1,5,2,3};
  int w_array[4] = {1,-1,1,-2};
  // putting in vector v and w into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    vector_set(ptr_v,i,v_array[i]);
    vector_set(ptr_w,i,w_array[i]);
  }
  //print v
  printf("v = ");
  print_vec(ptr_v);
  
  //print w
  printf("w = ");
  print_vec(ptr_w);
  
  //compute and print v - w
  my_vector mw = vector_scalar_multiplication(ptr_w,-1); //mw = -w
  my_vector* ptr_mw = &mw;
  my_vector vmw = vector_addition(ptr_v, ptr_mw); //vmw = v + -w
  my_vector* ptr_vmw = &vmw;
  printf("v - w = ");
  print_vec(ptr_vmw);

  //compute and print dot(v,w)
  printf("vTw = ");
  printf("%f\n", vector_dot_product(ptr_v, ptr_w));
  
  //free allocated vectors
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
  vector_destructor(ptr_mw);
  vector_destructor(ptr_vmw);

  return 0;
}
