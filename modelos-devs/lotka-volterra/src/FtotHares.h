#ifndef _FtotHares_H_
#define _FtotHares_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FTOTHARES "FtotHares"


class FtotHares : public Atomic {
  public:
    
    FtotHares(const string &name = FTOTHARES );
    virtual string className() const {  return FTOTHARES ;}
  
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
