#ifndef _Auxprofit_H_
#define _Auxprofit_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXPROFIT "Auxprofit"


class Auxprofit : public Atomic {
  public:
    
    Auxprofit(const string &name = AUXPROFIT );
    virtual string className() const {  return AUXPROFIT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_output;
    const Port &in_wageBill;
    // Output ports
    Port &out;

    // State variables
    double output;
    double wageBill;
    //
    // Check set of state variables
    bool isSet_output;
    bool isSet_wageBill;
    //
};

#endif