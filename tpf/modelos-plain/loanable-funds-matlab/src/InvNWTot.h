#ifndef _InvNWTot_H_
#define _InvNWTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define INVNWTOT "InvNWTot"

class InvNWTot : public Atomic {
  public:
    
    InvNWTot(const string &name = INVNWTOT );
    virtual string className() const {  return INVNWTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgInvNWPlus;
    Port &out;
    

    double val_chgInvNWPlus;
    bool isSet_val_chgInvNWPlus;
    
    
};

#endif