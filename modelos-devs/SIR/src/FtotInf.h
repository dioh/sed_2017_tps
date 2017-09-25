#ifndef _FtotInf_H_
#define _FtotInf_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FTOTINF "FtotInf"


class FtotInf : public Atomic {
  public:
    
    FtotInf(const string &name = FTOTINF );
    virtual string className() const {  return FTOTINF ;}
  
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
