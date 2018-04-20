#ifndef _outDegeneratesLeftMinus_H_
#define _outDegeneratesLeftMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define OUTDEGENERATESLEFTMINUS "outDegeneratesLeftMinus"


class outDegeneratesLeftMinus : public Atomic {
  public:
    
    outDegeneratesLeftMinus(const string &name = OUTDEGENERATESLEFTMINUS );
    virtual string className() const {  return OUTDEGENERATESLEFTMINUS ;}
  
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