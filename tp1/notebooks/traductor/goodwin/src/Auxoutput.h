#ifndef _Auxoutput_H_
#define _Auxoutput_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXOUTPUT "Auxoutput"


class Auxoutput : public Atomic {
  public:
    
    Auxoutput(const string &name = AUXOUTPUT );
    virtual string className() const {  return AUXOUTPUT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_capitalIntegrator;
    const Port &in_velocityOfMoney;
    // Output ports
    Port &out;

    // State variables
    double capitalIntegrator;
    double velocityOfMoney;
    //
    // Check set of state variables
    bool isSet_capitalIntegrator;
    bool isSet_velocityOfMoney;
    //
};

#endif