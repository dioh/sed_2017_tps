#ifndef _combinerPreySubSubModel_H_
#define _combinerPreySubSubModel_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define COMBINERPREYSUBSUBMODEL "combinerPreySubSubModel"


class combinerPreySubSubModel : public Atomic {
  public:
    
    combinerPreySubSubModel(const string &name = COMBINERPREYSUBSUBMODEL );
    virtual string className() const {  return COMBINERPREYSUBSUBMODEL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Prey;
    const Port &in_port_ctePulse;
    Port &out_port_combiner;
    
    double Prey;
    double ctePulse;
    bool isSet_Prey;
    bool isSet_ctePulse;
};

#endif