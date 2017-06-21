﻿//-------------------------------------------------------------------------------------------------
// File : r3d_shape.h
// Desc : Shapes.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <r3d_math.h>

///////////////////////////////////////////////////////////////////////////////////////////////////
// Sphere sturcture
///////////////////////////////////////////////////////////////////////////////////////////////////
struct Sphere
{
    double          radius;     //!< 半径です.
    Vector3         pos;        //!< 位置座標です.
    Vector3         color;      //!< 色です.

    Sphere
    (
        double          r,
        const Vector3&  p,
        const Vector3&  c
    )
    : radius    (r)
    , pos       (p)
    , color     (c)
    { /* DO_NOTHING*/ }

    inline double intersect(const Ray& ray) const
    {
        auto p = pos - ray.pos;
        auto b = dot(p, ray.dir);
        auto det = b * b - dot(p, p) + radius * radius;
        if (det >= 0.0)
        {
            auto sqrt_det = sqrt(det);
            auto t1 = b - sqrt_det;
            auto t2 = b + sqrt_det;
            if (t1 > D_HIT_MIN)
            { return t1; }
            else if (t2 > D_HIT_MIN)
            { return t2; }
        }
 
        return D_HIT_MAX;
    }
};