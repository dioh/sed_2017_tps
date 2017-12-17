#ifndef _Output_H_
#define _Output_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define OUTPUT "Output"


class Output : public Atomic {
  public:
    
    Output(const string &name = OUTPUT );
    virtual string className() const {  return OUTPUT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_Capital;
    const Port &in_velocityOfMoney;
    Port &out;
    

    double Capital;
    double velocityOfMoney;
    bool isSet_Capital;
    bool isSet_velocityOfMoney;
    //
};

#endif