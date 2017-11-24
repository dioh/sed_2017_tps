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
    const Port &in_investment;
    const Port &in_consumption;
    const Port &in_governmentSpending;
    // Output ports
    Port &out;

    // State variables
    double investment;
    double consumption;
    double governmentSpending;
    //
    // Check set of state variables
    bool isSet_investment;
    bool isSet_consumption;
    bool isSet_governmentSpending;
    //
};

#endif