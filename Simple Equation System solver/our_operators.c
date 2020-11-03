#include <stdio.h>
#include "our_operators.h"

// -------

int sum(int x, int y) {return x+y;}
int difference(int x, int y) {return x-y;}
int product(int x, int y) {return x*y;}
int quotient(int x, int y) {return x/y;}
int rem(int x, int y) {return x%y;}
int less(int x, int y) {return x<y;}
int greater(int x, int y) {return x>y;}
int lessOrEqual(int x, int y) {return x<=y;}
int greaterOrEqual(int x, int y) {return x>=y;}
int equal(int x, int y) {return x==y;}
int not_equal(int x, int y) {return x!=y;}
int max(int x, int y) {return x <= y ? y : x;}
int min(int x, int y) {return x <= y ? x : y;}

double dbl_sum(double x, double y) {return x+y;}
double dbl_difference(double x, double y) {return x-y;}
double dbl_product(double x, double y) {return x*y;}
double dbl_quotient(double x, double y) {return x/y;}
int dbl_less(double x, double y) {return x<y;}
int dbl_greater(double x, double y) {return x>y;}
int dbl_lessOrEqual(double x, double y) {return x<=y;}
int dbl_greaterOrEqual(double x, double y) {return x>=y;}
int dbl_equal(double x, double y) {return x==y;}
int dbl_not_equal(double x, double y) {return x!=y;}
double dbl_max(double x, double y) {return x <= y ? y : x;}
double dbl_min(double x, double y) {return x <= y ? x : y;}
