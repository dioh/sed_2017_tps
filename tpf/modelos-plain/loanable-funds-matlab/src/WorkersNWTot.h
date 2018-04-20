#ifndef _WorkersNWTot_H_
#define _WorkersNWTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define WORKERSNWTOT "WorkersNWTot"

class WorkersNWTot : public Atomic {
  public:
    
    WorkersNWTot(const string &name = WORKERSNWTOT );
    virtual string className() const {  return WORKERSNWTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgWorkersNWPlus;
    Port &out;
    

    double val_chgWorkersNWPlus;
    bool isSet_val_chgWorkersNWPlus;
    
    
};

#endif