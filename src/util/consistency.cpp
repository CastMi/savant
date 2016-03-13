#include "consistency.hpp"
#include "savant.hh"
#include <cassert>

consistency*
consistency::instance() {
   static consistency* singleton = new consistency();
   return singleton;
}

consistency::consistency() {
   // do something
}

consistency::~consistency(){
   // do something
   ASSERT(missing.size() == 0);
}

std::vector<IIR*>&
consistency::get_missing(){
   return missing;
}

size_t
consistency::size() const {
   return missing.size();
}

void
consistency::add_missing( IIR* item ) {
   return missing.push_back(item);
}
