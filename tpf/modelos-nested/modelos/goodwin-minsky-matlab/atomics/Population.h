#ifndef _Population_H_
#define _Population_H_

#include <string> 

#include "atomic.h"

#define POPULATION "Population"


class Population : public Atomic {
  public:
    
    Population(const string &name = POPULATION );
    virtual string className() const {  return POPULATION ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotPopulation;
    Port &out_port_Population;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_Population;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif