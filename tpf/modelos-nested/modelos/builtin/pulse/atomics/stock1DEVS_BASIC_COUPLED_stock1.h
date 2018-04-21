#ifndef _stock1DEVS_BASIC_COUPLED_stock1_H_
#define _stock1DEVS_BASIC_COUPLED_stock1_H_

#include <string> 

#include "atomic.h"

#define STOCK1DEVS_BASIC_COUPLED_STOCK1 "stock1DEVS_BASIC_COUPLED_stock1"


class stock1DEVS_BASIC_COUPLED_stock1 : public Atomic {
  public:
    
    stock1DEVS_BASIC_COUPLED_stock1(const string &name = STOCK1DEVS_BASIC_COUPLED_STOCK1 );
    virtual string className() const {  return STOCK1DEVS_BASIC_COUPLED_STOCK1 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_Totstock1;
    Port &out_port_stock1;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_stock1;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif