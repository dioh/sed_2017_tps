#ifndef _ft_WageRate_H_
#define _ft_WageRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FT_WAGERATE "ft_WageRate"

class ft_WageRate : public Atomic {
  public:
    
    ft_WageRate(const string &name = FT_WAGERATE );
    virtual string className() const {  return FT_WAGERATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_chgWageRate;
    Port &out;
    

    double val_inPlus_chgWageRate;
    bool isSet_val_inPlus_chgWageRate;
    //
};

#endif