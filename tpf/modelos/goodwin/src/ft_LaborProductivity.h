#ifndef _ft_LaborProductivity_H_
#define _ft_LaborProductivity_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FT_LABORPRODUCTIVITY "ft_LaborProductivity"

class ft_LaborProductivity : public Atomic {
  public:
    
    ft_LaborProductivity(const string &name = FT_LABORPRODUCTIVITY );
    virtual string className() const {  return FT_LABORPRODUCTIVITY ;}
  
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
    //
};

#endif