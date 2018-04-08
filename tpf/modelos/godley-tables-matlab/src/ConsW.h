#ifndef _ConsW_H_
#define _ConsW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CONSW "ConsW"


class ConsW : public Atomic {
  public:
    
    ConsW(const string &name = CONSW );
    virtual string className() const {  return CONSW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Workers;
    const Port &tauWVal;
    Port &out;
    

    double val_Workers;
    double val_tauWVal;
    bool isSet_val_Workers;
    bool isSet_val_tauWVal;
    
};

#endif