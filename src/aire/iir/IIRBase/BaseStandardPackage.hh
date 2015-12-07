#ifndef BASE_STANDARD_PACKAGE_HH
#define BASE_STANDARD_PACKAGE_HH

#include "StandardPackage.hh"
#include "IIRBase_PackageDeclaration.hh"

class BaseStandardPackage : public virtual StandardPackage,
			    public virtual IIRBase_PackageDeclaration {
public:
  IIRRef convert_tree(plugin_class_factoryRef factory);

protected:
  BaseStandardPackage(){}
  virtual ~BaseStandardPackage(){}
};

typedef refcount<BaseStandardPackage> BaseStandardPackageRef;

#endif
