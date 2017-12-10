#ifndef _FminusPreyMinusPrey_H_
#define _FminusPreyMinusPrey_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSPREYMINUSPREY "FminusPreyMinusPrey"

class FminusPreyMinusPrey : public Atomic {
  public:
    
    FminusPreyMinusPrey(const string &name = FMINUSPREYMINUSPREY );
    virtual string className() const {  return FMINUSPREYMINUSPREY ;}
  
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