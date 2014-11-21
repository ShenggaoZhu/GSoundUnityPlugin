/*
 * Project:     GSound
 * 
 * File:        gsound/GSoundBase.h
 * 
 * Version:     1.0.0
 * 
 * Contents:    Imports for base functionality of the GSound library.
 * 
 * License:
 * 
 *     Copyright (C) 2010-12 Carl Schissler, University of North Carolina at Chapel Hill.
 *     All rights reserved.
 *     
 *     Permission to use, copy, modify, and distribute this software and its
 *     documentation for educational, research, and non-profit purposes, without
 *     fee, and without a written agreement is hereby granted, provided that the
 *     above copyright notice, this paragraph, and the following four paragraphs
 *     appear in all copies.
 *     
 *     Permission to incorporate this software into commercial products may be
 *     obtained by contacting the University of North Carolina at Chapel Hill.
 *     
 *     This software program and documentation are copyrighted by Carl Schissler and
 *     the University of North Carolina at Chapel Hill. The software program and
 *     documentation are supplied "as is", without any accompanying services from
 *     the University of North Carolina at Chapel Hill or the authors. The University
 *     of North Carolina at Chapel Hill and the authors do not warrant that the
 *     operation of the program will be uninterrupted or error-free. The end-user
 *     understands that the program was developed for research purposes and is advised
 *     not to rely exclusively on the program for any reason.
 *     
 *     IN NO EVENT SHALL THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL OR ITS
 *     EMPLOYEES OR THE AUTHORS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
 *     SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS,
 *     ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE
 *     UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL OR THE AUTHORS HAVE BEEN ADVISED
 *     OF THE POSSIBILITY OF SUCH DAMAGE.
 *     
 *     THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND THE AUTHORS SPECIFICALLY
 *     DISCLAIM ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE AND ANY
 *     STATUTORY WARRANTY OF NON-INFRINGEMENT. THE SOFTWARE PROVIDED HEREUNDER IS
 *     ON AN "AS IS" BASIS, AND THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND
 *     THE AUTHORS HAVE NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
 *     ENHANCEMENTS, OR MODIFICATIONS.
 * 
 * 
 * Contact Information:
 *     
 *     Please send all bug reports and other contact to:
 *     Carl Schissler
 *     carl.schissler@gmail.com
 * 
 *     Updates and downloads are available at the main GSound web page:
 *     http://gamma.cs.unc.edu/GSOUND/
 * 
 */


#ifndef INCLUDE_GSOUND_BASE_H
#define INCLUDE_GSOUND_BASE_H


#include "GSoundConfig.h"


#include "GSoundMath.h"
#include "GSoundUtilities.h"


//##########################################################################################
//******************************  Start GSound Namespace  **********************************
GSOUND_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// Define the type to be used for all world-space floating-point computations.
typedef Float Real;




typedef math::AABB1D<Real> AABB1;
typedef math::AABB3D<Real> AABB3;

typedef math::Vector2D<Real> Vector2;
typedef math::Vector3D<Real> Vector3;

typedef math::Matrix3D<Real> Matrix3;

typedef math::Transformation3D<Real> Transformation3;

typedef math::Ray3D<Real> Ray3;

typedef math::Plane3D<Real> Plane3;

typedef math::SIMDScalar<Bool,4> SIMDBool;
typedef math::SIMDScalar<Int32,4> SIMDInt;
typedef math::SIMDScalar<Float32,4> SIMDFloat;
typedef math::SIMDVector3D<Float32,4> SIMDVector3;
typedef math::SIMDRay3D<Float32,4> SIMDRay3;
typedef math::SIMDAABB3D<Float32,4> SIMDAABB3;
typedef math::SIMDTriangle3D<Float32,4> SIMDTriangle3;

using util::ArrayList;
using util::StaticArrayList;
using util::HashSet;
using util::HashMap;
using util::String;

using util::StaticArray;

using util::Mutex;



//##########################################################################################
//******************************  End GSound Namespace  ************************************
GSOUND_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_GSOUND_BASE_H
