// this is the guard rail
#ifndef MY_VECTOR_STRUCT_H
#define MY_VECTOR_STRUCT_H

// definition of the vector struct
typedef struct{

  // the length of the vector
  int length;

  // status of the vector
  // status = 0 means allocation was successfull
  // and vector is ready to use.
  // status != 0 means vector is not ready to use
  // and something bad happened in its construction.
  int status;

  // the vector!
  double* v;
  
} my_vector;

// prototypes for the functions we need.

// constructor
my_vector vector_constructor(const int length);

// destructor
void vector_destructor(my_vector* vec);

// set <-- this function writes to a value in a given index, in the vector
void vector_set(my_vector* vec, const int index, const double value);

// get <-- this function reads the a value from a given index, from the vector
double vector_get(my_vector* vec, const int index);

// adding the two vectors
my_vector vector_addition(my_vector* v, my_vector* u);

// vector_dot_product
double vector_dot_product(my_vector* v, my_vector* u);

// vector_scalar_multiplication
my_vector vector_scalar_multiplication(my_vector* v, double num);

// vector_print
void vector_print(my_vector* v);

#endif
// Comment
