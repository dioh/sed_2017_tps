#ifndef _percentRationalists_H_
#define _percentRationalists_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PERCENTRATIONALISTS "percentRationalists"


class percentRationalists : public Atomic {
  public:
    
    percentRationalists(const string &name = PERCENTRATIONALISTS );
    virtual string className() const {  return PERCENTRATIONALISTS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &RationalSupporters;
    const Port &RationalSupporters;
    const Port &Degenerates;
    Port &out;
    

    double val_RationalSupporters;
    double val_RationalSupporters;
    double val_Degenerates;
    bool isSet_val_RationalSupporters;
    bool isSet_val_RationalSupporters;
    bool isSet_val_Degenerates;
    
};

#endif