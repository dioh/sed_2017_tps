#ifndef _AuxprofitGrossReal_H_
#define _AuxprofitGrossReal_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXPROFITGROSSREAL "AuxprofitGrossReal"


class AuxprofitGrossReal : public Atomic {
  public:
    
    AuxprofitGrossReal(const string &name = AUXPROFITGROSSREAL );
    virtual string className() const {  return AUXPROFITGROSSREAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_output;
    const Port &in_wages;
    // Output ports
    Port &out;

    // State variables
    double output;
    double wages;
    //
    // Check set of state variables
    bool isSet_output;
    bool isSet_wages;
    //
};

#endif