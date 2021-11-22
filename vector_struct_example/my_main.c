#include <stdio.h>
#include "my_vector_struct.h"

int main()
{

  // lets start making vector v
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector *ptr_v = &v;

  // this is the vector v
  int v_array[4] = {-1, 5, 2, 3};
  // putting in vector v into the structure of my_vector using vector_set
  for (int i = 0; i < sizeof(v_array) / sizeof(int); ++i)
  {
    vector_set(ptr_v, i, v_array[i]);
  }
  // continue ...
  my_vector w = vector_constructor(len);
  my_vector *ptr_w = &w;
  int w_array[4] = {1, -1, 1, -2};
  for (int i = 0; i < sizeof(w_array) / sizeof(int); ++i)
    vector_set(ptr_w, i, w_array[i]);

  my_vector temp = vector_scalar_multiplication(&w, -1.0);
  my_vector result1 = vector_addition(&v, &temp);
  printf("the result of v-w is:\n");
  for (int i = 0; i < result1.length; ++i)
    printf("%g\n", vector_get(&result1, i));
  double result2 = vector_dot_product(&w, &v);
  printf("the result of v*w is: %g\n", result2);
  vector_destructor(&v);
  vector_destructor(&w);
  vector_destructor(&temp);
  vector_destructor(&result1);
}
