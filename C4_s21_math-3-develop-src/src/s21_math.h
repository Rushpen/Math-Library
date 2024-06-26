#ifndef S21MATH
#define S21MATH
#include <float.h>
#include <limits.h>

#define PI 3.14159265358979323846

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_exp(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_tan(double x);
#endif
