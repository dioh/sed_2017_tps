#ifndef _fp_Infectious_Succumbing_H_
#define _fp_Infectious_Succumbing_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FP_INFECTIOUS_SUCCUMBING "fp_Infectious_Succumbing"

class fp_Infectious_Succumbing : public Atomic {
  public:
    fp_Infectious_Succumbing(const string &name = FP_INFECTIOUS_SUCCUMBING );
    virtual string className() const {  return FP_INFECTIOUS_SUCCUMBING ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_Susceptible;
    const Port &in_Infectious;
    const Port &in_TotalPopulation;
    const Port &in_ContactInfectivity;
    Port &out;
    

    double Susceptible;
    double Infectious;
    double TotalPopulation;
    double ContactInfectivity;
    bool isSet_Susceptible;
    bool isSet_Infectious;
    bool isSet_TotalPopulation;
    bool isSet_ContactInfectivity;
    //
};

#endif