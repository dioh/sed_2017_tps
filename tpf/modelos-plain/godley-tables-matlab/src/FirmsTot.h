#ifndef _FirmsTot_H_
#define _FirmsTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FIRMSTOT "FirmsTot"

class FirmsTot : public Atomic {
  public:
    
    FirmsTot(const string &name = FIRMSTOT );
    virtual string className() const {  return FIRMSTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgFirmsPlus;
    Port &out;
    

    double val_chgFirmsPlus;
    bool isSet_val_chgFirmsPlus;
    
    
};

#endif