#ifndef _SusceptiblesTot_H_
#define _SusceptiblesTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define SUSCEPTIBLESTOT "SusceptiblesTot"

class SusceptiblesTot : public Atomic {
  public:
    
    SusceptiblesTot(const string &name = SUSCEPTIBLESTOT );
    virtual string className() const {  return SUSCEPTIBLESTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    Port &out;
    

    
    
};

#endif