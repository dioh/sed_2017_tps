#ifndef _FminusPredatorMinusPredator_H_
#define _FminusPredatorMinusPredator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSPREDATORMINUSPREDATOR "FminusPredatorMinusPredator"

class FminusPredatorMinusPredator : public Atomic {
  public:
    
    FminusPredatorMinusPredator(const string &name = FMINUSPREDATORMINUSPREDATOR );
    virtual string className() const {  return FMINUSPREDATORMINUSPREDATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_predatorIntegrator;
    // Output ports
    Port &out;

    // State variables
    double predatorIntegrator;
    //
    // Check set of state variables
    bool isSet_predatorIntegrator;
    //
};

#endif