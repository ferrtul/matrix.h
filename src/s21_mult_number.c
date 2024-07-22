#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_number = OK;
  if (A == NULL)
    return_number = INCORRECT_MATRIX;
  else if (isnan(number) || isinf(number))
    return_number = CALCULATION_ERROR;
  else {
    if (s21_create_matrix(A->rows, A->columns, result) == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = number * A->matrix[i][j];
        }
      }
    } else {
      return_number = CALCULATION_ERROR;
      s21_remove_matrix(result);
    }
  }
  return return_number;
}