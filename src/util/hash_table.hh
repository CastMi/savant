#ifndef HASH_TABLE_HH
#define HASH_TABLE_HH

// Copyright (c) 1993-1999 The University of Cincinnati.
// All rights reserved. 

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
// DERIVATIVES.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
// DERIVATIVES.

// Authors: Philip A. Wilsey    phil.wilsey@uc.edu
//          Dale E. Martin      dmartin@cliftonlabs.com
//          Timothy J. McBrayer tmcbraye@ece.uc.edu
//          Michele Castellana blacklion727@gmail.com

//---------------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <map>
#include "savant.hh"
#include "dl_list.hh"
#include "savant.hh"

/** Template based bucket hashing class.  Hashes on input string.
    The template Type defines the type of the constructed bucket for
    each entry.

    Requirements on Type:
    void set_key(char *key): initializes text key in Type
    internal pointer to text string
    Type constructor assumed to require no arguments
*/

template <class Type>
class hash_table {
    
public:
  /**
    Look up "text" in the hash table.
  */
  Type *hash_look( const char * const text ){
    return hash_look( text, strlen(text) );
  }

  /**
     Look up the NULL terminated "text" in the hash table, using
     "length" as the length of the key.
  */
  Type *hash_look( const char *const text, const int length ) {
    assert( strlen(text) == length );
    return hash_look(std::string(text));
  }

  /**
     Look up the NULL terminated "text" in the hash table, using
     "length" as the length of the key.
  */
  Type *hash_look( const std::string text ) {
    if ( ht.find(text) != ht.end() ) {
       return ht.find(text)->second;
    }

    Type *wk = new Type();
    wk->set_key( text.c_str(), text.size() );
    ht.insert( std::pair<std::string, Type*>(text, wk) );
    assert( ht.find(text) != ht.end() );
    return wk;
  }

  /**
     Constructor

     @param table_size The initial table size of this hash table.
     Currently it's the final size as well as the table won't grow.
  */
  hash_table() : ht() {}
  ~hash_table() {};

  /**
     Clear the hash table.
  */
  void reset(){
    for(unsigned i = 0 ; i < ht.size(); ++i) {
      //ht[i].destroy_containers();
    }
  }


  /**
     This method returns the whole table as a list.  The list needs to be
     deleted when finished.  This can be an expensive operation.  If the
     hash table is empty, an empty list will be returned.
  */
  dl_list<Type> *convert_to_list() const {
    dl_list<Type> *retval = new dl_list<Type>;
    for( auto it = ht.begin(); it != ht.end(); ++it ) {
      Type *current = it->second;
      retval->append( current );
    }
    return retval;
  }

private:
  std::map<std::string, Type*> ht;
};

#endif // HASH_TABLE_HH
