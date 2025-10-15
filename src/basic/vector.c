#include <stdlib.h>
#include <math.h>
#include "../../include/basic/vector.h"

// Vec2I
int vec2I_length(Vec2I v) {
  return sqrtf(v.x * v.x + v.y * v.y);
}

Vec2I vec2I_add(Vec2I v1, Vec2I v2) {
  Vec2I result = {v1.x + v2.x, v1.y + v2.y};

  return result;
}

// Vec2F
float vec2F_length(Vec2F v) {
  return sqrtf(v.x * v.x + v.y * v.y);
}

Vec2F vec2F_add(Vec2F v1, Vec2F v2) {
  Vec2F result = {v1.x + v2.x, v1.y + v2.y};

  return result;
}

// VecNI
VecNI *vecNI_create(int n) {
  VecNI *v = malloc(sizeof(VecNI) + n * sizeof(int));

  if (!v) return NULL;

  v->n = n;

  return v;
}

int vecNI_length(VecNI *v) {
  int sum = 0;

  for (int i = 0; i < v->n; i++) {
    sum += (v->comp[i] * v->comp[i]);
  }

  return (int)sqrt(sum);
}

int vecNI_add(VecNI *v1, VecNI *v2, VecNI *v3) {
  if (v1->n != v2->n) {
    return -1;
  }

  for (int i = 0; i < v1->n; i++) {
    v3->comp[i] = v1->comp[i] + v2->comp[i];
  }

  v3->n = v1->n;

  return 0;
}

// VecNF
VecNF *vecNF_create(int n) {
  VecNF *v = malloc(sizeof(VecNF) + n * sizeof(float));

  if (!v) return NULL;

  v->n = n;

  return v;
}

float vecNF_length(VecNF *v) {
  float sum = 0;

  for (int i = 0; i < v->n; i++) {
    sum += (v->comp[i] * v->comp[i]);
  }

  return sqrtf(sum);
}

int vecNF_add(VecNF *v1, VecNF *v2, VecNF *v3) {
  if (v1->n != v2->n) {
    return -1;
  }

  for (int i = 0; i < v1->n; i++) {
    v3->comp[i] = v1->comp[i] + v2->comp[i];
  }

  v3->n = v1->n;

  return 0;
}
