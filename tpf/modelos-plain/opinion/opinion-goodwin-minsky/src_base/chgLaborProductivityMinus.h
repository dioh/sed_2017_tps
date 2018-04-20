#ifndef _chgLaborProductivityMinus_H_
#define _chgLaborProductivityMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGLABORPRODUCTIVITYMINUS "chgLaborProductivityMinus"


class chgLaborProductivityMinus : public Atomic {
  public:
    
    chgLaborProductivityMinus(const string &name = CHGLABORPRODUCTIVITYMINUS );
    virtual string className() const {  return CHGLABORPRODUCTIVITYMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Alphaa;
    const Port &LaborProductivity;
    Port &out;
    

    double val_Alphaa;
    double val_LaborProductivity;
    bool isSet_val_Alphaa;
    bool isSet_val_LaborProductivity;
    
};

#endif