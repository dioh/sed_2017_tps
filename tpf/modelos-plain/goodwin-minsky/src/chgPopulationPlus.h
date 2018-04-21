#ifndef _chgPopulationPlus_H_
#define _chgPopulationPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGPOPULATIONPLUS "chgPopulationPlus"


class chgPopulationPlus : public Atomic {
  public:
    
    chgPopulationPlus(const string &name = CHGPOPULATIONPLUS );
    virtual string className() const {  return CHGPOPULATIONPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Betaa;
    const Port &Population;
    Port &out;
    

    double val_Betaa;
    double val_Population;
    bool isSet_val_Betaa;
    bool isSet_val_Population;
    
};

#endif