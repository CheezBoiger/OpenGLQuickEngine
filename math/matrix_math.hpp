//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "common.hpp"
#include "matrix.hpp"
#include "vector.hpp"


namespace math {


// Translates the given matrix, to a new matrix value output.
// This is handy to move objects in space.
template<typename T> inline
Matrix4x4<T> Translate(const Matrix4x4<T> &original, const Vector3<T> &v);

// Rotates the given matrix using the given angle (in radians) along the given
// axis.
template<typename T> inline
Matrix4x4<T> Rotate(const Matrix4x4<T> &original, T angle, const Vector3<T> &axis);

// Scale the matrix, to provide for the zooming in of objects in space.
// This is handy with zooming and whatnot.
template<typename T> inline
Matrix4x4<T> Scale(const Matrix4x4<T> &original, const Vector3<T> &scale);

// LookAt, Persepective and Orthographic need to be implemented as well!
template<typename T> inline
Matrix4x4<T> LookAtLH(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up);

//
template<typename T> inline
Matrix4x4<T> LookAtRH(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up);

// Default call of LookAt function, which will return the Left hand side 
// or right hand side matrix depending on the rendering api.
template<typename T> inline
Matrix4x4<T> LookAt(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up);

// Perspective projection matrix.
template<typename T> inline
Matrix4x4<T> Perspective(T fov, T aspect, T zNear, T zFar);

// Orthographic projection matrix. 
template<typename T> inline
Matrix4x4<T> Orthographic(T fov, T aspect, T zNear, T zFar);
} // jkl
#include "internal/matrix_math.inl"