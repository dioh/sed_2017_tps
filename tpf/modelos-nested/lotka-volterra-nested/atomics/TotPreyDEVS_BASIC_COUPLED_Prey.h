#ifndef _TotPreyDEVS_BASIC_COUPLED_Prey_H_
#define _TotPreyDEVS_BASIC_COUPLED_Prey_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTPREYDEVS_BASIC_COUPLED_PREY "TotPreyDEVS_BASIC_COUPLED_Prey"

class TotPreyDEVS_BASIC_COUPLED_Prey : public Atomic {
  public:
    
    TotPreyDEVS_BASIC_COUPLED_Prey(const string &name = TOTPREYDEVS_BASIC_COUPLED_PREY );
    virtual string className() const {  return TOTPREYDEVS_BASIC_COUPLED_PREY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &PlusPrey_Prey;
    const Port &MinusPrey_Prey;
    

    double PlusPrey_Prey;
    double MinusPrey_Prey;
    bool isSet_PlusPrey_Prey;
    
    bool isSet_MinusPrey_Prey;
    
};

#endif