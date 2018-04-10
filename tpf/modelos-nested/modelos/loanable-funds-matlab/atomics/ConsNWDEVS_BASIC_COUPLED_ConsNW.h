#ifndef _ConsNWDEVS_BASIC_COUPLED_ConsNW_H_
#define _ConsNWDEVS_BASIC_COUPLED_ConsNW_H_

#include <string> 

#include "atomic.h"

#define CONSNWDEVS_BASIC_COUPLED_CONSNW "ConsNWDEVS_BASIC_COUPLED_ConsNW"


class ConsNWDEVS_BASIC_COUPLED_ConsNW : public Atomic {
  public:
    
    ConsNWDEVS_BASIC_COUPLED_ConsNW(const string &name = CONSNWDEVS_BASIC_COUPLED_CONSNW );
    virtual string className() const {  return CONSNWDEVS_BASIC_COUPLED_CONSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotConsNW;
    Port &out_port_ConsNW;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_ConsNW;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif