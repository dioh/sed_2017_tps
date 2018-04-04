#ifndef _paramAPreyModel_H_
#define _paramAPreyModel_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PARAMAPREYMODEL "paramAPreyModel"


class paramAPreyModel : public Atomic {
  public:
    
    paramAPreyModel(const string &name = PARAMAPREYMODEL );
    virtual string className() const {  return PARAMAPREYMODEL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &paramA;
    
    Port &paramA;
    
    double paramA;
    };

#endif