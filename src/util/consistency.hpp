#ifndef CONSISTENCY_HPP
#define CONSISTENCY_HPP

#include <vector>
#include <cstddef>

class IIR;

class consistency {
public:
  /** Singleton. */
  static consistency* instance();
  ~consistency();
  
  void add_missing( IIR* );
  std::vector<IIR*>& get_missing();
  size_t size() const;
  

private:
  /** This is private - It is a singleton.  */
  consistency();

  // items with at least one missing element
  std::vector<IIR*> missing;
    
};

#endif
