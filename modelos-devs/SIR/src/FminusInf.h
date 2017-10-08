#ifndef _FminusInf_H_
#define _FminusInf_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FMINUSINF "FminusInf"


class FminusInf : public Atomic {
  public:
    
    FminusInf(const string &name = FMINUSINF );
    virtual string className() const {  return FMINUSINF ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inInfected;
    const Port &inDuration;
    Port &out;

    double infected;
    bool isSetInfected;

    double duration;
    bool isSetDuration;
};

#endif
