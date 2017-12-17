#ifndef _fp_Recovered_Recovering_H_
#define _fp_Recovered_Recovering_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FP_RECOVERED_RECOVERING "fp_Recovered_Recovering"

class fp_Recovered_Recovering : public Atomic {
  public:
    fp_Recovered_Recovering(const string &name = FP_RECOVERED_RECOVERING );
    virtual string className() const {  return FP_RECOVERED_RECOVERING ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_Infectious;
    const Port &in_Duration;
    Port &out;
    

    double Infectious;
    double Duration;
    bool isSet_Infectious;
    bool isSet_Duration;
    //
};

#endif