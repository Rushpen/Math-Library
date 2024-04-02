#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

#define D 1e-07

START_TEST(s21_abs_test) {
  ck_assert_int_eq(s21_abs(-10), abs(-10));
  ck_assert_int_eq(s21_abs(10), abs(10));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
}
END_TEST

START_TEST(s21_acos_test) {
  ck_assert_ldouble_eq_tol(s21_acos(0.9), acos(0.9), D);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), D);
  ck_assert_ldouble_eq_tol(s21_acos(0.), acos(0.), D);
  ck_assert_ldouble_nan(s21_acos(1.1));
  ck_assert_ldouble_eq_tol(s21_acos(-1.), acos(-1.), D);
}
END_TEST

START_TEST(s21_asin_test) {
  ck_assert_ldouble_eq_tol(s21_asin(0.9), asin(0.9), D);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), D);
  ck_assert_ldouble_eq_tol(s21_asin(0.), asin(0.), D);
  ck_assert_ldouble_nan(s21_asin(1.1));
  ck_assert_ldouble_eq_tol(s21_asin(-1.), asin(-1.), D);
}
END_TEST

START_TEST(s21_atan_test) {
  double t = -0.9;
  double x = 0.5;
  ck_assert_ldouble_eq_tol(s21_atan(t), atan(t), D);
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), D);
  ck_assert_ldouble_eq_tol(s21_atan(0.), atan(0.), D);
  ck_assert_ldouble_eq_tol(s21_atan(PI / 4), atan(PI / 4), D);
  ck_assert_ldouble_eq_tol(s21_atan(PI / 2), atan(PI / 2), D);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), D);
  ck_assert_ldouble_eq_tol(s21_atan(999), atan(999), D);
}
END_TEST

START_TEST(s21_ceil_test) {
  double t = -0.9;
  double x = -1;

  ck_assert_double_eq(s21_ceil(t), ceil(t));
  ck_assert_double_eq(s21_ceil(x), ceil(x));
  ck_assert_double_eq(s21_ceil(1.), ceil(1.));
  ck_assert_double_eq(s21_ceil(0.1), ceil(0.1));
  ck_assert_double_eq(s21_ceil(0.), ceil(0.));
}
END_TEST

START_TEST(s21_cos_test) {
  double t = -0.9;
  double x = 0.5;

  ck_assert_ldouble_eq_tol(s21_cos(t), cos(t), D);
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), D);
  ck_assert_ldouble_eq_tol(s21_cos(0.), cos(0.), D);
  ck_assert_ldouble_eq_tol(s21_cos(10.), cos(10.), D);
  ck_assert_ldouble_eq_tol(s21_cos(-10.), cos(-10.), D);
  ck_assert_ldouble_eq_tol(s21_cos(10000.), cos(10000.), D);
  ck_assert_ldouble_eq_tol(s21_cos(-10000.), cos(-10000.), D);
}
END_TEST

START_TEST(s21_exp_test) {
  double t = -0.9;
  double x = 710;

  ck_assert_ldouble_eq_tol(s21_exp(t), exp(t), D);
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_eq_tol(s21_exp(0.), exp(0.), D);
  ck_assert_ldouble_infinite(s21_exp(10000000000));
  ck_assert_ldouble_eq_tol(s21_exp(-90), exp(-90), D);
}
END_TEST

START_TEST(s21_fabs_test) {
  double t = -0.9;
  double x = 0.5;

  ck_assert_ldouble_eq_tol(s21_fabs(t), fabs(t), D);
  ck_assert_ldouble_eq_tol(s21_fabs(x), fabs(x), D);
  ck_assert_ldouble_eq_tol(s21_fabs(0.), fabs(0.), D);
}
END_TEST

START_TEST(s21_floor_test) {
  double t = -0.9;
  double x = -10;

  ck_assert_double_eq(s21_floor(t), floor(t));
  ck_assert_double_eq(s21_floor(x), floor(x));
  ck_assert_double_eq(s21_floor(1.), floor(1.));
  ck_assert_double_eq(s21_floor(0.1), floor(0.1));
  ck_assert_double_eq(s21_floor(0.), floor(0.));
}
END_TEST

