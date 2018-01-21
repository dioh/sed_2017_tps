#ifndef _outDegeneratesLeftPlus_H_
#define _outDegeneratesLeftPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define OUTDEGENERATESLEFTPLUS "outDegeneratesLeftPlus"


class outDegeneratesLeftPlus : public Atomic {
  public:
    
    outDegeneratesLeftPlus(const string &name = OUTDEGENERATESLEFTPLUS );
    virtual string className() const {  return OUTDEGENERATESLEFTPLUS ;}
  
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