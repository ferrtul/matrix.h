//
// Created by Josie Sunflower on 1/11/24.
//

#ifndef MATRIX_S21_MATRIX_H
#define MATRIX_S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// возвращаемые значения
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

// возвращаемые значения для сравнения
#define SUCCESS 1
#define FAILURE 0

// точность
#define EPS 1e-07

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int colomns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// additional_funktions
void s21_print_matrix(matrix_t *A);
void rewrite_matrix(matrix_t *A, matrix_t RES_A);
double calc_determinant(matrix_t CHANGE_MATRIX, int swap_value);
void swap_rows(matrix_t *ORIGINAL_MATRIX, int row_num, int *swap_value);
void redact_matrix(matrix_t *ORIGINAL_MATRIX, int *swap_value);
void calc_minor(matrix_t *ORIGINAL_MATRIX, matrix_t *MINOR, int row,
                int column);
double calc_complement(matrix_t *ORIGINAL_MATRIX, int row, int column);
int inverse_matrix(matrix_t *A, matrix_t *result);
int mult(matrix_t *A, matrix_t *B, matrix_t *result);

#endif  // MATRIX_S21_MATRIX_H
