#ifndef _PiIG_H_
#define _PiIG_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PIIG "PiIG"


class PiIG : public Atomic {
  public:
    
    PiIG(const string &name = PIIG );
    virtual string className() const {  return PIIG ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &YIValue;
    const Port &WagesI;
    Port &out;
    

    double val_YIValue;
    double val_WagesI;
    bool isSet_val_YIValue;
    bool isSet_val_WagesI;
    
};

#endif