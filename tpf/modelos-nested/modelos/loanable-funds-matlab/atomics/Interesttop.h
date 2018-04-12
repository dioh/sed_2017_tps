#ifndef _Interesttop_H_
#define _Interesttop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INTERESTTOP "Interesttop"


class Interesttop : public Atomic {
  public:
    
    Interesttop(const string &name = INTERESTTOP );
    virtual string className() const {  return INTERESTTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_rLValue;
    const Port &in_port_Loans;
    Port &out_port_Interest;
    
    double rLValue;
    double Loans;
    bool isSet_rLValue;
    bool isSet_Loans;
};

#endif