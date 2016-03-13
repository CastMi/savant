#ifndef GENERIC_PARSER_HH
#define GENERIC_PARSER_HH

class IIR_LibraryDeclaration;
class plugin_class_factory;
class symbol_table;

class generic_parser {
public:
  /** This method returns the IIR_LibraryDeclaration that was used for this
      execution of the parser for the VHDL library "work". */
  virtual IIR_LibraryDeclaration *get_work_library() const { ASSERT(false); };
  
  virtual plugin_class_factory* get_class_factory() const { ASSERT(false); };

  virtual generic_parser* convert_node(plugin_class_factory *) { ASSERT(false); };

  /** Return the symbol_table associated with this parser. */
  virtual symbol_table* get_symbol_table() const { ASSERT(false); } ;

};

#endif //GENERIC_PARSER_HH
