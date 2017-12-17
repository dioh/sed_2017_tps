#ifndef _fp_Population_chgPopulation_H_
#define _fp_Population_chgPopulation_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FP_POPULATION_CHGPOPULATION "fp_Population_chgPopulation"

class fp_Population_chgPopulation : public Atomic {
  public:
    fp_Population_chgPopulation(const string &name = FP_POPULATION_CHGPOPULATION );
    virtual string className() const {  return FP_POPULATION_CHGPOPULATION ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_Betaa;
    const Port &in_Population;
    Port &out;
    

    double Betaa;
    double Population;
    bool isSet_Betaa;
    bool isSet_Population;
    //
};

#endif