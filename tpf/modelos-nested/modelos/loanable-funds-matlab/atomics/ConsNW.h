#ifndef _ConsNW_H_
#define _ConsNW_H_

#include <string> 

#include "atomic.h"

#define CONSNW "ConsNW"


class ConsNW : public Atomic {
  public:
    
    ConsNW(const string &name = CONSNW );
    virtual string className() const {  return CONSNW ;}
  
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