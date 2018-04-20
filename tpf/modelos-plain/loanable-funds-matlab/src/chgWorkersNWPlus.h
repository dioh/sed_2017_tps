#ifndef _chgWorkersNWPlus_H_
#define _chgWorkersNWPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGWORKERSNWPLUS "chgWorkersNWPlus"


class chgWorkersNWPlus : public Atomic {
  public:
    
    chgWorkersNWPlus(const string &name = CHGWORKERSNWPLUS );
    virtual string className() const {  return CHGWORKERSNWPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &WagesC;
    const Port &WagesI;
    const Port &ConsW;
    Port &out;
    

    double val_WagesC;
    double val_WagesI;
    double val_ConsW;
    bool isSet_val_WagesC;
    bool isSet_val_WagesI;
    bool isSet_val_ConsW;
    
};

#endif