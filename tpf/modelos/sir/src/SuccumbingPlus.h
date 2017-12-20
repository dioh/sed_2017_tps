#ifndef _SuccumbingPlus_H_
#define _SuccumbingPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define SUCCUMBINGPLUS "SuccumbingPlus"


class SuccumbingPlus : public Atomic {
  public:
    
    SuccumbingPlus(const string &name = SUCCUMBINGPLUS );
    virtual string className() const {  return SUCCUMBINGPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Susceptibles;
    const Port &Infected;
    const Port &InfectionRate;
    const Port &TotalPopulation;
    Port &out;
    

    double val_Susceptibles;
    double val_Infected;
    double val_InfectionRate;
    double val_TotalPopulation;
    bool isSet_val_Susceptibles;
    bool isSet_val_Infected;
    bool isSet_val_InfectionRate;
    bool isSet_val_TotalPopulation;
    
};

#endif