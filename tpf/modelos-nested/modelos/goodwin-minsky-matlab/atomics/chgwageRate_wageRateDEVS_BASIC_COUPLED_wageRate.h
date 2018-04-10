#ifndef _chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate_H_
#define _chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGWAGERATE_WAGERATEDEVS_BASIC_COUPLED_WAGERATE "chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate"


class chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate : public Atomic {
  public:
    
    chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate(const string &name = CHGWAGERATE_WAGERATEDEVS_BASIC_COUPLED_WAGERATE );
    virtual string className() const {  return CHGWAGERATE_WAGERATEDEVS_BASIC_COUPLED_WAGERATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_wageFunction;
    const Port &in_port_wageRate;
    Port &out_port_chgwageRate_wageRate;
    
    double wageFunction;
    double wageRate;
    bool isSet_wageFunction;
    bool isSet_wageRate;
};

#endif