#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
  int i, j;
  screen s;
  color c;
  /*
  double counter = .5;
  double mult = 2.5;
  */
  struct matrix *edges;
  struct matrix *transform;
  struct matrix *identity;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  identity = new_matrix(4, 4);

  clear_matrix(edges);
  clear_matrix(transform);
  /*
Different Matrices for Testing Different Matrix Operations
  struct matrix *tester;
  struct matrix *tester2;
  tester2 = new_matrix(4, 2);  
  tester = new_matrix(4, 4);
  
  clear_matrix( edges );
  printf("Edge Matrix:\n");
  print_matrix( edges );
  clear_matrix( transform );
  printf("Transform Matrix:\n");
  print_matrix( transform );
  
//////////////////////////////////
Initializations of Tester Matrices
//////////////////////////////////
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

///////////////////////////////

IDENTITY
  printf("Testing Identity: Identity Matrix\n");
  print_matrix( identity );
  
SCALAR MULTIPLICATION
  printf("Testing Scalar Multiplication ( 2.5 * Tester )\n");
  scalar_mult( mult, tester );
  print_matrix( tester );
  
MATRIX MULTIPLICATION
  printf("Testing Matrix Multiplication With Identity => SAME\n");  
  matrix_mult( identity, tester );
  print_matrix( tester );
  printf("Testing Matrix Multiplication With (4x4) and (4x2)\n");  
  matrix_mult( tester, tester2 );
  print_matrix( tester2 );
  
  printf("\n\n");
  printf("Tester Before\n");
  clear_matrix( tester );
  print_matrix( tester );
  
ADDING POINTS
  printf("Adding Point to tester\n");
  add_point( tester, 1, 2, 3);
  print_matrix( tester );
  printf("\nAdding Point to tester again\n");
  add_point( tester, 4, 5, 6);
  add_point( tester, 7, 8, 9);
  add_point( tester, 10, 11, 12);
  add_point( tester, 13, 14, 15);
  print_matrix( tester );
  
ADDING EDGES
  printf("Adding Edge to Tester\n");
  add_edge( tester, 1, 1, 1, 2, 2, 2 );
  add_edge( tester, 3, 3, 3, 4, 4, 4 );
  add_edge( tester, 5, 5, 5, 6, 6, 6 );
  print_matrix( tester );

  free_matrix( tester );
  free_matrix( tester2 );


  ident( identity );
  int x0, y0, z0, x1, y1, z1;
  z0 = 0;
  z1 = 0;
  */
  /*
  for (i = 0; i < 10; i++) { 
    x0 = i * 10 + 10;
    y0 = i * 10 + 20;
    x1 = i;
    y1 = i;
    add_edge( edges, x0,y0,z0,x1,y1,z1 );
  }
  */
  //  print_matrix( edges );
  
  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

  /*
  //Bottom Left Square
  add_edge( edges, 0,0,0,0,YRES/2,0 );
  add_edge( edges, 0,YRES/2,0,XRES/2,YRES/2,0 );
  add_edge( edges, XRES/2,YRES/2,0,XRES/2,0,0 );
  add_edge( edges, XRES/2,0,0,0,0,0 );

  //Top Left
  add_edge( edges, 0,YRES/2,0,0,YRES,0 );
  add_edge( edges, 0,YRES,0,XRES/2,YRES,0 );
  add_edge( edges, XRES/2,YRES,0,XRES/2,YRES/2,0 );
  add_edge( edges, XRES/2,YRES/2,0,0,XRES/2,0 );

  //Top Right
  add_edge( edges, XRES/2,YRES,0,XRES,YRES,0 );
  add_edge( edges, XRES,YRES,0,XRES,YRES/2,0 );
  add_edge( edges, XRES,YRES/2,0,XRES/2,YRES/2,0 );
  add_edge( edges, XRES/2,YRES/2,0,XRES/2,YRES,0 );

  //Bottom Right
  add_edge( edges, XRES/2,YRES/2,0,XRES,YRES/2,0 );
  add_edge( edges, XRES,YRES/2,0,XRES,0,0 );
  add_edge( edges, XRES,0,0,XRES/2,0,0 );
  add_edge( edges, XRES/2,0,0,XRES/2,YRES/2,0 );
  
  add_edge( edges, 125,125,0, 125,375,0);
  add_edge( edges, 125,375,0, 375,375,0);
  add_edge( edges, 375,375,0, 375,125,0);
  add_edge( edges, 375,125,0, 125,125,0);
  */
  add_edge( edges, XRES/4,YRES/4,0, XRES/4,YRES/4*3,0 );
  add_edge( edges, XRES/4,YRES/4*3,0, XRES/4*3,YRES/4*3,0 );
  add_edge( edges, XRES/4*3,YRES/4*3,0, XRES/4*3,YRES/4,0 );
  add_edge( edges, XRES/4*3,YRES/4,0, XRES/4,YRES/4,0 );

  //  print_matrix( transform );
  transform = make_translate( 50, 50, 0 );
  matrix_mult( transform, edges );
  print_matrix( transform );
  //  transform = scalar_mult(.5, edge
  printf("\n");
  print_matrix( edges );
  draw_lines( edges, s, c );


  save_extension(s, "matrix.png" );
  display(s);

  free_matrix( transform );
  free_matrix( edges );
}  
