#ifndef _auxVariablePredatorModel_H_
#define _auxVariablePredatorModel_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXVARIABLEPREDATORMODEL "auxVariablePredatorModel"


class auxVariablePredatorModel : public Atomic {
  public:
    
    auxVariablePredatorModel(const string &name = AUXVARIABLEPREDATORMODEL );
    virtual string className() const {  return AUXVARIABLEPREDATORMODEL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_cteVariable;
    Port &out_port_auxVariable;
    
    double cteVariable;
    bool isSet_cteVariable;
};

#endif