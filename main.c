#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  double mult = 2.5;
  screen s;
  struct matrix *edges;
  struct matrix *transform;
  struct matrix *tester;
  
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  tester = new_matrix(4, 4);
  
  printf("Edge Matrix:\n");
  print_matrix( edges );
  printf("Transform Matrix:\n");
  print_matrix( transform );
  printf("Tester Matrix:\n");
  print_matrix( tester );

  printf("\n\n");
  printf("Testing Identity on Tester\n");
  ident( tester );
  print_matrix( tester );
  printf("Testing Scalar Multiplication\n");
  scalar_mult( mult, tester );
  print_matrix( tester );
  
  free_matrix( transform );
  free_matrix( edges );
}  
