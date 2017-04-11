//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "common.hpp"


namespace math {


template<typename T> struct Vector3;
template<typename T> struct Vector2;


// 4-component vector type object.
// handles most of the work in terms of w compoenents or a components.
// This can be useful for colors, or matrices.
// use 3-component vectors when dealing with graphics programming!
// Do not use this vector4 object, as the w component matters!
template<typename T>
struct Vector4 {
  // Constructors.
  Vector4( 
    T x = static_cast<T>(0), 
    T y = static_cast<T>(0), 
    T z = static_cast<T>(0), 
    T w = static_cast<T>(1)
  ) : x(x), y(y), z(z), w(w) 
    { }

  Vector4(
    const Vector3<T> &v, 
    T w = static_cast<T>(1)
  ) : x(v.x), y(v.y), z(v.z), w(w)
    { }

  Vector4(
    const Vector2<T> &v, 
    T z = static_cast<T>(0), 
    T w = static_cast<T>(1)
  ) : x(v.x), y(v.y), z(z), w(w)
    { }

  // Adds this vector to v, and returns a new
  // 4 component vector.
  Vector4 operator+(const Vector4 &v) const;

  // Subtracts this vector to v, and returns a new
  // 4 component vector.
  Vector4 operator-(const Vector4 &v) const;
  
  // Multiplies this vector to v, and returns a new
  // 4 component vector.
  Vector4 operator*(const Vector4 &v) const;

  // Multiplies this vector to a scaler value, and 
  // returns a new 4 component vector.
  Vector4 operator*(const T scale) const;

  // Performs division of this vector with vector v,
  // and returns a resulting 4 component vector.
  Vector4 operator/(const Vector4 &v) const;

  // Vector division. Divides this vector by the scaler
  // value, and returns a new, fresh copy of a 4-component 
  // vector.
  Vector4 operator/(const T scaler) const;

  // Add values of v into this vector. This will not
  // create a new vector object, it will instead modify
  // this vector.
  void operator+=(const Vector4 &v);

  // Subtract values of v into this vector. This will not
  // create a new vector object, it will instead modify
  // this vector.
  void operator-=(const Vector4 &v);

  // Multiply values of v into this vector. This will not
  // create a new vector object, it will instead modify
  // this vector.
  void operator*=(const Vector4 &v);

  // Multiply a scaler value into this vector. Thise will 
  // not create a new vector object, it will instead modify
  // this vector.
  void operator*=(const T scale);

  // Divide values of v into this vector. This will not 
  // create a new vector object, it will instead modify 
  // this vector.
  void operator/=(const Vector4 &v);

  // Divides this vector's 4 components with the provided
  // scaler value. Modifies this vector object.
  void operator/=(const T scaler);

  // Take the invert of this vector, and return it as
  // a new 4 component vector.
  Vector4 operator-() const;

  Vector4 operator!() const {
    return -(*this);
  }

  // Comparison by length.
  bool operator<(const Vector4 &v) const {
    return Length() < v.Length();
  }

  bool operator>(const Vector4 &v) const {
    return Length() > v.Length();
  }

  bool operator<=(const Vector4 &v) const {
    return Length() <= v.Length();
  }

  bool operator>=(const Vector4 &v) const {
    return Length() >= v.Length();
  }

  // Comparison by actual values in the vector.
  bool operator!=(const Vector4 &v) const {
    return (x != v.x || y != v.y || z != v.z || w != v.w);  
  }

  bool operator==(const Vector4 &v) const {
    return (x == v.x && y == v.y && z == v.z && w == v.w);
  }


  // Returns the length of this vector.
  T Length() const {
    return 
      static_cast<T>(Sqrt((x * x) + (y * y) + (z * z) + (w * w))); 
  }

  union {
    struct { T x, y, z, w; };
    struct { T r, g, b, a; };
    struct { T s, t, r, q; };
  };
};


// 3-Component vector object for use in mathematics inside jackal.
// This is verty handy for rotations, scaling, translating, and whatnot.
// Most of the transformation, scaling, shearing, and rotations will be using
// this vector object.
template<typename T>
struct Vector3 {

  Vector3(
    T x = static_cast<T>(0),
    T y = static_cast<T>(0),
    T z = static_cast<T>(0)
  ) : x(x), y(y), z(z)
  { }

  // Performs perspective divide.
  Vector3(const Vector4<T> &v)
    : x(v.x / v.w), y(v.y / v.w), z(v.z / v.w)
    { }

  Vector3(
    const Vector2<T> &v, 
    T z = static_cast<T>(0)
  ) : x(v.x), y(v.y), z(z)
    { }

  Vector3(
    const Vector3 &v
  ) : x(v.x), y(v.y), z(v.z)
  { }

  // Adds this vector to v, and returns a new
  // 3 component vector.
  Vector3 operator+(const Vector3 &v) const;

  // Subtracts this vector to v, and returns a new
  // 3 component vector.
  Vector3 operator-(const Vector3 &v) const;
  
  // Multiplies this vector to v, and returns a new
  // 3 component vector.
  Vector3 operator*(const Vector3 &v) const;

  // Multiplies this vector to a scaler value, and 
  // returns a new 3 component vector.
  Vector3 operator*(const T scale) const;

