#ifndef _outDegeneratesRightMinus_H_
#define _outDegeneratesRightMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define OUTDEGENERATESRIGHTMINUS "outDegeneratesRightMinus"


class outDegeneratesRightMinus : public Atomic {
  public:
    
    outDegeneratesRightMinus(const string &name = OUTDEGENERATESRIGHTMINUS );
    virtual string className() const {  return OUTDEGENERATESRIGHTMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Degenerates;
    Port &out;
    

    double val_Degenerates;
    bool isSet_val_Degenerates;
    
};

#endif