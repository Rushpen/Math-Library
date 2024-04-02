#include "s21_math.h"

int s21_abs(int x) { return x < 0 ? -x : x; }

long double s21_fabs(double x) { return x < 0 ? -x : x; }

long double s21_fmod(double x, double y) {
  return x - y * ((long long)(x / y));
}

long double s21_ceil(double x) {
  long double res;
  long double remainder = s21_fmod(x, 1.0);
  if (x >= 0 && remainder)
    res = x - remainder + 1;
  else
    res = x - remainder;
  return res;
}

long double s21_floor(double x) {
  long double res;
  long double remainder = s21_fmod(x, 1.0);
  if (x < 0 && remainder)
    res = x - remainder - 1;
  else
    res = x - remainder;
  return res;
}

long double s21_exp(double x) {
  long double eps = 1e-20;
  long double s = 1;
  long double p = 1;
  long double prevTerm = 0;
  int i = 1;
  int negativeX = 0;
  if (x < 0) {
    negativeX = 1;
    x = -x;
  }
  do {
    prevTerm = s;
    p *= x / i;
    s += p;
    i++;
    if (s >= DBL_MAX) {
      s = __builtin_inff();
      break;
    }
  } while (s21_fabs(s - prevTerm) >= eps);
  if (negativeX) {
    if (s == __builtin_inff()) {
      s = 0;
    } else {
      s = 1. / s;
    }
  }
  return s;
}

long double s21_sin(double x) {
  x = s21_fmod(x, 2 * PI);
  long double eps = 1e-16;
  long double s = x;
  long double p = x;
  long double prevTerm = 0;
  int i = 3;
  int sign = 1;
  if (s21_fmod(x, PI) == 0) {
    s = 0;
  } else {
    do {
      prevTerm = s;
      sign *= -1;
      p *= x * x / (i * (i - 1));
      s += sign * p;
      i += 2;
    } while (s21_fabs(s - prevTerm) >= eps);
  }
  return s;
}

long double s21_cos(double x) {
  x = s21_fmod(x, 2 * PI);
  long double eps = 1e-16;
  long double s = 1;
  long double p = 1;
  long double prevTerm = 0;
  int i = 2;
  int sign = 1;
  if (s21_fmod(x, PI / 2) == 0 && s21_fmod(x, PI) != 0) {
    s = 0;
  } else {
    do {
      prevTerm = s;
      sign *= -1;
      p *= x * x / (i * (i - 1));
      s += sign * p;
      i += 2;
    } while (s21_fabs(s - prevTerm) >= eps);
  }
  return s;
}

long double s21_asin(double x) {
  long double res = x;

  if (s21_fabs(x) < 1) {
    long double eps = 1e-16;
    long double numerator = x;
    long double denominator = 1;
    long double prevTerm = 0;
    for (int i = 2; s21_fabs(res - prevTerm) >= eps; i += 2) {
      prevTerm = res;
      numerator *= x * x;
      denominator *= i;
      res += numerator / (denominator * (i + 1));
      numerator *= i + 1;
    }

  } else {
    if (x == -1) {
      res = -PI / 2;
    } else if (x == 1) {
      res = PI / 2;
    } else {
      res = __builtin_nanf("0x7fc00000");
    }
  }
  return res;
}

long double s21_acos(double x) {
  long double res;
  if (s21_fabs(x) <= 1) {
    res = PI / 2 - s21_asin(x);
  } else {
    res = __builtin_nanf("0x7fc00000");
  }
  return res;
}

long double s21_atan(double x) {
  long double result = 0;
  if (x == __builtin_inff() || x == -__builtin_inff()) {
    result = x < 0 ? -PI / 2 : PI / 2;
  } else if (x <= 1. && x >= -1.) {
    for (long double i = 0.0; i < 500; i += 1.0) {
      result += ((s21_pow(-1, i)) * (s21_pow(x, 2 * i + 1))) / (2 * i + 1);
    }
  } else {
    for (long double i = 0.0; i < 500; i += 1.0) {
      result += ((s21_pow(-1, i)) * (s21_pow(x, -2 * i - 1))) / (2 * i + 1);
    }
    result = PI * s21_sqrt(x * x) / (2 * x) - result;
  }
  return result;
}

long double s21_log(double x) {
  long double result = 0.0;
  if (x < 0) {
    result = __builtin_nanf("0x7fc00000");
  } else if (x == 0) {
    result = -__builtin_inff();
  } else {
    long double eps = 1e-16;
    long double prevTerm = 0;
    long double term = ((long double)x - 1.0L) / ((long double)x + 1.0L);
    long double numerator = term;
    long double denominator = 1.0;

    do {
      prevTerm = result;
      result += numerator / denominator;
      numerator *= term * term;
      denominator += 2.0;

    } while (s21_fabs(result - prevTerm) >= eps);

    result *= 2.0;
  }

  return result;
}

long double s21_pow(double base, double exp) {
  int sign = 1;
  long double result = 0;
  if (base == 1) {
    result = 1;
  }
  if (base == 0 && exp == 0) {
    result = 1;
  }
  if ((base < 0) && exp == s21_floor(exp)) {
    sign = ((long long)s21_fabs(exp)) % 2 == 1 ? -1 : 1;
    base = s21_fabs(base);
  }
  if (result == 0) {
    result = sign * s21_exp(s21_log(base) * exp);
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = 0.0;
  if (x != 0) result = s21_exp(s21_log(x) * 0.5);
  return result;
}

long double s21_tan(double x) {
  long double sin = s21_sin(x);
  long double cos = s21_cos(x);
  long double res;
  res = sin / cos;
  return res;
}
