#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_number = FAILURE;
  if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] == B->matrix[i][j] ||
            fabs(A->matrix[i][j] - B->matrix[i][j]) < EPS) {
          return_number = SUCCESS;
        } else
          return_number = FAILURE;
      }
    }
  }
  return return_number;
}
