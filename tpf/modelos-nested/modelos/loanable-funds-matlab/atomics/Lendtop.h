#ifndef _Lendtop_H_
#define _Lendtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define LENDTOP "Lendtop"


class Lendtop : public Atomic {
  public:
    
    Lendtop(const string &name = LENDTOP );
    virtual string className() const {  return LENDTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_DepCons;
    const Port &in_port_tauL;
    Port &out_port_Lend;
    
    double DepCons;
    double tauL;
    bool isSet_DepCons;
    bool isSet_tauL;
};

#endif