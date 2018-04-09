#ifndef _specialParamCPredatorModel_H_
#define _specialParamCPredatorModel_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define SPECIALPARAMCPREDATORMODEL "specialParamCPredatorModel"


class specialParamCPredatorModel : public Atomic {
  public:
    
    specialParamCPredatorModel(const string &name = SPECIALPARAMCPREDATORMODEL );
    virtual string className() const {  return SPECIALPARAMCPREDATORMODEL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &specialParamC;
    
    Port &specialParamC;
    
    double specialParamC;
    };

#endif