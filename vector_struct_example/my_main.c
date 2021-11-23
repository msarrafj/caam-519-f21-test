#include "my_vector_struct.h"
#include <stdio.h>

int main(){

  // lets start making vector v
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector* ptr_v = &v;
  my_vector w = vector_constructor(len);
  my_vector* ptr_w= &w;
  my_vector mainresult1;
  my_vector* ptr_mainresult1=&mainresult1;
  my_vector mainresult2;
  my_vector *ptr_mainresult2=&mainresult2;
  double num=-1;

  // this is the vector v
  int v_array[4] = {-1,5,2,3};
  int w_array[4] = {1,-1,1,-2};
  
  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;i++){
    vector_set(ptr_v,i,v_array[i]);
  }
  for (int j=0; j< sizeof(w_array)/sizeof(int);j++){
    vector_set(ptr_w,j,w_array[j]);
  }
  // continue ...
  //test case for dot product.
  printf("The result for dot product of vector v and w is = %f \n",vector_dot_product(ptr_v,ptr_w));

  //test case for scalr multiplication
  //because in order to implement v-w, we need to multiply (-1) in front of w.
  mainresult1=vector_scalar_multiplication(ptr_w,num);

  //print out the value of vector w (after multiplied with -1.)
  printf("first, do scalar multiplication for vector w.\n");
  for (int k=0;k<len;k++){
    printf("%f \n",vector_get(ptr_mainresult1,k));
  }
  //test case for vector addition.
  mainresult2=vector_addition(ptr_v,ptr_mainresult1);
  printf("Then, using vector_addition function, the result for v-w is:\n");
  for (int m=0;m<len;m++){
    //print value after substitution
    printf("%f\n", vector_get(ptr_mainresult2,m));
  }
  //destruct all the constructed vector. free their memory. 
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
  vector_destructor(ptr_mainresult1);
  vector_destructor(ptr_mainresult2);
  return 0;
}
