#ifndef _trueMemes_H_
#define _trueMemes_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define TRUEMEMES "trueMemes"


class trueMemes : public Atomic {
  public:
    
    trueMemes(const string &name = TRUEMEMES );
    virtual string className() const {  return TRUEMEMES ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &rationalistsInfluence;
    const Port &constantTrueMemeSize;
    Port &out;
    

    double val_rationalistsInfluence;
    double val_constantTrueMemeSize;
    bool isSet_val_rationalistsInfluence;
    bool isSet_val_constantTrueMemeSize;
    
};

#endif