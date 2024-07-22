#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_number = OK;
  if (A == NULL || B == NULL)
    return_number = INCORRECT_MATRIX;
  else if (A->columns != B->rows)
    return_number = CALCULATION_ERROR;
  else {
    return_number = mult(A, B, result);
  }
  return return_number;
}
