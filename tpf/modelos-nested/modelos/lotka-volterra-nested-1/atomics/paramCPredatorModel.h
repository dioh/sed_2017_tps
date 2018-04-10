#ifndef _paramCPredatorModel_H_
#define _paramCPredatorModel_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PARAMCPREDATORMODEL "paramCPredatorModel"


class paramCPredatorModel : public Atomic {
  public:
    
    paramCPredatorModel(const string &name = PARAMCPREDATORMODEL );
    virtual string className() const {  return PARAMCPREDATORMODEL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_paramC;
    
    Port &out_port_paramC;
    
    double paramC;
    };

#endif