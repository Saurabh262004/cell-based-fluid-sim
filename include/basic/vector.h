#ifndef VECTOR_H
#define VECTOR_H

// Vec2I
typedef struct {
  int x;
  int y;
} Vec2I;

int vec2I_length(Vec2I v);

Vec2I vec2I_add(Vec2I v1, Vec2I v2);

// Vec2F
typedef struct {
  float x;
  float y;
} Vec2F;

float vec2F_length(Vec2F v);

Vec2F vec2F_add(Vec2F v1, Vec2F v2);

// VecNI
typedef struct {
  int n;
  int comp[];
} VecNI;

VecNI *vecNI_create(int n);

int vecNI_length(VecNI *v);

int vecNI_add(VecNI *v1, VecNI *v2, VecNI *v3);

// VecNF
typedef struct {
  int n;
  float comp[];
} VecNF;

VecNF *vecNF_create(int n);

float vecNF_length(VecNF *v);

int vecNF_add(VecNF *v1, VecNF *v2, VecNF *v3);

#endif
