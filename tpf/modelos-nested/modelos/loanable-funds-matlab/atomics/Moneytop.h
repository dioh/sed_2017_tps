#ifndef _Moneytop_H_
#define _Moneytop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define MONEYTOP "Moneytop"


class Moneytop : public Atomic {
  public:
    
    Moneytop(const string &name = MONEYTOP );
    virtual string className() const {  return MONEYTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_BankersNW;
    const Port &in_port_Workers;
    const Port &in_port_DepInv;
    const Port &in_port_DepCons;
    Port &out_port_Money;
    
    double BankersNW;
    double Workers;
    double DepInv;
    double DepCons;
    bool isSet_BankersNW;
    bool isSet_Workers;
    bool isSet_DepInv;
    bool isSet_DepCons;
};

#endif