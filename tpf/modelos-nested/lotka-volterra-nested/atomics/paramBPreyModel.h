#ifndef _paramBPreyModel_H_
#define _paramBPreyModel_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PARAMBPREYMODEL "paramBPreyModel"


class paramBPreyModel : public Atomic {
  public:
    
    paramBPreyModel(const string &name = PARAMBPREYMODEL );
    virtual string className() const {  return PARAMBPREYMODEL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_paramB;
    
    Port &out_port_paramB;
    
    double paramB;
    };

#endif