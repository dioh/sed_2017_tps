#ifndef _chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW_H_
#define _chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGWORKERSNW_WORKERSNWDEVS_BASIC_COUPLED_WORKERSNW "chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW"


class chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW : public Atomic {
  public:
    
    chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW(const string &name = CHGWORKERSNW_WORKERSNWDEVS_BASIC_COUPLED_WORKERSNW );
    virtual string className() const {  return CHGWORKERSNW_WORKERSNWDEVS_BASIC_COUPLED_WORKERSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_WagesC;
    const Port &in_port_WagesI;
    const Port &in_port_ConsW;
    Port &out_port_chgWorkersNW_WorkersNW;
    
    double WagesC;
    double WagesI;
    double ConsW;
    bool isSet_WagesC;
    bool isSet_WagesI;
    bool isSet_ConsW;
};

#endif