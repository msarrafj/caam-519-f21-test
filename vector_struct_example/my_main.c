#include "my_vector_struct.h"
#include <stdio.h>

int main()
{

  // lets start making vector v
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector * ptr_v = &v;

  // this is the vector v
  int v_array[4] = {-1, 5, 2, 3};

  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ; ++i) 
  {
    vector_set(ptr_v,i,v_array[i]);
  }
  
  // lets start making vector w
  // length is still 4 as defined
  my_vector w = vector_constructor(len);
  my_vector * ptr_w = &w;
  
  // this is the vector w
  int w_array[4] = {1, -1, 1, 2}; 

  // putting in vector w into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(w_array)/sizeof(int) ; ++i) 
  {
    vector_set(ptr_w,i,w_array[i]);
  }

  // First, we compute v - w
  // Regard v - w as v + (-w) by using vector_scalar_multiplication on w
  my_vector neg_w = vector_scalar_multiplication(ptr_w, -1);
  my_vector * ptr_neg_w = &neg_w; 
  my_vector diff = vector_addition(ptr_v, ptr_neg_w);
  printf("v - w is \r\n");
   for (int i = 0; i < diff.length; ++i)
    printf("%g\n", vector_get(&diff, i));


  // Then, we compute v * w
  double dot_product = vector_dot_product(ptr_v, ptr_w);
  printf("v * w is %f\n ", dot_product);

  // Destructor vectors
  vector_destructor(&diff);
  vector_destructor(ptr_neg_w);
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
}
