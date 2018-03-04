#ifndef _DegeneratesTot_H_
#define _DegeneratesTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define DEGENERATESTOT "DegeneratesTot"

class DegeneratesTot : public Atomic {
  public:
    
    DegeneratesTot(const string &name = DEGENERATESTOT );
    virtual string className() const {  return DEGENERATESTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &neutralistsToDegeneratesPlus;
    
    const Port &outDegeneratesRightMinus;
    
    const Port &outDegeneratesLeftMinus;
    Port &out;
    

    double val_neutralistsToDegeneratesPlus;
    double val_outDegeneratesRightMinus;
    double val_outDegeneratesLeftMinus;
    bool isSet_val_neutralistsToDegeneratesPlus;
    
    bool isSet_val_outDegeneratesRightMinus;
    bool isSet_val_outDegeneratesLeftMinus;
    
};

#endif