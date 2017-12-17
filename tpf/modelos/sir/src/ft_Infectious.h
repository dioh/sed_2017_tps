#ifndef _ft_Infectious_H_
#define _ft_Infectious_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FT_INFECTIOUS "ft_Infectious"

class ft_Infectious : public Atomic {
  public:
    
    ft_Infectious(const string &name = FT_INFECTIOUS );
    virtual string className() const {  return FT_INFECTIOUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inMinus_Recovering;
    const Port &inPlus_Succumbing;
    Port &out;
    

    double val_inMinus_Recovering;
    double val_inPlus_Succumbing;
    bool isSet_val_inMinus_Recovering;
    bool isSet_val_inPlus_Succumbing;
    //
};

#endif