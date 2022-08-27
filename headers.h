

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>


enum NUM_ROOTS {
  ZERO,
  ONE_ROOT,
  TWO_ROOTS,
  INF = -1,
  ERROR_ROOTS = -2
  };

const int LEN = 200;
const double EPSILON = 0.0001;

int input_from_file(double *a, double *b, double *c, int *counter2);

int solve(double a, double b, double c, double *x1, double *x2, int *counter, int counter2);

int linear(double b, double c, double *x1, int *counter);

int kvadratic(double a, double b, double c, double *x1, double *x2, int *counter);

double compare_two(double num1, double num2);

int is_zero(double num);

void output_in_file(int counter, double x1, double x2);

