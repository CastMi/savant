#ifndef CONSISTENCY_HPP
#define CONSISTENCY_HPP

#include <vector>
#include <cstddef>

class IIR_Statement;

class consistency {
public:
  /** Singleton. */
  static consistency* instance();
  ~consistency();
  
  void add_missing( IIR_Statement* );
  std::vector<IIR_Statement*>& get_missing();
  size_t size() const;
  

private:
  /** This is private - It is a singleton.  */
  consistency();

  // items with at least one missing element
  std::vector<IIR_Statement*> missing;
    
};

#endif
