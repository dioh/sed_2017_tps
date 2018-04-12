#ifndef _PreyDEVS_BASIC_COUPLED_Prey_H_
#define _PreyDEVS_BASIC_COUPLED_Prey_H_

#include <string> 

#include "atomic.h"

#define PREYDEVS_BASIC_COUPLED_PREY "PreyDEVS_BASIC_COUPLED_Prey"


class PreyDEVS_BASIC_COUPLED_Prey : public Atomic {
  public:
    
    PreyDEVS_BASIC_COUPLED_Prey(const string &name = PREYDEVS_BASIC_COUPLED_PREY );
    virtual string className() const {  return PREYDEVS_BASIC_COUPLED_PREY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotPrey;
    Port &out_port_Prey;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_Prey;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif