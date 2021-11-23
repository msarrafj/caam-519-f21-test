#include "my_vector_struct.h"
#include <stdlib.h>
#include <stdio.h>

// implementation of the functions

// constructor
my_vector vector_constructor(const int length){

  // declaring a vector
  my_vector vec;
  vec.v = NULL;
  
  // return if a bad length value is given
  if (length <= 0){
    printf("vector_constructor: the vector length is negative!\n");
    vec.length = length;
    vec.status = 1;
    return vec;
  }
  else{ // length > 0 and we try to allocate memory
    vec.length = length;
    vec.v = (double*) calloc(length, sizeof(double));
    if(vec.v != NULL){ //A == NULL means out of memory
      vec.status = 0;
    }
    else{
      vec.status = 1;
    }
    return vec;
  }
}

// destructor
void vector_destructor(my_vector* vec){
  free(vec->v);
  // status is nonzero indicating the vector cannot be used.
  vec->status = 1;
}

// set <-- this function writes to a value in a given index, in the vector
void vector_set(my_vector* vec, const int index, const double value){
  if (vec->status == 0){
    if (index > vec->length - 1){
      printf("vector_set: index exceeds vector length\n");
    }
    else{
      // set value.
      vec->v[index] = value;
    }
  }
  else {
    printf("vector_set: this vector cannot be used now\n");
  }
}

// get <-- this function reads the a value from a given index, from the vector
double vector_get(my_vector* vec, const int index){
  double value = 0.0;
  if (vec->status == 0){
    if (index > vec->length - 1){
      printf("vector_get: index exceeds vector length\n");
    }
    else{
      // set value.
      value = vec->v[index];
    }
  }
  else {
    printf("vector_get: this vector cannot be used now\n");
  }
  return value;
}


// vector scalar multiplication
my_vector vector_scalar_multiplication(my_vector* v, double num){
  // initialized a new vector called w
  my_vector w = vector_constructor(v->length);

  // here the input is the scalar num and we have checked that v is a usable vector
  if (v->status == 0){

    //get the address of w for the pointer
    my_vector* ptr_w = &w;
    
    // for loop for scalar multiplication
    // continue ... [use vector_set() here]
    for (int i = 0; i < v->length; i++) {
	    //calculate the scalar multiple of each element
	    double mult = (v->v[i]) * (num);
	    vector_set(ptr_w, i, mult);
	   //update pointer 
	   //v++; 
    }

  }
  else{
    printf("vector_scalar_multiplication: this is an invalid vector we have inputted");
  }

  return w;
}

// continue ...
// implement vector_addition and vector_dot_product

// vector_addition
my_vector vector_addition(my_vector* v, my_vector* w){
	//check that vectors v and w are usable
	if (v->status == 0 && w-> status == 0)
	{
		//check that vector lengths match
		if (v->length == w->length)
		{
			//add vectors

			//initialize resultant vector u
			my_vector u = vector_constructor(v->length);

			//get address for u
			my_vector* ptr_u = &u;

			//for loop for vector addition
			for (int i = 0; i < v->length; i++) {
				//define variable sum which is the sum of each element
				int sum = (v->v[i]) + (w->v[i]);
				vector_set(ptr_u, i, sum);
			}
			
		}
		
		else{
			printf("lengths don't match");
		}
	}
	else{
		printf("vectors aren't usable");
	}

}


//vector_dot_product
double vector_dot_product(my_vector* v, my_vector* w){
	//check that vectors are usable
	if (v->status == 0 && w->status == 0)
	{
		//check that vector length is the same
		if (v->length == w->length)
		{
			//vector dot product

			//initialize result variable
			double result = 0.0;

			//for loop for dot product
			for (int i = 0; i < v->length; i++) {
				result += (vector_get(v, i)) * (vector_get(w, i));
				
			}
			return result;
		}
		else{
			printf("lengths don't match");
		}
	}
	else{
		printf("vectors aren't usable");
	}
}

