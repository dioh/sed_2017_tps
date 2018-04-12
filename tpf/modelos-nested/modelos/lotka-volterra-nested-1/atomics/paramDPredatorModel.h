#ifndef _paramDPredatorModel_H_
#define _paramDPredatorModel_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PARAMDPREDATORMODEL "paramDPredatorModel"


class paramDPredatorModel : public Atomic {
  public:
    
    paramDPredatorModel(const string &name = PARAMDPREDATORMODEL );
    virtual string className() const {  return PARAMDPREDATORMODEL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_paramD;
    
    Port &out_port_paramD;
    
    double paramD;
    };

#endif