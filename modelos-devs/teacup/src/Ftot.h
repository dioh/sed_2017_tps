#ifndef _Ftot_H_
#define _Ftot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FTOT "Ftot"


class Ftot : public Atomic {
  public:
    
    Ftot(const string &name = FTOT );
    virtual string className() const {  return FTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus, &inMinus;
    Port &out;

    double plus, minus;
};

#endif
