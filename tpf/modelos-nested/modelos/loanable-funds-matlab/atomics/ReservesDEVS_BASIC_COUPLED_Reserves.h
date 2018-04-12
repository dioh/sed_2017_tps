#ifndef _ReservesDEVS_BASIC_COUPLED_Reserves_H_
#define _ReservesDEVS_BASIC_COUPLED_Reserves_H_

#include <string> 

#include "atomic.h"

#define RESERVESDEVS_BASIC_COUPLED_RESERVES "ReservesDEVS_BASIC_COUPLED_Reserves"


class ReservesDEVS_BASIC_COUPLED_Reserves : public Atomic {
  public:
    
    ReservesDEVS_BASIC_COUPLED_Reserves(const string &name = RESERVESDEVS_BASIC_COUPLED_RESERVES );
    virtual string className() const {  return RESERVESDEVS_BASIC_COUPLED_RESERVES ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotReserves;
    Port &out_port_Reserves;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_Reserves;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif