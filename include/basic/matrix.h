#ifndef MATRIX_H
#define MATRIX_H

// Matrix2I
typedef struct {
  int rows;
  int columns;
  int comp[];
} Matrix2I;

Matrix2I *matrix2I_create(int rows, int columns);

int matrix2I_getValue(Matrix2I *matrix, int row, int column, int *out);

int matrix2I_setValue(Matrix2I *matrix, int row, int column, int value);

// Matrix2F
typedef struct {
  int rows;
  int columns;
  float comp[];
} Matrix2F;

Matrix2F *matrix2F_create(int rows, int columns);

int matrix2F_getValue(Matrix2F *matrix, int row, int column, float *out);

int matrix2F_setValue(Matrix2F *matrix, int row, int column, float value);

#endif
