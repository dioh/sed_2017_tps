#ifndef _DepInvTot_H_
#define _DepInvTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define DEPINVTOT "DepInvTot"

class DepInvTot : public Atomic {
  public:
    
    DepInvTot(const string &name = DEPINVTOT );
    virtual string className() const {  return DEPINVTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgDepInvPlus;
    Port &out;
    

    double val_chgDepInvPlus;
    bool isSet_val_chgDepInvPlus;
    
    
};

#endif