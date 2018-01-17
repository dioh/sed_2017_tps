#ifndef _Wages_H_
#define _Wages_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WAGES "Wages"


class Wages : public Atomic {
  public:
    
    Wages(const string &name = WAGES );
    virtual string className() const {  return WAGES ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &WageRate;
    const Port &Labor;
    Port &out;
    

    double val_WageRate;
    double val_Labor;
    bool isSet_val_WageRate;
    bool isSet_val_Labor;
    
};

#endif