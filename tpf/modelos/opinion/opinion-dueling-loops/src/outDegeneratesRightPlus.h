#ifndef _outDegeneratesRightPlus_H_
#define _outDegeneratesRightPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define OUTDEGENERATESRIGHTPLUS "outDegeneratesRightPlus"


class outDegeneratesRightPlus : public Atomic {
  public:
    
    outDegeneratesRightPlus(const string &name = OUTDEGENERATESRIGHTPLUS );
    virtual string className() const {  return OUTDEGENERATESRIGHTPLUS ;}
  
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