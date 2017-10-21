#ifndef _FminusInfected_H_
#define _FminusInfected_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSINFECTED "FminusInfected"

class FminusInfected : public Atomic {
  public:
    
    FminusInfected(const string &name = FMINUSINFECTED );
    virtual string className() const {  return FMINUSINFECTED ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &inInfected;
    const Port &inDuration;
    // Output ports
    Port &out;

    // State variables
    double infected;
    double duration;
    //
    // Check set of state variables
    bool isSetInfected;
    bool isSetDuration;
    //
};

#endif