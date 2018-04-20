#ifndef _chgWorkersPlus_H_
#define _chgWorkersPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGWORKERSPLUS "chgWorkersPlus"


class chgWorkersPlus : public Atomic {
  public:
    
    chgWorkersPlus(const string &name = CHGWORKERSPLUS );
    virtual string className() const {  return CHGWORKERSPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Wages;
    const Port &ConsW;
    Port &out;
    

    double val_Wages;
    double val_ConsW;
    bool isSet_val_Wages;
    bool isSet_val_ConsW;
    
};

#endif