#ifndef _FtotTeacupTemperatureIntegrator_H_
#define _FtotTeacupTemperatureIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTTEACUPTEMPERATUREINTEGRATOR "FtotTeacupTemperatureIntegrator"

class FtotTeacupTemperatureIntegrator : public Atomic {
  public:
    
    FtotTeacupTemperatureIntegrator(const string &name = FTOTTEACUPTEMPERATUREINTEGRATOR );
    virtual string className() const {  return FTOTTEACUPTEMPERATUREINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inMinus_HeatLosstoRoom;
    Port &out;
    

    double val_inMinus_HeatLosstoRoom;
    bool isSet_val_inMinus_HeatLosstoRoom;
    
};

#endif