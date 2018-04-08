#ifndef _cteVariablePredatorModel_H_
#define _cteVariablePredatorModel_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CTEVARIABLEPREDATORMODEL "cteVariablePredatorModel"


class cteVariablePredatorModel : public Atomic {
  public:
    
    cteVariablePredatorModel(const string &name = CTEVARIABLEPREDATORMODEL );
    virtual string className() const {  return CTEVARIABLEPREDATORMODEL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &cteVariable;
    
    Port &cteVariable;
    
    double cteVariable;
    };

#endif