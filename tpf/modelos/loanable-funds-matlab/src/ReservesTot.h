#ifndef _ReservesTot_H_
#define _ReservesTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define RESERVESTOT "ReservesTot"

class ReservesTot : public Atomic {
  public:
    
    ReservesTot(const string &name = RESERVESTOT );
    virtual string className() const {  return RESERVESTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgReservesPlus;
    Port &out;
    

    double val_chgReservesPlus;
    bool isSet_val_chgReservesPlus;
    
    
};

#endif