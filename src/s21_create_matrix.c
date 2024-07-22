#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_values = OK;
  if (rows <= 0 || columns <= 0)
    return_values = INCORRECT_MATRIX;
  else {
    result->rows = rows, result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      return_values = INCORRECT_MATRIX;
      free(result->matrix);
    } else if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          return_values = INCORRECT_MATRIX;
          free(result->matrix[i]);
        }
      }
    }
  }
  return return_values;
}