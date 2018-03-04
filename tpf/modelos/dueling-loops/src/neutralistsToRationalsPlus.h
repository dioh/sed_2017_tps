#ifndef _neutralistsToRationalsPlus_H_
#define _neutralistsToRationalsPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define NEUTRALISTSTORATIONALSPLUS "neutralistsToRationalsPlus"


class neutralistsToRationalsPlus : public Atomic {
  public:
    
    neutralistsToRationalsPlus(const string &name = NEUTRALISTSTORATIONALSPLUS );
    virtual string className() const {  return NEUTRALISTSTORATIONALSPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Neutralists;
    Port &out;
    

    double val_Neutralists;
    bool isSet_val_Neutralists;
    
};

#endif