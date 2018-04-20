#ifndef _piR_H_
#define _piR_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PIR "piR"


class piR : public Atomic {
  public:
    
    piR(const string &name = PIR );
    virtual string className() const {  return PIR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &ProfitNet;
    const Port &Capital;
    Port &out;
    

    double val_ProfitNet;
    double val_Capital;
    bool isSet_val_ProfitNet;
    bool isSet_val_Capital;
    
};

#endif