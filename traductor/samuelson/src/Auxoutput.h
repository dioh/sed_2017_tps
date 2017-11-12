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
    const Port &in_Investment;
    const Port &in_Consumption;
    const Port &in_governmentSpending;
    // Output ports
    Port &out;

    // State variables
    double Investment;
    double Consumption;
    double governmentSpending;
    //
    // Check set of state variables
    bool isSet_Investment;
    bool isSet_Consumption;
    bool isSet_governmentSpending;
    //
};

#endif