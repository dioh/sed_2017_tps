#ifndef _PopulationTot_H_
#define _PopulationTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define POPULATIONTOT "PopulationTot"

class PopulationTot : public Atomic {
  public:
    
    PopulationTot(const string &name = POPULATIONTOT );
    virtual string className() const {  return POPULATIONTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgPopulationPlus;
    Port &out;
    

    double val_chgPopulationPlus;
    bool isSet_val_chgPopulationPlus;
    
    
};

#endif