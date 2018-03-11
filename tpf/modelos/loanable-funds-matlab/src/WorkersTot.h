#ifndef _WorkersTot_H_
#define _WorkersTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define WORKERSTOT "WorkersTot"

class WorkersTot : public Atomic {
  public:
    
    WorkersTot(const string &name = WORKERSTOT );
    virtual string className() const {  return WORKERSTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgWorkersPlus;
    Port &out;
    

    double val_chgWorkersPlus;
    bool isSet_val_chgWorkersPlus;
    
    
};

#endif