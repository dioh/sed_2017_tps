#ifndef _AuxpiR_H_
#define _AuxpiR_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXPIR "AuxpiR"


class AuxpiR : public Atomic {
  public:
    
    AuxpiR(const string &name = AUXPIR );
    virtual string className() const {  return AUXPIR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_profitNet;
    const Port &in_capitalIntegrator;
    // Output ports
    Port &out;

    // State variables
    double capitalIntegrator;
    double profitNet;
    //
    // Check set of state variables
    bool isSet_capitalIntegrator;
    bool isSet_profitNet;
    //
};

#endif