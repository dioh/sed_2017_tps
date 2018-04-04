#ifndef _PlusPrey_PreyDEVS_BASIC_COUPLED_Prey_H_
#define _PlusPrey_PreyDEVS_BASIC_COUPLED_Prey_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PLUSPREY_PREYDEVS_BASIC_COUPLED_PREY "PlusPrey_PreyDEVS_BASIC_COUPLED_Prey"


class PlusPrey_PreyDEVS_BASIC_COUPLED_Prey : public Atomic {
  public:
    
    PlusPrey_PreyDEVS_BASIC_COUPLED_Prey(const string &name = PLUSPREY_PREYDEVS_BASIC_COUPLED_PREY );
    virtual string className() const {  return PLUSPREY_PREYDEVS_BASIC_COUPLED_PREY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &Prey;
    const Port &paramA;
    const Port &PreySubModelStock;
    Port &PlusPrey_Prey;
    
    double Prey;
    double paramA;
    double PreySubModelStock;
    bool isSet_Prey;
    bool isSet_paramA;
    bool isSet_PreySubModelStock;
};

#endif