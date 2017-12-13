#ifndef _FplusPredatorPlusPredator_H_
#define _FplusPredatorPlusPredator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSPREDATORPLUSPREDATOR "FplusPredatorPlusPredator"

class FplusPredatorPlusPredator : public Atomic {
  public:
    
    FplusPredatorPlusPredator(const string &name = FPLUSPREDATORPLUSPREDATOR );
    virtual string className() const {  return FPLUSPREDATORPLUSPREDATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_preyIntegrator;
    const Port &in_predatorIntegrator;
    // Output ports
    Port &out;

    // State variables
    double predatorIntegrator;
    double preyIntegrator;
    //
    // Check set of state variables
    bool isSet_predatorIntegrator;
    bool isSet_preyIntegrator;
    //
};

#endif