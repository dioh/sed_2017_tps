#ifndef _ConsBtop_H_
#define _ConsBtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CONSBTOP "ConsBtop"


class ConsBtop : public Atomic {
  public:
    
    ConsBtop(const string &name = CONSBTOP );
    virtual string className() const {  return CONSBTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_BankersNW;
    const Port &in_port_tauBC;
    Port &out_port_ConsB;
    
    double BankersNW;
    double tauBC;
    bool isSet_BankersNW;
    bool isSet_tauBC;
};

#endif