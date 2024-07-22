#include "s21_matrix.h"

void rewrite_matrix(matrix_t *A, matrix_t RES_A) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; j++) {
      RES_A.matrix[i][j] = A->matrix[i][j];
    }
  }
}

double calc_determinant(matrix_t CHANGE_MATRIX, int swap_value) {
  double determinant_value = 1;
  for (int i = 0, j = 0; i < CHANGE_MATRIX.rows && j < CHANGE_MATRIX.columns;
       i++, j++) {
    determinant_value *= CHANGE_MATRIX.matrix[i][j];
  }
  determinant_value = pow(-1, swap_value) * determinant_value;
  if (determinant_value == -0) determinant_value = 0;
  return determinant_value;
}

void swap_rows(matrix_t *ORIGINAL_MATRIX, int row_num, int *swap_value) {
  double temp_value = 0;
  int in_swap_row_num = 0, stop = 0;

  for (int i = row_num; i < ORIGINAL_MATRIX->rows || stop == 0; i++) {
    if (stop != 1 && ORIGINAL_MATRIX->matrix[i][row_num] != 0) {
      in_swap_row_num = i;
      stop = 1;
    }
  }
  for (int i = 0; i < ORIGINAL_MATRIX->columns; i++) {
    temp_value = ORIGINAL_MATRIX->matrix[row_num][i];
    ORIGINAL_MATRIX->matrix[row_num][i] =
        ORIGINAL_MATRIX->matrix[in_swap_row_num][i];
    ORIGINAL_MATRIX->matrix[in_swap_row_num][i] = temp_value;
  }
  (*swap_value)++;
}

void redact_matrix(matrix_t *ORIGINAL_MATRIX, int *swap_value) {
  for (int k = 0, n = 0;
       k < ORIGINAL_MATRIX->rows - 1 && n < ORIGINAL_MATRIX->columns;
       k++, n++) {
    if (ORIGINAL_MATRIX->matrix[k][n] == 0) {
      swap_rows(ORIGINAL_MATRIX, k, swap_value);
    }

    for (int i = k + 1; i < ORIGINAL_MATRIX->rows; i++) {
      double koeff =
          ORIGINAL_MATRIX->matrix[i][k] / ORIGINAL_MATRIX->matrix[k][k];
      for (int j = k; j < ORIGINAL_MATRIX->columns; j++) {
        ORIGINAL_MATRIX->matrix[i][j] -= koeff * ORIGINAL_MATRIX->matrix[k][j];
      }
    }
  }
}

double calc_complement(matrix_t *ORIGINAL_MATRIX, int row, int column) {
  int minor_row = 0, minor_column = 0;
  double complement = 0;
  matrix_t MINOR = {0};
  if (s21_create_matrix(ORIGINAL_MATRIX->rows - 1, ORIGINAL_MATRIX->columns - 1,
                        &MINOR) == OK) {
    for (int i = 0; i < ORIGINAL_MATRIX->rows; ++i) {
      for (int j = 0; j < ORIGINAL_MATRIX->columns; ++j) {
        if (i != row && j != column) {
          MINOR.matrix[minor_row][minor_column] = ORIGINAL_MATRIX->matrix[i][j];
          minor_column++;
          if (minor_column == MINOR.columns) {
            minor_column = 0;
            minor_row++;
          }
        }
      }
    }
    s21_determinant(&MINOR, &complement);
    s21_remove_matrix(&MINOR);

  } else
    s21_remove_matrix(&MINOR);

  return complement;
}

void s21_print_matrix(matrix_t *A) {
  for (int i = 0; i < A->columns; ++i) {
    for (int j = 0; j < A->rows; ++j) {
      printf("%lf ", A->matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("________________\n");
}

int inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_value = 0;
  double determinant_value = 0;
  matrix_t COMPLEMENTS_MATRIX = {0}, TRANSPOSE_MATRIX = {0};
  if (s21_calc_complements(A, &COMPLEMENTS_MATRIX) == OK) {
    if (s21_transpose(&COMPLEMENTS_MATRIX, &TRANSPOSE_MATRIX) == OK) {
      if (s21_determinant(A, &determinant_value) == OK) {
        if (s21_mult_number(&TRANSPOSE_MATRIX, 1 / determinant_value, result) !=
            OK) {
          return_value = CALCULATION_ERROR;
          s21_remove_matrix(result);
        }
      } else
        return_value = CALCULATION_ERROR;
    } else
      return_value = CALCULATION_ERROR;
  } else
    return_value = CALCULATION_ERROR;

  s21_remove_matrix(&COMPLEMENTS_MATRIX);
  s21_remove_matrix(&TRANSPOSE_MATRIX);
  return return_value;
}

int mult(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_number = OK;
  if (s21_create_matrix(A->rows, B->columns, result) == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  } else {
    return_number = CALCULATION_ERROR;
    s21_remove_matrix(result);
  }

  return return_number;
}