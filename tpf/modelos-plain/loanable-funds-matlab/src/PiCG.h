#ifndef _PiCG_H_
#define _PiCG_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PICG "PiCG"


class PiCG : public Atomic {
  public:
    
    PiCG(const string &name = PICG );
    virtual string className() const {  return PICG ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &YCValue;
    const Port &WagesC;
    Port &out;
    

    double val_YCValue;
    double val_WagesC;
    bool isSet_val_YCValue;
    bool isSet_val_WagesC;
    
};

#endif