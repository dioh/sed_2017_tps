#ifndef _degeneratesInfluence_H_
#define _degeneratesInfluence_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define DEGENERATESINFLUENCE "degeneratesInfluence"


class degeneratesInfluence : public Atomic {
  public:
    
    degeneratesInfluence(const string &name = DEGENERATESINFLUENCE );
    virtual string className() const {  return DEGENERATESINFLUENCE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Degenerates;
    const Port &influencePerDegenerate;
    Port &out;
    

    double val_Degenerates;
    double val_influencePerDegenerate;
    bool isSet_val_Degenerates;
    bool isSet_val_influencePerDegenerate;
    
};

#endif