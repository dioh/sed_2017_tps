#ifndef _SuccumbingMinus_H_
#define _SuccumbingMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define SUCCUMBINGMINUS "SuccumbingMinus"


class SuccumbingMinus : public Atomic {
  public:
    
    SuccumbingMinus(const string &name = SUCCUMBINGMINUS );
    virtual string className() const {  return SUCCUMBINGMINUS ;}
  
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