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
    const Port &tauWC;
    Port &out;
    

    double val_Workers;
    double val_tauWC;
    bool isSet_val_Workers;
    bool isSet_val_tauWC;
    
};

#endif