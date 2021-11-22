#include "my_vector_struct.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

  // lets start making vector v
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector* ptr_v = &v;

  // this is the vector v
  int v_array[4] = {-1,5,2,3};
  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    vector_set(ptr_v,i,v_array[i]); //setting the elements for the vector v
  }

  // lets start making vector w
  my_vector w = vector_constructor(len);
  my_vector* ptr_w = &w;

  // this is the vector w
  int w_array[4] = {1,-1,1,-2};
  // putting in vector w into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(w_array)/sizeof(int) ;++i){
    vector_set(ptr_w,i,w_array[i]); //setting the elements for vector w
  }
  
  // defining and computing the appropriate vector structs
  my_vector minus_w = vector_scalar_multiplication(ptr_w, -1);
  my_vector* ptr_minus_w = &minus_w;
  my_vector v_minus_w = vector_addition(ptr_v, ptr_minus_w);
  my_vector* ptr_v_minus_w = &v_minus_w; // pointer to desired vector struct
  double v_dot_w = vector_dot_product(ptr_v, ptr_w); // desired dot product

  printf("The vector v - w is as follows:\n");
  for (int i = 0; i < len; i++) {
	  printf("%f\n", ptr_v_minus_w->v[i]); // printing the elements of the vector v - w
  }

    // here we deallocate the memory in the heap that was used by the vector structs
    vector_destructor(ptr_minus_w);
    vector_destructor(ptr_v_minus_w);
    vector_destructor(ptr_v);
    vector_destructor(ptr_w);

  printf("The dot product of v and w is %f\n", v_dot_w); // printing the dot product of v and w
}
