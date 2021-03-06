/*
 * Project:     GSound
 * 
 * File:        gsound/SoundScene.cpp
 * 
 * Version:     1.0.0
 * 
 * Contents:    gsound::SoundScene class implementation
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


#include "SoundScene.h"


//##########################################################################################
//******************************  Start GSound Namespace  **********************************
GSOUND_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//##########################################################################################
//############		
//############		Constructor
//############		
//##########################################################################################
//##########################################################################################




SoundScene:: SoundScene()
	:	objectBVH( NULL ),
		speedOfSound( 343 ),
		userData( NULL )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sound Source Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




void SoundScene:: addSource( SoundSource* newSource )
{
	if ( newSource == NULL )
		return;
	
	sources.add( newSource );
}




Bool SoundScene:: removeSource( SoundSource* source )
{
	if ( source == NULL )
		return false;
	
	return sources.remove( source );
}




void SoundScene:: removeAllSources()
{
	sources.clear();
}




//##########################################################################################
//##########################################################################################
//############		
//############		Sound Object Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




void SoundScene:: addObject( SoundObject* newObject )
{
	if ( newObject == NULL )
		return;
	
	objects.add( newObject );
	rebuildObjectBVH();
}




Bool SoundScene:: removeObject( SoundObject* object )
{
	if ( object == NULL )
		return false;
	
	Bool result = objects.remove( object );
	
	if ( result )
		rebuildObjectBVH();
	
	return result;
}




void SoundScene:: removeAllObjects()
{
	objects.clear();
	
	rebuildObjectBVH();
}




//##########################################################################################
//##########################################################################################
//############		
//############		BVH Rebuilding Method
//############		
//##########################################################################################
//##########################################################################################




void SoundScene:: rebuildObjectBVH() const
{
	if ( objectBVH != NULL )
		util::destruct(objectBVH);
	
	if ( objects.getSize() == 0 )
		objectBVH = NULL;
	else
	{
		objectBVH = util::allocate<ObjectBVHType>();
		new (objectBVH) ObjectBVHType( const_cast<SoundScene*>(this)->objects );
	}
}




//##########################################################################################
//******************************  End GSound Namespace  ************************************
GSOUND_NAMESPACE_END
//******************************************************************************************
//##########################################################################################
