#ifndef _AuxgovernmentSpending_H_
#define _AuxgovernmentSpending_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXGOVERNMENTSPENDING "AuxgovernmentSpending"


class AuxgovernmentSpending : public Atomic {
  public:
    
    AuxgovernmentSpending(const string &name = AUXGOVERNMENTSPENDING );
    virtual string className() const {  return AUXGOVERNMENTSPENDING ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_basespending;
    const Port &in_spendingstep;
    const Port &in_PULSE;
    const Port &in_steptime,tIMESTEP1;
    // Output ports
    Port &out;

    // State variables
    double spendingstep;
    double basespending;
    double steptime,tIMESTEP1;
    double PULSE;
    //
    // Check set of state variables
    bool isSet_spendingstep;
    bool isSet_basespending;
    bool isSet_steptime,tIMESTEP1;
    bool isSet_PULSE;
    //
};

#endif