  // Performs division of this vector with vector v,
  // and returns a resulting 3 component vector.
  Vector3 operator/(const Vector3 &v) const;

  // Vector division. Divides this vector by the scaler
  // value, and returns a new, fresh copy of a 3-component 
  // vector.
  Vector3 operator/(const T scaler) const;

  // Add a 3-component vector v into this vector.
  // This will not create a new vector, it will instead
  // modify this vector.
  void operator+=(const Vector3 &v);

  // Subtract a 3-component vector v into this vector.
  // This will not create new vector, it will instead
  // modify this vector.
  void operator-=(const Vector3 &v);

  // Multiply a 3-component vector v into this vector.
  // This will not create a new vector, it will instead
  // modify this vector.
  void operator*=(const Vector3 &v);

  // Multiply a scaler value into this vector.
  // This will not create a new vector, it will instead
  // modify this vector.
  void operator*=(const T scale);

  // Divide a 3-component vector v into this vector.
  // This will not create a new vector, it will instead
  // modify this vector.
  void operator/=(const Vector3 &v);

  // Divides this vector's 3 components with the provided
  // scaler value. Modifies this vector object.
  void operator/=(const T scaler);

  // Take the invert of this vector, and return it as
  // a new 3 component vector.
  Vector3 operator-() const;
  
  Vector3 operator!() {
    return -(*this);
  }

  // comparisons by length.
  bool operator<(const Vector3 &v) const {
    return Length() < v.Length();
  }

  bool operator<=(const Vector3 &v) const {
    return Length() <= v.Length();
  }

  bool operator>(const Vector3 &v) const {
    return Length() > v.Length();
  }

  bool operator>=(const Vector3 &v) const {
    return Length() >= v.Length();
  }

  // comparison by actual components.
  bool operator!=(const Vector3 &v) const {
    return (x != v.x || y != v.y || z != v.z);
  }

  bool operator==(const Vector3 &v) const {
    return (x == v.x && y == v.y && z == v.z);
  }

  T Length() const {
    return 
      static_cast<T>(Sqrt((x * x) + (y * y) + (z * z)));
  }
  union {
    struct { T x, y, z; };
    struct { T r, g, b; };
    struct { T s, t, r; };
  };
};


template<typename T>
struct Vector2 {

  Vector2(
    T x = static_cast<T>(0),
    T y = static_cast<T>(0)
  ) : x(x), y(y)
    { }

  // Adds this vector to v, and returns a new
  // 2 component vector.
  Vector2 operator+(const Vector2 &v) const;

  // Subtracts this vector to v, and returns a new
  // 2 component vector.
  Vector2 operator-(const Vector2 &v) const;

  // Multiplies this vector to v, and returns a new
  // 2 component vector.
  Vector2 operator*(const Vector2 &v) const;

  // Multiplies this vector to a scaler value, and 
  // returns a new 2 component vector.
  Vector2 operator*(const T scale) const;

  // Performs division of this vector with vector v,
  // and returns a resulting 2 component vector.
  Vector2 operator/(const Vector2 &v) const;

  // Vector division. Divides this vector by the scaler
  // value, and returns a new, fresh copy of a 2-component 
  // vector.
  Vector2 operator/(const T scaler) const;

  // Add a 2-component vector v into this vector.
  // It will not create a new vector, it will modify
  // this vector instead.
  void operator+=(const Vector2 &v);

  // Subtract a 2-component vector v into this vector.
  // It will not create a new vector, it will modify 
  // this vector instead.
  void operator-=(const Vector2 &v);

  // Multiply a 2-component vector v into this vector.
  // It will not create a new vector, it will modify
  // this vector instead.
  void operator*=(const Vector2 &v);

  // Multiply a scaler value into this vector.
  // It will not create a new vector, it will modify 
  // this vector instead.
  void operator*=(const T scale);
  
  // Divide a 2-component vector v into this vector.
  // It will not create a new vector, it will modify
  // this vector instead.
  void operator/=(const Vector2 &v);

  // Divides this vector's 2 components with the provided
  // scaler value. Modifies this vector object.
  void operator/=(const T scaler);

  // Take the invert of this vector, and return it as
  // a new 2 component vector.
  Vector2 operator-() const;

  Vector2 operator!() const {
    return -(*this);
  }

  // comparisons by length.
  bool operator<(const Vector2 &v) const {
    return Length() < v.Length();
  }

  bool operator<=(const Vector2 &v) const {
    return Length() <= v.Length();
  }

  bool operator>(const Vector2 &v) const {
    return Length() > v.Length();
  }

  bool operator>=(const Vector2 &v) const {
    return Length() >= v.Length();
  }

  // comparisons by actual component values.
  bool operator!=(const Vector2 &v) const { 
    return (x != v.x || y != v.y);
  }

  bool operator==(const Vector2 &v) const {
    return (x == v.x && y == v.y);
  }

  T Length() const {
    return 
      static_cast<T>(Sqrt((x * x) + (y * y)));
  }

  union {
    struct { T x, y; };
    struct { T r, g; };
    struct { T s, t; };
  };
};


typedef Vector3<real32> Vec3;
typedef Vector2<real32> Vec2;
typedef Vector4<real32> Vec4;
} // jkl

#include "internal/vector.inl"