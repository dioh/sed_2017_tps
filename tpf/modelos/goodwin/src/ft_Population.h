#ifndef _ft_Population_H_
#define _ft_Population_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FT_POPULATION "ft_Population"

class ft_Population : public Atomic {
  public:
    
    ft_Population(const string &name = FT_POPULATION );
    virtual string className() const {  return FT_POPULATION ;}
  
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
    //
};

#endif