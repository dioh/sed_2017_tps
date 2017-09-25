#ifndef _FtotRecov_H_
#define _FtotRecov_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FTOTRECOV "FtotRecov"


class FtotRecov : public Atomic {
  public:
    
    FtotRecov(const string &name = FTOTRECOV );
    virtual string className() const {  return FTOTRECOV ;}
  
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
