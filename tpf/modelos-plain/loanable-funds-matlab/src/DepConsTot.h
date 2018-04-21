#ifndef _DepConsTot_H_
#define _DepConsTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define DEPCONSTOT "DepConsTot"

class DepConsTot : public Atomic {
  public:
    
    DepConsTot(const string &name = DEPCONSTOT );
    virtual string className() const {  return DEPCONSTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgDepConsPlus;
    Port &out;
    

    double val_chgDepConsPlus;
    bool isSet_val_chgDepConsPlus;
    
    
};

#endif