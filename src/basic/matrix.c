#include <stdlib.h>
#include <math.h>
#include "../../include/basic/matrix.h"

// Matrix2I
Matrix2I *matrix2I_create(int rows, int columns) {
  int totalData = rows * columns;

  Matrix2I *m = malloc(sizeof(Matrix2I) + totalData * sizeof(int));

  if (!m) return NULL;

  m->rows = rows;
  m->columns = columns;

  return m;
}

int matrix2I_getValue(Matrix2I *matrix, int row, int column, int *out) {
  if (row >= matrix->rows || row < 0 || column >= matrix->columns || column < 0)
    return -1;

  *out = matrix->comp[row * matrix->columns + column];

  return 0;
}

int matrix2I_setValue(Matrix2I *matrix, int row, int column, int value) {
  if (row >= matrix->rows || row < 0 || column >= matrix->columns || column < 0)
    return -1;

  matrix->comp[row * matrix->columns + column] = value;

  return 0;
}

// Matrix2F
Matrix2F *matrix2F_create(int rows, int columns) {
  int totalData = rows * columns;

  Matrix2F *m = malloc(sizeof(Matrix2F) + totalData * sizeof(float));

  if (!m) return NULL;

  m->rows = rows;
  m->columns = columns;

  return m;
}

int matrix2F_getValue(Matrix2F *matrix, int row, int column, float *out) {
  if (row >= matrix->rows || row < 0 || column >= matrix->columns || column < 0)
    return -1;

  *out = matrix->comp[row * matrix->columns + column];

  return 0;
}

int matrix2F_setValue(Matrix2F *matrix, int row, int column, float value) {
  if (row >= matrix->rows || row < 0 || column >= matrix->columns || column < 0)
    return -1;

  matrix->comp[row * matrix->columns + column] = value;

  return 0;
}
