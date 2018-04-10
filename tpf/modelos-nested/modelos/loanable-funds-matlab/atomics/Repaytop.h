#ifndef _Repaytop_H_
#define _Repaytop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define REPAYTOP "Repaytop"


class Repaytop : public Atomic {
  public:
    
    Repaytop(const string &name = REPAYTOP );
    virtual string className() const {  return REPAYTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Loans;
    const Port &in_port_tauR;
    Port &out_port_Repay;
    
    double Loans;
    double tauR;
    bool isSet_Loans;
    bool isSet_tauR;
};

#endif