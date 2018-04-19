#ifndef _TotwageRate_H_
#define _TotwageRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTWAGERATE "TotwageRate"

class TotwageRate : public Atomic {
  public:
    
    TotwageRate(const string &name = TOTWAGERATE );
    virtual string className() const {  return TOTWAGERATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate;
    
    Port &out_port_TotwageRate;

    double chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate;
    bool isSet_chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate;
    
    
};

#endif