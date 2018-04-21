#ifndef _LaborProductivityTot_H_
#define _LaborProductivityTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define LABORPRODUCTIVITYTOT "LaborProductivityTot"

class LaborProductivityTot : public Atomic {
  public:
    
    LaborProductivityTot(const string &name = LABORPRODUCTIVITYTOT );
    virtual string className() const {  return LABORPRODUCTIVITYTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgLaborProductivityPlus;
    Port &out;
    

    double val_chgLaborProductivityPlus;
    bool isSet_val_chgLaborProductivityPlus;
    
    
};

#endif