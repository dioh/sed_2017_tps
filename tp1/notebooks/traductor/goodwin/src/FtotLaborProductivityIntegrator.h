#ifndef _FtotLaborProductivityIntegrator_H_
#define _FtotLaborProductivityIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTLABORPRODUCTIVITYINTEGRATOR "FtotLaborProductivityIntegrator"

class FtotLaborProductivityIntegrator : public Atomic {
  public:
    
    FtotLaborProductivityIntegrator(const string &name = FTOTLABORPRODUCTIVITYINTEGRATOR );
    virtual string className() const {  return FTOTLABORPRODUCTIVITYINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_chgLaborProductivity;
    Port &out;
    

    double val_inPlus_chgLaborProductivity;
    bool isSet_val_inPlus_chgLaborProductivity;
    
};

#endif