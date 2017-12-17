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
    const Port &in_WageRate;
    const Port &in_Labor;
    Port &out;
    

    double WageRate;
    double Labor;
    bool isSet_WageRate;
    bool isSet_Labor;
    //
};

#endif