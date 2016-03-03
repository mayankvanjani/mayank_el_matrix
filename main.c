#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
  int i, j;
  double counter = .5;
  double mult = 2.5;
  screen s;
  struct matrix *edges;
  struct matrix *transform;
  struct matrix *tester;
  struct matrix *identity;
  struct matrix *tester2;
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  tester = new_matrix(4, 4);
  identity = new_matrix(4, 4);
  tester2 = new_matrix(4, 2);  

  clear_matrix( edges );
  printf("Edge Matrix:\n");
  print_matrix( edges );
  /*
  printf("Transform Matrix:\n");
  print_matrix( transform );
  */
  counter = 0;
  for (i = 0; i < tester->rows; i++ ) {
    for (j = 0; j < tester->cols; j++ ) {
      tester->m[i][j] = counter;
      counter += 1;
    }
  }
  printf("Tester Matrix:\n");
  print_matrix( tester );

  counter = 0;
  for (i = 0; i < tester2->rows; i++ ) {
    for (j = 0; j < tester2->cols; j++ ) {
      tester2->m[i][j] = 1;
    }
  }
  printf("Tester2 Matrix:\n");
  print_matrix( tester2 );

  printf("\n\n");
  
  ident( identity );
  /*
  printf("Testing Identity: Identity Matrix\n");
  print_matrix( identity );
  
  printf("Testing Scalar Multiplication ( 2.5 * Tester )\n");
  scalar_mult( mult, tester );
  print_matrix( tester );
  
  printf("Testing Matrix Multiplication With Identity => SAME\n");  
  matrix_mult( identity, tester );
  print_matrix( tester );
  printf("Testing Matrix Multiplication With (4x4) and (4x2)\n");  
  matrix_mult( tester, tester2 );
  print_matrix( tester2 );
  */
  printf("\n\n");
  printf("Tester Before\n");
  clear_matrix( tester );
  print_matrix( tester );
  /*
  printf("Adding Point to tester\n");
  add_point( tester, 1, 2, 3);
  print_matrix( tester );
  printf("\nAdding Point to tester again\n");
  add_point( tester, 4, 5, 6);
  print_matrix( tester );
  */
  printf("Adding Edge to Tester\n");
  add_edge( tester, 1, 1, 1, 2, 2, 2 );
  add_edge( tester, 3, 3, 3, 4, 4, 4 );
  add_edge( tester, 5, 5, 5, 6, 6, 6 );
  print_matrix( tester );
  
  free_matrix( tester );
  free_matrix( tester2 );
  free_matrix( transform );
  free_matrix( edges );
}  
