#ifndef _YCValue_H_
#define _YCValue_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define YCVALUE "YCValue"


class YCValue : public Atomic {
  public:
    
    YCValue(const string &name = YCVALUE );
    virtual string className() const {  return YCVALUE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &DepCons;
    const Port &tauMC;
    Port &out;
    

    double val_DepCons;
    double val_tauMC;
    bool isSet_val_DepCons;
    bool isSet_val_tauMC;
    
};

#endif