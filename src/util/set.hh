#ifndef SET_HH
#define SET_HH

// Copyright (c) 1996-1999 The University of Cincinnati.
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

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include <set>
#include "dl_list.hh"
#include "constraint_functors.hh"

namespace savant {

   /** This class maintains a distinct set of pointers to the objects it's
     templatized on.  Functions are provided to add and reome things from
     the set, to get the number of objects in the set, and walk the members
     of the set.  NOTE: Since only pointers are kept within the set, care
     must be taken when "delete"ing members of the of set and so forth. */

   template <class type>
      /*
       * FIXME:
       * Should we inherith in a protected way?
       * std library destructors are not virtual
       * class set : protected std::set<type> {
       */
       class set : public std::set<type> {
         public:

            set( type elem );
            set();
            void insert( savant::set<type>* theSet );
            void insert( type elem );
            bool contains( type elem );
            void reduce_set( constraint_functor *functor );
            void intersect( savant::set<type> * theSet );
            template <typename new_type> savant::set<new_type> *convert_set();

            /*
             * FIXME:
             * if we want to inherit in a protected way, we need at least these methods
             * void clear() noexcept { return std::set<type>::clear(); };
             * typename std::set<type>::size_type size() const noexcept { return std::set<type>::size(); };
             * typename std::set<type>::size_type erase(const type& val) { return std::set<type>::erase(val); };
             * typename std::set<type>::iterator erase(typename std::set<type>::const_iterator val) { return std::set<type>::erase(val); };
             * typename std::set<type>::iterator begin() noexcept { return std::set<type>::begin(); };
             * typename std::set<type>::iterator end() noexcept { return std::set<type>::end(); };
             * typename std::set<type>::iterator find(const type& val) { return std::set<type>::find(val); };
             */
      };

   template <class type>
      inline 
      bool 
      set<type>::contains( type elem ){
         return std::set<type>::find(elem) != std::set<type>::end();
      }

   template <class type>
      inline 
      void 
      set<type>::reduce_set( constraint_functor *functor ){
         ASSERT( functor != NULL );
            for( typename std::set<type>::iterator it = this->begin(); it != this->end(); ){
               if( (*functor)(*it) == FALSE ){
                  it = std::set<type>::erase( it );
               } else
                  it++;
            }
      }

   template <typename type>
      inline
      void 
      savant::set<type>::intersect( savant::set<type>* theSet ) {
         ASSERT ( theSet != NULL );
         for(auto it = std::set<type>::begin(); it != std::set<type>::end(); ) {
            if(theSet->find(*it) == theSet->end()) {
               it = std::set<type>::erase( it );
            } else
               it++;
         }
      } 

   template <typename type>
      inline
      savant::set<type>::set() : std::set<type>() {} 

   template <typename type>
      inline
      savant::set<type>::set( type elem ) : std::set<type>() {
         std::set<type>::insert( elem );
      } 

   template <typename type>
      inline
      void 
      savant::set<type>::insert( type elem ) {
         std::set<type>::insert( elem );
      } 

   template <typename type>
      inline
      void 
      savant::set<type>::insert( savant::set<type>* theSet ) {
         ASSERT( theSet != NULL );
         std::set<type>::insert( theSet->begin(), theSet->end() );
      } 

   template <typename type>
      template <typename new_type> 
      inline
      savant::set<new_type> *
      savant::set<type>::convert_set() {
         savant::set<new_type>* retv = new savant::set<new_type>;

         for( auto it = std::set<type>::begin(); it != std::set<type>::end(); it++ ) {
            new_type new_val = dynamic_cast<new_type>(*it);
            retv->insert(new_val);
         }

         return retv;
      } 
}
#endif
