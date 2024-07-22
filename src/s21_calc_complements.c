#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_number = OK;
  if (A == NULL)
    return_number = INCORRECT_MATRIX;
  else if (result == NULL)
    return_number = CALCULATION_ERROR;
  else {
    if (s21_create_matrix(A->rows, A->columns, result) == OK) {
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          result->matrix[i][j] = calc_complement(A, i, j) * pow(-1, i + j);
        }
      }
    } else {
      return_number = CALCULATION_ERROR;
      s21_remove_matrix(result);
    }
  }
  return return_number;
}
