#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int return_num = OK, swap_value = 0;
  matrix_t REWRITE_A = {0};
  if (A == NULL)
    return_num = INCORRECT_MATRIX;
  else {
    if (s21_create_matrix(A->rows, A->columns, &REWRITE_A) == OK) {
      rewrite_matrix(A, REWRITE_A);
      redact_matrix(&REWRITE_A, &swap_value);
      (*result) = calc_determinant(REWRITE_A, swap_value);
    } else {
      return_num = CALCULATION_ERROR;
      s21_remove_matrix(&REWRITE_A);
    }
    s21_remove_matrix(&REWRITE_A);
  }

  return return_num;
}
