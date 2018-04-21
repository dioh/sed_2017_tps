#ifndef _ctePulsePreySubSubModel_H_
#define _ctePulsePreySubSubModel_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CTEPULSEPREYSUBSUBMODEL "ctePulsePreySubSubModel"


class ctePulsePreySubSubModel : public Atomic {
  public:
    
    ctePulsePreySubSubModel(const string &name = CTEPULSEPREYSUBSUBMODEL );
    virtual string className() const {  return CTEPULSEPREYSUBSUBMODEL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_ctePulse;
    
    Port &out_port_ctePulse;
    
    double ctePulse;
    };

#endif