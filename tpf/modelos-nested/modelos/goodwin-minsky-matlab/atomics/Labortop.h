#ifndef _Labortop_H_
#define _Labortop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define LABORTOP "Labortop"


class Labortop : public Atomic {
  public:
    
    Labortop(const string &name = LABORTOP );
    virtual string className() const {  return LABORTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Output;
    const Port &in_port_LaborProductivity;
    Port &out_port_Labor;
    
    double Output;
    double LaborProductivity;
    bool isSet_Output;
    bool isSet_LaborProductivity;
};

#endif