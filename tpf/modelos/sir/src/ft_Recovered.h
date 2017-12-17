#ifndef _ft_Recovered_H_
#define _ft_Recovered_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FT_RECOVERED "ft_Recovered"

class ft_Recovered : public Atomic {
  public:
    
    ft_Recovered(const string &name = FT_RECOVERED );
    virtual string className() const {  return FT_RECOVERED ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_Recovering;
    Port &out;
    

    double val_inPlus_Recovering;
    bool isSet_val_inPlus_Recovering;
    //
};

#endif