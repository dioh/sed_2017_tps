#ifndef _chgLaborProductivityPlus_H_
#define _chgLaborProductivityPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGLABORPRODUCTIVITYPLUS "chgLaborProductivityPlus"


class chgLaborProductivityPlus : public Atomic {
  public:
    
    chgLaborProductivityPlus(const string &name = CHGLABORPRODUCTIVITYPLUS );
    virtual string className() const {  return CHGLABORPRODUCTIVITYPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &LaborProductivity;
    Port &out;
    

    double val_LaborProductivity;
    bool isSet_val_LaborProductivity;
    
};

#endif