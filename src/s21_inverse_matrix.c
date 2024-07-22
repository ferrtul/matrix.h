#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_value = OK;
  if (A == NULL)
    return_value = INCORRECT_MATRIX;
  else if (result == NULL)
    return_value = CALCULATION_ERROR;
  else {
    return_value = inverse_matrix(A, result);
  }
  return return_value;
}
