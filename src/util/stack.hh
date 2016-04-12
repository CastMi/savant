#ifndef STACK_HH
#define STACK_HH

/**
  * Copyright (C) 2016 Michele Castellana <blacklion727@gmail.com>
  *
  * This source code is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This source code is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this code.  If not, see <http://www.gnu.org/licenses/>.
  **/

#include <stack>
#include <type_traits>
#include "savant.hh"

namespace savant {

template <class element>
class stack {
   static_assert( std::is_pointer<element>::value, "This stack class must be used with a pointer. Use the std::stack instead." );
public:
  inline stack() {}
  inline ~stack() {}

  inline element pop();
  inline void push( element );

  inline element get_top_of_stack(){
     if ( realstack.empty() )
        return nullptr;
     return realstack.top();
  };

  inline element top(){
     if ( realstack.empty() )
        return nullptr;
     return realstack.top();
  };
private:
  std::stack<element> realstack;
  
};

template < class element >
element stack<element>::pop() {
  if ( realstack.empty() )
    return nullptr;
  else {
    element tmp = realstack.top();
    realstack.pop();
    return tmp;
  }
}

template < class element >
void stack<element>::push(element new_element) {
   ASSERT( new_element );
   realstack.push(new_element);
}

}
#endif
