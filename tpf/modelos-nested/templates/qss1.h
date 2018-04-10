#ifndef _QSS_H_
#define _QSS_H_

#include <string> 

#include "atomic.h"

#define {{name_full_upper}} "{{name_full}}"


VTime minposroot(double *coeff);

double to_seconds(const VTime &);


class {{name_full}} : public Atomic {
  public:
    
    {{name_full}}(const string &name = {{name_full_upper}} );
    virtual string className() const {  return {{name_full_upper}} ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_Tot{{name}};
    Port &out_port_{{name}};

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output;

    double get_param(const string &);
};

#endif
