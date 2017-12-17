#ifndef _fm_Susceptible_Succumbing_H_
#define _fm_Susceptible_Succumbing_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FM_SUSCEPTIBLE_SUCCUMBING "fm_Susceptible_Succumbing"

class fm_Susceptible_Succumbing : public Atomic {
  public:
    fm_Susceptible_Succumbing(const string &name = FM_SUSCEPTIBLE_SUCCUMBING );
    virtual string className() const {  return FM_SUSCEPTIBLE_SUCCUMBING ;}
  
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