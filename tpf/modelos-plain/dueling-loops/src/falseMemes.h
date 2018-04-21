#ifndef _falseMemes_H_
#define _falseMemes_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FALSEMEMES "falseMemes"


class falseMemes : public Atomic {
  public:
    
    falseMemes(const string &name = FALSEMEMES );
    virtual string className() const {  return FALSEMEMES ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &degeneratesInfluence;
    const Port &falseMemeSize;
    Port &out;
    

    double val_degeneratesInfluence;
    double val_falseMemeSize;
    bool isSet_val_degeneratesInfluence;
    bool isSet_val_falseMemeSize;
    
};

#endif