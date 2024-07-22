#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_number = OK;
  if (A == NULL)
    return_number = INCORRECT_MATRIX;
  else {
    if (s21_create_matrix(A->columns, A->rows, result) == OK) {
      for (int i = 0; i < A->columns; ++i) {
        for (int j = 0; j < A->rows; ++j) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    } else {
      return_number = CALCULATION_ERROR;
      s21_remove_matrix(result);
    }
  }
  return return_number;
}