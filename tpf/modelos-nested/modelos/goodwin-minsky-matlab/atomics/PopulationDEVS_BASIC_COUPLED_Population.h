#ifndef _PopulationDEVS_BASIC_COUPLED_Population_H_
#define _PopulationDEVS_BASIC_COUPLED_Population_H_

#include <string> 

#include "atomic.h"

#define POPULATIONDEVS_BASIC_COUPLED_POPULATION "PopulationDEVS_BASIC_COUPLED_Population"


class PopulationDEVS_BASIC_COUPLED_Population : public Atomic {
  public:
    
    PopulationDEVS_BASIC_COUPLED_Population(const string &name = POPULATIONDEVS_BASIC_COUPLED_POPULATION );
    virtual string className() const {  return POPULATIONDEVS_BASIC_COUPLED_POPULATION ;}
  
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