#ifndef _YIValue_H_
#define _YIValue_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define YIVALUE "YIValue"


class YIValue : public Atomic {
  public:
    
    YIValue(const string &name = YIVALUE );
    virtual string className() const {  return YIVALUE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &DepInv;
    const Port &tauMI;
    Port &out;
    

    double val_DepInv;
    double val_tauMI;
    bool isSet_val_DepInv;
    bool isSet_val_tauMI;
    
};

#endif