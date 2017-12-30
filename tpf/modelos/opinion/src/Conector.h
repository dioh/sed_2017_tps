#ifndef _Conector_H_
#define _Conector_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define CONECTOR "Conector"

class Conector : public Atomic {
  public:
    
    Conector(const string &name = CONECTOR );
    virtual string className() const {  return CONECTOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:

    // Input ports
    const Port &inRationalSupporters;
    const Port &inDegenerates;
    const Port &inNeutralists;
    // Output ports
    Port &out;

    // State variables
    double RationalSupporters, prev_RationalSupporters;
    double Degenerates, prev_Degenerates;
    double Neutralists, prev_Neutralists;

    // Variables set
    bool isSet_RationalSupporters;
    bool isSet_Degenerates;
    bool isSet_Neutralists;

};

#endif