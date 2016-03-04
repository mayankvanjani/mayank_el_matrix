#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"

#define PI 3.14159265

/*-------------- struct matrix *new_matrix() --------------
Inputs:  int rows
         int cols 
Returns: 

Once allocated, access the matrix as follows:
m->m[r][c]=something;
if (m->lastcol)... 
*/
struct matrix *new_matrix(int rows, int cols) {
  double **tmp;
  int i;
  struct matrix *m;

  tmp = (double **)malloc(rows * sizeof(double *));
  for (i=0;i<rows;i++) {
      tmp[i]=(double *)malloc(cols * sizeof(double));
    }

  m=(struct matrix *)malloc(sizeof(struct matrix));
  m->m=tmp;
  m->rows = rows;
  m->cols = cols;
  m->lastcol = 0;

  return m;
}


/*-------------- void free_matrix() --------------
Inputs:  struct matrix *m 
Returns: 

1. free individual rows
2. free array holding row pointers
3. free actual matrix
*/
void free_matrix(struct matrix *m) {

  int i;
  for (i=0;i<m->rows;i++) {
      free(m->m[i]);
    }
  free(m->m);
  free(m);
}


/*======== void grow_matrix() ==========
Inputs:  struct matrix *m
         int newcols 
Returns: 

Reallocates the memory for m->m such that it now has
newcols number of collumns
====================*/
void grow_matrix(struct matrix *m, int newcols) {
  
  int i;
  for (i=0;i<m->rows;i++) {
      m->m[i] = realloc(m->m[i],newcols*sizeof(double));
  }
  m->cols = newcols;
}


/*-------------- void print_matrix() --------------
Inputs:  struct matrix *m 
Returns: 

print the matrix
*/
void print_matrix(struct matrix *m) {
  int i, j;
  for (i = 0; i < m->rows; i++) {
    for (j = 0; (j < m->cols) ; j++ ) {
      printf("m->[%d][%d]:%.1lf  ", i, j, m->m[i][j]);
    }
    printf("\n");
  }
}

/*-------------- void ident() --------------
Inputs:  struct matrix *m <-- assumes m is a square matrix
Returns: 

turns m in to an identity matrix
*/
void ident(struct matrix *m) {
  int i, j;
  for (i = 0; i < m->rows; i++ ) {
    for (j = 0; j < m->cols; j++ ) {
      if ( i == j )
	m->m[i][j] = 1;
      else
	m->m[i][j] = 0;
    }
  }
}

void clear_matrix(struct matrix *m) {
  int i, j;
  for ( i = 0; i < m->rows; i++ ) {
    for ( j = 0; j < m->cols; j++ ) {
      m->m[i][j] = 0.0;
    }
  }
}

/*-------------- void scalar_mult() --------------
Inputs:  double x
         struct matrix *m 
Returns: 

multiply each element of m by x
*/
void scalar_mult(double x, struct matrix *m) {
  int i, j;
  for (i = 0; i < m->rows; i++ ) {
    for (j = 0; j < m->cols; j++ ) {
      m->m[i][j] = m->m[i][j] * x;
    }
  }
  //  printf("\nchecking %G ", m->m[i][j]);
}


/*-------------- void matrix_mult() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 

a*b -> b
*/
void matrix_mult(struct matrix *a, struct matrix *b) {
  int i, j, counter;
  double sum = 0.0;
  if (a->cols != b->rows) {
    printf("Can't multiply matrices, row and column mismatch\n");
    return;
  }
  struct matrix *test;
  test = new_matrix(b->rows,b->cols);
  copy_matrix( b, test );
  
  for (i = 0; i < a->rows; i++ ) {
    for (j = 0; j < test->cols; j++ ) {
      sum = 0; 
      counter = 0;
      while (counter < a->cols ) {
	sum += (a->m[i][counter] * test->m[counter][j]);
	counter++;
      }
      b->m[i][j] = sum;
    }
  }
  b->rows = a->rows;
  b->lastcol = a->cols - 1;
}

/*-------------- void copy_matrix() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 

copy matrix a to matrix b
*/
void copy_matrix(struct matrix *a, struct matrix *b) {

  int r, c;

  for (r=0; r < a->rows; r++) 
    for (c=0; c < a->cols; c++)  
      b->m[r][c] = a->m[r][c];  
}

/*======== struct matrix * make_translate() ==========
Inputs:  int x
         int y
         int z 
Returns: The translation matrix created using x, y and z 
as the translation offsets.
====================*/

