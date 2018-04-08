#ifndef _ConsNWTot_H_
#define _ConsNWTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define CONSNWTOT "ConsNWTot"

class ConsNWTot : public Atomic {
  public:
    
    ConsNWTot(const string &name = CONSNWTOT );
    virtual string className() const {  return CONSNWTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgConsNWPlus;
    Port &out;
    

    double val_chgConsNWPlus;
    bool isSet_val_chgConsNWPlus;
    
    
};

#endif