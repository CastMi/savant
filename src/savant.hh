#ifndef SAVANT_HH
#define SAVANT_HH

// Copyright (c) 1995-2001 The University of Cincinnati.
// All rights reserved. 

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2,
// June 1991. A copy of this license agreement can be found in the file
// "LGPL", distributed with this archive.

// Author: Dale E. Martin          dmartin@cliftonlabs.com
//         Magnus Danielson        cfmd@swipnet.se

//---------------------------------------------------------------------------

#include "savant_config.hh"

#ifndef NULL
#define NULL 0
#endif

extern bool parse_error;
extern bool gen_cc_ref;

#include <cstdio>
#include <cstdlib>

/*
 * Asserts
 */
#include <cassert>
// #define ASSERT(x) assert( x || parse_error == true )
#define ASSERT(x) assert( x )

/*
 * Smart pointers
 */
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/make_shared.hpp>
#define refcount std::shared_ptr
#define Wrefcount boost::weak_ptr
#define my_dynamic_pointer_cast std::dynamic_pointer_cast
#define my_make_shared boost::make_shared

/*
 * Macro used to forward declare a Refcount type
 */
#define REF_FORWARD_DECL(obj) class obj; typedef refcount<obj> obj##Ref
#define CONSTREF_FORWARD_DECL(obj) class obj; typedef refcount<const obj> obj##ConstRef

#endif
