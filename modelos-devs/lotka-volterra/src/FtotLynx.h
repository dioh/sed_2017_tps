#ifndef _FtotLynx_H_
#define _FtotLynx_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FTOTLYNX "FtotLynx"


class FtotLynx : public Atomic {
  public:
    
    FtotLynx(const string &name = FTOTLYNX );
    virtual string className() const {  return FTOTLYNX ;}
  
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
