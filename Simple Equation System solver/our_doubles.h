//
//  our_doubles.h
//
//  Created by Pedro Guerreiro on 01/11/2018.
//  Copyright © 2018 Pedro Guerreiro. All rights reserved.
//

#ifndef our_doubles_h
#define our_doubles_h

void doubles_println_basic(const double *a, int n);
void doubles_println_special(const double *a, int n);

void doubles_fprint(FILE *f, const double *a, int n, const char *separator);
void doubles_fprintln(FILE *f, const double *a, int n, const char *separator);
void doubles_print(const double *a, int n, const char *separator);
void doubles_println(const double *a, int n, const char *separator);
void doubles_print_two(const double *a, const double *b, int n);
void doubles_printf(const char *fmt, const double *a, int n);
void doubles_printfln(const char *fmt, const double *a, int n);
void doubles_fprintf(FILE *f, const char *fmt, const double *a, int n);
void doubles_fprintfln(FILE *f, const char *fmt, const double *a, int n);

int doubles_get(double *a);
int doubles_get_until(double terminator, double *a);
int doubles_get_some(double *a, int n);
int doubles_get_two(double *a, double *b);

double *doubles_new(int n);

int doubles_copy(const double *a, int n, double *b);

int doubles_fill(double x, int n, double *a);
int doubles_range(double start, int n, double *a);

int doubles_map(const double *a, int n, double f(double), double *b);
int doubles_map_with(const double *a, int n, double f(double, double), double x, double *b);
int doubles_map_with_2(const double *a, int n, double f(double, double), double x, double *b);

int doubles_zip(const double *a, const double *b, int n, double f(double, double), double *c);

int doubles_count(const double *a, int n, double x);
double doubles_sum(const double *a, int n);
double doubles_mean(const double *a, int n);
int doubles_remove(const double *a, int n, int x, double *b);
double doubles_max(const double *a, int n);
double doubles_min(const double *a, int n);
int doubles_argmax(const double *a, int n);
int doubles_argmin(const double *a, int n);
int doubles_indices(const double *a, int n, int x, int* b);
int doubles_find(const double *a, int n, double x);
int doubles_find_last(const double *a, int n, double x);

int doubles_equal(const double *a, int n, const double *b, int m);

int doubles_count_while(const double *a, int n, double x);
int doubles_count_while_not(const double *a, int n, double x);
int doubles_unique(const double *a, int n, double *b);
int doubles_groups(const double *a, int n, int *b);
int doubles_runs(const double *a, int n, double x, int *b);
int doubles_runs_not(const double *a, int n, double x, int *b);
int doubles_runs_starts(const double *a, int n, double x, int *b, int *c);
int doubles_runs_starts_not(const double *a, int n, double x, int *b, int *c);

int doubles_is_sorted(double *a, int n);
int doubles_rank(const double *a, int n, double x);
int doubles_bfind(const double *a, int n, double x);
void doubles_exchange(double *a, int x, int y);
int doubles_insert(double *a, int n, double x);
void doubles_isort(double *a, int n);
int doubles_merge(const double *a, int n, const double *b, int m, double *c);
void doubles_msort(double *a, int n);
void doubles_shuffle(double *a, int n);

double doubles_inner_product(const double *a, const double *b, int n);

double rand1();
int doubles_random(int x, int n, double *a);
int doubles_rand1(int n, double *a);

void unit_test_doubles_count(void);
void unit_test_doubles_sum(void);
void unit_test_doubles_remove(void);
void unit_test_doubles_max(void);
void unit_test_doubles_min(void);
void unit_test_doubles_argmax(void);
void unit_test_doubles_argmin(void);
void unit_test_doubles_indices(void);
void unit_test_doubles_find(void);
void unit_test_doubles_equal(void);
void unit_test_doubles_count_while(void);
void unit_test_doubles_count_while_not(void);
void unit_test_doubles_unique(void);
void unit_test_doubles_groups(void);
void unit_test_doubles_runs(void);
void unit_test_doubles_runs_not(void);
void unit_test_doubles_runs_starts(void);
void unit_test_doubles_runs_starts_not(void);

void our_doubles_unit_tests(void);

#endif
