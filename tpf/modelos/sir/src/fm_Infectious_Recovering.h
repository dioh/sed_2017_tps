#ifndef _fm_Infectious_Recovering_H_
#define _fm_Infectious_Recovering_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FM_INFECTIOUS_RECOVERING "fm_Infectious_Recovering"

class fm_Infectious_Recovering : public Atomic {
  public:
    fm_Infectious_Recovering(const string &name = FM_INFECTIOUS_RECOVERING );
    virtual string className() const {  return FM_INFECTIOUS_RECOVERING ;}
  
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