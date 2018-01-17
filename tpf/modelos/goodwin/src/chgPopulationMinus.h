#ifndef _chgPopulationMinus_H_
#define _chgPopulationMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGPOPULATIONMINUS "chgPopulationMinus"


class chgPopulationMinus : public Atomic {
  public:
    
    chgPopulationMinus(const string &name = CHGPOPULATIONMINUS );
    virtual string className() const {  return CHGPOPULATIONMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Population;
    Port &out;
    

    double val_Population;
    bool isSet_val_Population;
    
};

#endif