#ifndef _MinusPrey_PreyDEVS_BASIC_COUPLED_Prey_H_
#define _MinusPrey_PreyDEVS_BASIC_COUPLED_Prey_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define MINUSPREY_PREYDEVS_BASIC_COUPLED_PREY "MinusPrey_PreyDEVS_BASIC_COUPLED_Prey"


class MinusPrey_PreyDEVS_BASIC_COUPLED_Prey : public Atomic {
  public:
    
    MinusPrey_PreyDEVS_BASIC_COUPLED_Prey(const string &name = MINUSPREY_PREYDEVS_BASIC_COUPLED_PREY );
    virtual string className() const {  return MINUSPREY_PREYDEVS_BASIC_COUPLED_PREY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Predator;
    const Port &in_port_Prey;
    const Port &in_port_paramB;
    Port &out_port_MinusPrey_Prey;
    
    double Predator;
    double Prey;
    double paramB;
    bool isSet_Predator;
    bool isSet_Prey;
    bool isSet_paramB;
};

#endif