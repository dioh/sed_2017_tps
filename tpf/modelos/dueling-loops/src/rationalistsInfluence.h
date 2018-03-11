#ifndef _rationalistsInfluence_H_
#define _rationalistsInfluence_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RATIONALISTSINFLUENCE "rationalistsInfluence"


class rationalistsInfluence : public Atomic {
  public:
    
    rationalistsInfluence(const string &name = RATIONALISTSINFLUENCE );
    virtual string className() const {  return RATIONALISTSINFLUENCE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &RationalSupporters;
    const Port &influencePerRationalist;
    Port &out;
    

    double val_RationalSupporters;
    double val_influencePerRationalist;
    bool isSet_val_RationalSupporters;
    bool isSet_val_influencePerRationalist;
    
};

#endif