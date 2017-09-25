#ifndef _FtotSusc_H_
#define _FtotSusc_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FTOTSUSC "FtotSusc"


class FtotSusc : public Atomic {
  public:
    
    FtotSusc(const string &name = FTOTSUSC );
    virtual string className() const {  return FTOTSUSC ;}
  
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
