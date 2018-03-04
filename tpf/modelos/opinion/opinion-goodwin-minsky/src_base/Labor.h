#ifndef _Labor_H_
#define _Labor_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define LABOR "Labor"


class Labor : public Atomic {
  public:
    
    Labor(const string &name = LABOR );
    virtual string className() const {  return LABOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Output;
    const Port &LaborProductivity;
    Port &out;
    

    double val_Output;
    double val_LaborProductivity;
    bool isSet_val_Output;
    bool isSet_val_LaborProductivity;
    
};

#endif