START_TEST(s21_fmod_test) {
  double t = -0.9;
  double x = 1000;

  double p = 4;

  ck_assert_ldouble_eq_tol(s21_fmod(t, p), fmod(t, p), D);
  ck_assert_ldouble_eq_tol(s21_fmod(x, p), fmod(x, p), D);
  ck_assert_ldouble_eq_tol(s21_fmod(100000000., 1000000.),
                           fmod(100000000., 1000000.), D);
  ck_assert_ldouble_eq_tol(s21_fmod(-100000000., 1000000.),
                           fmod(-100000000., 1000000.), D);
  ck_assert_ldouble_eq_tol(s21_fmod(-100000000., 9999999.),
                           fmod(-100000000., 9999999.), D);
  ck_assert_ldouble_eq_tol(s21_fmod(-100000000., -1000000.),
                           fmod(-100000000., -1000000.), D);
}
END_TEST

START_TEST(s21_log_test) {
  double t = -0.9;
  double x = 5;

  ck_assert_double_nan(s21_log(t));
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), D);
  ck_assert_ldouble_infinite(s21_log(0));
}
END_TEST

START_TEST(s21_pow_test) {
  double t = 0;
  double p = 0;
  ck_assert_double_nan(s21_pow(-1, 0.33));
  ck_assert_ldouble_eq_tol(s21_pow(t, p), pow(t, p), D);
  ck_assert_ldouble_infinite(s21_pow(t, -5));
  ck_assert_ldouble_eq_tol(s21_pow(t, 0.5), pow(t, 0.5), D);
  ck_assert_ldouble_eq_tol(s21_pow(-50, 0), pow(t, 0), D);
  ck_assert_ldouble_eq_tol(s21_pow(-5000, -5000), pow(-5000, -5000), D);
  ck_assert_ldouble_infinite(s21_pow(500, 500));
}
END_TEST

START_TEST(s21_sin_test) {
  double t = -0.9;
  double x = 0.5;
  ck_assert_double_eq_tol(s21_sin(t), sin(t), D);
  ck_assert_double_eq_tol(s21_sin(x), sin(x), D);
  ck_assert_ldouble_eq_tol(s21_sin(0.), sin(0.), D);
  ck_assert_ldouble_eq_tol(s21_sin(10.), sin(10.), D);
  ck_assert_ldouble_eq_tol(s21_sin(-10.), sin(-10.), D);
  ck_assert_ldouble_eq_tol(s21_sin(10000.), sin(10000.), D);
  ck_assert_ldouble_eq_tol(s21_sin(-10000.), sin(-10000.), D);
}
END_TEST

START_TEST(s21_sqrt_test) {
  double t = -0.9;
  double x = 0.5;

  ck_assert_double_nan(s21_sqrt(t));
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), D);
  ck_assert_double_eq_tol(s21_sqrt(0.), sqrt(0.), D);
  ck_assert_double_eq_tol(s21_sqrt(4.), sqrt(4.), D);
}
END_TEST

START_TEST(s21_tan_test) {
  double t = -0.9;
  double x = 0.5;

  ck_assert_double_eq_tol(s21_tan(t), tan(t), D);
  ck_assert_double_eq_tol(s21_tan(x), tan(x), D);
  ck_assert_double_infinite(s21_tan(PI / 2));
  ck_assert_double_eq_tol(s21_tan(PI / 4), tan(PI / 4), D);
  ck_assert_double_eq_tol(s21_tan(-PI / 4), tan(-PI / 4), D);
  ck_assert_double_eq_tol(s21_tan(PI), tan(PI), D);
}
END_TEST

Suite *s21_math_suite_create(void) {
  Suite *suite = suite_create("s21_math_suite");
  TCase *tcase_core = tcase_create("s21_math_tcase");

  tcase_add_test(tcase_core, s21_abs_test);
  tcase_add_test(tcase_core, s21_acos_test);
  tcase_add_test(tcase_core, s21_asin_test);
  tcase_add_test(tcase_core, s21_atan_test);
  tcase_add_test(tcase_core, s21_ceil_test);
  tcase_add_test(tcase_core, s21_cos_test);
  tcase_add_test(tcase_core, s21_exp_test);
  tcase_add_test(tcase_core, s21_fabs_test);
  tcase_add_test(tcase_core, s21_floor_test);
  tcase_add_test(tcase_core, s21_fmod_test);
  tcase_add_test(tcase_core, s21_log_test);
  tcase_add_test(tcase_core, s21_pow_test);
  tcase_add_test(tcase_core, s21_sin_test);
  tcase_add_test(tcase_core, s21_sqrt_test);
  tcase_add_test(tcase_core, s21_tan_test);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main() {
  int failed_count = 0;
  Suite *suite = s21_math_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  printf("%d\n", failed_count);

  return 0;
}
