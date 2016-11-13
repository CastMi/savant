/*
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "generic_visitor.hh"
#include "IIR.hh"
#include "IIR_Statement.hh"
#include <iostream>
#include <typeinfo>

bool
generic_visitor::visit( IIR * el ) {
  switch( el->get_kind() ) {
     default:
        std::cerr << typeid(*this).name() << " does not support the visit of the type: "
           << el->get_kind_text();
        return true;
  }
}

bool
generic_visitor::visit( IIR_Statement * el ) {
  switch( el->get_kind() ) {
     default:
        std::cerr << typeid(*this).name() << ": does not support the visit of the type: "
           << el->get_kind_text();
        return true;
  }
}
