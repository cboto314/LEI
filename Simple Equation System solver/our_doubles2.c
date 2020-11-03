#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#include "our_ints.h"
#include "our_doubles.h"
#include "our_doubles2.h"
#include "our_operators.h"

// -------

double **doubles2_new(int rows, int cols)
{
  double **result = (double **) malloc(rows * sizeof(double *));
  double *p  = doubles_new(rows * cols);
  for (int i = 0; i < rows; i++)
    result[i] = p + i * cols;
  return result;
}

void doubles2_get(double **a, int rows, int cols)
{
  doubles_get_some(*a, rows * cols);
}

void doubles2_get_by_row_column_some(double **a, int n)
{
  int i, j;
  while (n--)
  {
    scanf("%d%d", &i, &j);
    scanf("%lf", &a[i][j]);
  }
}

void doubles2_get_by_row_column(double **a)
{
  int i, j, x;
  while (scanf("%d%d%d", &i, &j, &x) != EOF)
    a[i][j] = x;
}

void doubles2_printf(char *fmt, double **a, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
    doubles_printfln(fmt, a[i], cols);
}

void doubles2_exchange_rows(double **a, int x, int y)
{
  double *m = a[x];
  a[x] = a[y];
  a[y] = m;
}

void doubles2_column(double **a, int rows, int cols, int x, double *b)
{
  for (int i = 0; i < rows; i++)
    b[i] = a[i][x];
}

void doubles2_multiply_by_array(double **a, int rows, int cols, const double *b, double *c)
{
  for (int i = 0; i < rows; i++)
    c[i] = doubles_inner_product(a[i], b, cols);
}

void doubles2_accumulate(double **a, int rows, int cols, double **z)
{
  for (int i = 0; i < rows; i++)
    z[i][0] = 0;
  for (int j = 1; j < cols; j++)
    z[0][j] = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      z[i+1][j+1] = a[i][j] + z[i][j+1] + z[i+1][j] - z[i][j];
}

void test_doubles2(void)
{
  int r, c;
  double **m;
  double **acc;
  scanf("%d%d", &r, &c);
  m = doubles2_new(r, c);
  doubles2_get(m, r, c);
  doubles2_printf("%3d", m, r, c);
  acc = doubles2_new(r+1, c+1);
  doubles2_accumulate(m, r, c, acc);
  doubles2_printf("%5d", acc, r+1, c+1);
}

void doubles2_copy(double **a, int rows, int columns, double **b)
{
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      b[i][j] = a[i][j];
}


void doubles2_transpose(double **a, int rows, int columns, double **b)
{
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      b[j][i] = a[i][j];
}

void doubles2_multiply(double **a, int rows_a, int cols_a,
  double **b, int rows_b, int cols_b,
  double **c)
{
  assert(cols_a == rows_b);
  double **z = doubles2_new(cols_b, rows_b);
  doubles2_transpose(b, rows_b, cols_b, z);
  for (int i = 0; i < rows_a; i++)
    for (int j = 0; j < cols_b; j++)
      c[i][j] = doubles_inner_product(a[i], z[j], cols_a);
}

