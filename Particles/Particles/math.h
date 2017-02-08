#pragma once
#include <random>
#include <cmath>

inline float rand01() { return (float)rand() / RAND_MAX; }

inline float lerp(float s, float e, float t) { return s*(1 - t) + e*t; }

#define DEG2RAD 0.0174533


struct vec2 { float x, y; };

inline vec2 operator+(const vec2 &A, const vec2 &B)
	{	return vec2{ A.x + B.x, A.y + B.y };}

inline vec2 operator*(const vec2 &A, float b)
	{	return vec2{ A.x*b, A.y*b };}

inline vec2 operator*(const vec2 &A, const vec2 &B)
	{	return vec2{ A.x*B.x, A.y*B.y };}
