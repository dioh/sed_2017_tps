#ifndef _QSS_H_
#define _QSS_H_

#include <string> 

#include "atomic.h"

#define QSS_MODEL_NAME "QSS1"


VTime minposroot(double *coeff);

double to_seconds(const VTime &);


class QSS1 : public Atomic {
  public:
    
    QSS1(const string &name = QSS_MODEL_NAME );
    virtual string className() const {  return QSS_MODEL_NAME ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in;
    Port &out;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output;

    double get_param(const string &);
};

#endif
