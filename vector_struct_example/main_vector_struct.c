#include "my_vector_struct.h"
#include <stdlib.h>
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

  //lets start making vector w
  const int length = 4;
  my_vector w = vector_constructor(length);
  my_vector* ptr_w = &w;

  //this is the vector w
  int w_array[4] = {1,-1,1,-2};
  // putting vector w into the structur of my_vector using vector_set
  for (int i=0; i < sizeof(w_array)/sizeof(int); ++i){
	  vector_set(ptr_w, i, w_array[i]);
  }

  //assign array values v-w to pointer 
  
  //place array address of vector_addition in vec_add
  my_vector u = vector_addition(ptr_v, ptr_w);

  //get address for u
  my_vector* ptr_u = &u;

  printf("ptr_u = %p", ptr_u);

  //I tried various ways to print out the values of this new my_vector struct but I kept getting "Segmentation fault" error
  //for loop to print values of u
  //for (int i = 0; i < 4; i++){
//	 printf("value of u[%d] = %lf\n", i, ptr_u->v[i]);
  //} 
  //my_vector* ptr_u = &u;
  //print result
  //for (int i = 0; i < ptr_u->length; i++){
//	 printf("%lf", vector_get(ptr_u,i));
  //} 


  //calculate v*w
  printf("%lf", vector_dot_product(ptr_v, ptr_w));

  //print result
  //printf("%d", result);

  return 0;


}