struct matrix * make_translate(double x, double y, double z) {
  struct matrix * answer;
  answer = new_matrix(4,4);
  int i, j;
  for (i = 0; i < answer->rows; i++ ) {
    for (j = 0; j < answer->cols; j++ ) {
      if (i == j)
        answer->m[i][j] = 1;
      else if ( j == 3 ) {
	if (i == 0)
	  answer->m[i][j] = x;
	if (i == 1)
          answer->m[i][j] = y;
	if (i == 2)
          answer->m[i][j] = z;
      }
      else 
	answer->m[i][j] = 0;
    }
  }
  return answer;
}

/*======== struct matrix * make_scale() ==========
Inputs:  int x
         int y
         int z 
Returns: The translation matrix creates using x, y and z
as the scale factors
====================*/
struct matrix * make_scale(double x, double y, double z) {
  struct matrix * answer;
  answer = new_matrix(4,4);
  int i, j;
  for (i = 0; i < answer->rows; i++ ) {
    for (j = 0; j < answer->cols; j++ ) {
      if (i == 0 && j == 0)
        answer->m[i][j] = x;
      else if (i == 1 && j == 1)
        answer->m[i][j] = y;
      else if (i == 2 && j == 2)
        answer->m[i][j] = z;
      else if (i == 3 && j == 3)
        answer->m[i][j] = 1;
      else
        answer->m[i][j] = 0;
    }
  }
  return answer;
}

/*======== struct matrix * make_rotX() ==========
Inputs:  double theta

Returns: The rotation matrix created using theta as the 
angle of rotation and X as the axis of rotation.
====================*/
struct matrix * make_rotX(double theta) {
  struct matrix * answer;
  answer = new_matrix(4,4);
  int i, j;
  for (i = 0; i < answer->rows; i++ ) {
    for (j = 0; j < answer->cols; j++ ) {

      if (i == 0 && j == 0)
        answer->m[i][j] = 1;
      else if (i == 3 && j == 3)
        answer->m[i][j] = 1;

      else if ( i == 1 ) {
        if (j == 1)
          answer->m[i][j] = cos( theta * (PI / 180));
        if (j == 2)
          answer->m[i][j] = -1 * sin( theta * (PI / 180));
      }
      else if ( i == 2 ) {
        if (j == 1)
          answer->m[i][j] = sin( theta * (PI / 180));
        if (j == 2)
          answer->m[i][j] = cos( theta * (PI / 180));
      }
      else
	answer->m[i][j] = 0;
    }
  }
   return answer;
}

/*======== struct matrix * make_rotY() ==========
Inputs:  double theta

Returns: The rotation matrix created using theta as the 
angle of rotation and Y as the axis of rotation.
====================*/
struct matrix * make_rotY(double theta) {
  struct matrix * answer;
  answer = new_matrix(4,4);
  int i, j;
  for (i = 0; i < answer->rows; i++ ) {
    for (j = 0; j < answer->cols; j++ ) {

      if (i == 1 && j == 1)
        answer->m[i][j] = 1;
      else if (i == 3 && j == 3)
        answer->m[i][j] = 1;

      else if ( i == 0 ) {
        if (j == 0)
          answer->m[i][j] = cos( theta * (PI / 180));
        if (j == 2)
          answer->m[i][j] = -1 * sin( theta * (PI / 180));
      } 
      else if (i == 2 ) {
	if (j == 0)
          answer->m[i][j] = sin( theta * (PI / 180));
        if (j == 2)
          answer->m[i][j] = cos( theta * (PI / 180));
      } 
      else
        answer->m[i][j] = 0;
    }
  }
  return answer;
}

/*======== struct matrix * make_rotZ() ==========
Inputs:  double theta

Returns: The rotation matrix created using theta as the 
angle of rotation and Z as the axis of rotation.
====================*/
struct matrix * make_rotZ(double theta) {
  struct matrix * answer;
  answer = new_matrix(4,4);
  int i, j;
  for (i = 0; i < answer->rows; i++ ) {
    for (j = 0; j < answer->cols; j++ ) {

      if (i == 2 && j == 2)
        answer->m[i][j] = 1;
      else if (i == 3 && j == 3)
        answer->m[i][j] = 1;

      else if ( i == 0 ) {
        if (j == 0)
          answer->m[i][j] = cos( theta * (PI / 180));
        if (j == 1)
          answer->m[i][j] = -1 * sin( theta * (PI / 180));
      }
      else if (i == 1 ) {
        if (j == 0)
          answer->m[i][j] = sin( theta * (PI / 180));
        if (j == 1)
          answer->m[i][j] = cos( theta * (PI / 180));
      }
      else
        answer->m[i][j] = 0;
    }
  }
  return answer;
}

