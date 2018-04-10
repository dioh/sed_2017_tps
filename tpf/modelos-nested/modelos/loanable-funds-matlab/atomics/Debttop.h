#ifndef _Debttop_H_
#define _Debttop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define DEBTTOP "Debttop"


class Debttop : public Atomic {
  public:
    
    Debttop(const string &name = DEBTTOP );
    virtual string className() const {  return DEBTTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Loans;
    Port &out_port_Debt;
    
    double Loans;
    bool isSet_Loans;
};

#endif