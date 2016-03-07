#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

#define PI 3.14159265

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
  clear_screen(s);

  //SCALAR MULT (DILATION)
  clear_matrix(edges);
  clear_matrix(transform);
  add_edge( edges, 1,1,0, 6,1,0 );
  add_edge( edges, 6,1,0, 6,6,0 );
  add_edge( edges, 6,6,0, 1,6,0 );
  add_edge( edges, 1,6,0, 1,1,0 );
  draw_lines(edges,s,c);
  
  for(i = 0; i < 55; i++){
    scalar_mult(1.09, edges);
    c.red = c.red - 4;
    draw_lines(edges,s,c);
  }

  //TRANSLATE
  clear_matrix(edges);
  clear_matrix(transform);
  c.red = MAX_COLOR;
  add_edge( edges, 0,YRES,0, 0,YRES-25,0 );
  add_edge( edges, 0,YRES-25,0, 25,YRES-25,0 );
  add_edge( edges, 25,YRES-25,0, 25,YRES,0 );
  add_edge( edges, 25,YRES,0, 0,YRES,0 );
  draw_lines(edges,s,c);
  
  for(i = 0; i < 20; i++){
    transform = make_translate( 25, -25, 0 );
    matrix_mult( transform, edges);
    c.green = c.green - 4;
    draw_lines(edges,s,c);
  }
  
  //ROTATION
  clear_matrix(edges);
  clear_matrix(transform);
  c.green = MAX_COLOR;
  add_edge( edges, XRES,0,0, XRES,25,0 );
  add_edge( edges, XRES,25,0, XRES-25,25,0 );
  add_edge( edges, XRES-25,25,0, XRES-25,0,0 );
  add_edge( edges, XRES-25,0,0, XRES,0,0 );
  draw_lines(edges,s,c);
  print_matrix( edges );

  for(i = 0; i < 20; i++){
    transform = make_rotZ( 4.5 );
    matrix_mult( transform, edges);
    c.blue = c.blue - 4;
    draw_lines(edges,s,c);
  }

  //Central Flower
  clear_matrix(edges);
  clear_matrix(transform);
  c.blue = MAX_COLOR;
  c.red = MAX_COLOR;
  c.green = MAX_COLOR / 2 + 50;
  add_edge( edges, 200,200,0, 200,300,0 );
  add_edge( edges, 200,300,0, 300,300,0 );
  add_edge( edges, 300,300,0, 300,200,0 );
  add_edge( edges, 300,200,0, 200,200,0 );
  draw_lines(edges,s,c);

  for(i = 0; i < 36; i++){
    transform = make_rotZ( 10 );
    matrix_mult( transform, edges);
    transform = make_translate( 50, -50, 0);
    matrix_mult( transform, edges);
    draw_lines(edges,s,c);
  }

  //NAME
  clear_matrix(edges);
  clear_matrix(transform);
  c.blue = MAX_COLOR;
  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  add_edge( edges, 250,0,0, 250,25,0 );//M
  add_edge( edges, 250,25,0, 263,0,0 );
  add_edge( edges, 263,0,0, 275,25,0 );
  add_edge( edges, 275,25,0, 275,0,0 );
  add_edge( edges, 280,0,0, 293,25,0 );//A
  add_edge( edges, 293,25,0, 305,0,0 );
  add_edge( edges, 287,13,0, 299,13,0 );
  add_edge( edges, 310,0,0, 325,25,0 );//Y
  add_edge( edges, 318,13,0, 305,25,0 );
  add_edge( edges, 330,0,0, 343,25,0 );//A
  add_edge( edges, 343,25,0, 355,0,0 );
  add_edge( edges, 337,13,0, 349,13,0 );
  add_edge( edges, 360,0,0, 360,25,0 );//N
  add_edge( edges, 360,25,0, 385,0,0 );
  add_edge( edges, 385,0,0, 385,25,0 );
  add_edge( edges, 390,0,0, 390,25,0 );//K
  add_edge( edges, 390,13,0, 408,25,0 );
  add_edge( edges, 395,14,0, 408,0,0 );
  draw_lines(edges,s,c);

  save_extension(s, "matrix.png" );
  display(s);

  free_matrix( transform );
  free_matrix( edges );
}  
