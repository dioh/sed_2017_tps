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
    const Port &YCValue;
    const Port &YIValue;
    Port &out;
    

    double val_YCValue;
    double val_YIValue;
    bool isSet_val_YCValue;
    bool isSet_val_YIValue;
    
};

#endif