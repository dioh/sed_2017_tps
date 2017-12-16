#ifndef _FtotPopulationIntegrator_H_
#define _FtotPopulationIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTPOPULATIONINTEGRATOR "FtotPopulationIntegrator"

class FtotPopulationIntegrator : public Atomic {
  public:
    
    FtotPopulationIntegrator(const string &name = FTOTPOPULATIONINTEGRATOR );
    virtual string className() const {  return FTOTPOPULATIONINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_chgPopulation;
    Port &out;
    

    double val_inPlus_chgPopulation;
    bool isSet_val_inPlus_chgPopulation;
    
};

#endif