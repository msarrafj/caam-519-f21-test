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
  
  // construct w and ptr_w same as about
  my_vector w = vector_constructor(len);
  my_vector* ptr_w = &w;
  int w_array[4] = {1,-1,1,-2};
  for (int i = 0; i < sizeof(w_array)/sizeof(int); i++) {
    vector_set(ptr_w,i,w_array[i]);
  }
  
  // save and set a pointer to address of scalar multiply of w and -1
  my_vector nega = vector_scalar_multiplication(ptr_w,-1);
  my_vector* ptr_nega = &nega;
  
  // save and set a pointer to address of addition of v and -w 
  my_vector diff = vector_addition(ptr_v,negative);
  my_vector* ptr_diff = &diff;
  
  // save value of dot product into a double multi
  double multi = vector_dot_product(ptr_v,ptr_w);
  
  // print vector v-w with a for loop
  printf("V - W is:\n");
  for (int i = 0; i < ptr_diff->length; i++) {
    printf("%f\n", vector_get(ptr_diff,i));
  }
  
  // print result of dot product multi
  printf("V * W is: %f\n", multi);
  
  // free up the allocated memory
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
  vector_destructor(ptr_diff);
  vector_destructor(ptr_nega);
}
