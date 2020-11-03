#ifndef _doubles2_h
#define _doubles2_h

double **doubles2_new(int rows, int cols);

void doubles2_get(double **a, int rows, int cols);
void doubles2_get_by_row_column_some(double **a, int n);
void doubles2_get_by_row_column(double **a);
void doubles2_printf(char *fmt, double **a, int rows, int cols);

void doubles2_exchange_rows(double **a, int r1, int r2);

void doubles2_column(double **a, int rows, int cols, int x, double *b);

void doubles2_multiply_by_array(double **a, int rows, int cols, const double *b, double *c);

// void doubles2_accumulate(double **a, int rows, int cols, double **b);

void doubles2_copy(double **a, int rows, int columns, double **b);
void doubles2_transpose(double **a, int rows, int columns, double **b);

void doubles2_multiply(double **a, int rows_a, int cols_a,
  double **b, int rows_b, int cols_b,
  double **c);

#endif
