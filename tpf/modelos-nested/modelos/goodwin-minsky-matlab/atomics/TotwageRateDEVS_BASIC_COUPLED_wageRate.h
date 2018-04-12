#ifndef _TotwageRateDEVS_BASIC_COUPLED_wageRate_H_
#define _TotwageRateDEVS_BASIC_COUPLED_wageRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTWAGERATEDEVS_BASIC_COUPLED_WAGERATE "TotwageRateDEVS_BASIC_COUPLED_wageRate"

class TotwageRateDEVS_BASIC_COUPLED_wageRate : public Atomic {
  public:
    
    TotwageRateDEVS_BASIC_COUPLED_wageRate(const string &name = TOTWAGERATEDEVS_BASIC_COUPLED_WAGERATE );
    virtual string className() const {  return TOTWAGERATEDEVS_BASIC_COUPLED_WAGERATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgwageRate_wageRate;
    
    Port &out_port_TotwageRate;

    double chgwageRate_wageRate;
    bool isSet_chgwageRate_wageRate;
    
    
};

#endif