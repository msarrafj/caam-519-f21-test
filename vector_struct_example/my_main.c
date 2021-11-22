#include "my_vector_struct.h"
#include <stdio.h>

int main(){

  // lets start making vectors v and w
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector* ptr_v = &v;
  my_vector w = vector_constructor(len);
  my_vector* ptr_w = &w;

  // this is the vector v
  int v_array[4] = {-1,5,2,3};
  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    vector_set(ptr_v,i,v_array[i]);
  }
  // we do the same thing for w
  int w_array[4] = {1,-1,1,-2};
  for (int i=0; i < sizeof(w_array)/sizeof(int) ;++i){
    vector_set(ptr_w,i,w_array[i]);
  }

  // We get the negative of w for the subtratction
  my_vector minusw = vector_scalar_multiplication(ptr_w,-1);
  my_vector* ptr_mw = &minusw;
  // we add v and negative w
  my_vector u = vector_addition(ptr_v,ptr_mw);
  my_vector* ptr_u = &u;
  // we print out our vector
  printf("(-1 5 2 3)-(1 -1 1 -2) = (");
  for (int i = 0; i < ptr_u->length; i++){
  	printf("%f ",vector_get(ptr_u,i));
  }printf(")\n");
  
  // we get the dot product of v and w and print it out
  double x = vector_dot_product(ptr_v,ptr_w);
  printf("v dot w is %f\n", x);
  
  // we free everything using the destructor
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
  vector_destructor(ptr_u);
  vector_destructor(ptr_mw);
}
