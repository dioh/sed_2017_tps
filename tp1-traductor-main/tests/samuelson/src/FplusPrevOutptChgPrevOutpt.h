#ifndef _FplusPrevOutptChgPrevOutpt_H_
#define _FplusPrevOutptChgPrevOutpt_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSPREVOUTPTCHGPREVOUTPT "FplusPrevOutptChgPrevOutpt"

class FplusPrevOutptChgPrevOutpt : public Atomic {
  public:
    
    FplusPrevOutptChgPrevOutpt(const string &name = FPLUSPREVOUTPTCHGPREVOUTPT );
    virtual string className() const {  return FPLUSPREVOUTPTCHGPREVOUTPT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_output;
    const Port &in_prevOutptIntegrator;
    const Port &in_twounitTimestep;
    // Output ports
    Port &out;

    // State variables
    double output;
    double prevOutptIntegrator;
    double twounitTimestep;
    //
    // Check set of state variables
    bool isSet_output;
    bool isSet_prevOutptIntegrator;
    bool isSet_twounitTimestep;
    //
};

#endif