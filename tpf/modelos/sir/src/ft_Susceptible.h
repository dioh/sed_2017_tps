#ifndef _ft_Susceptible_H_
#define _ft_Susceptible_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FT_SUSCEPTIBLE "ft_Susceptible"

class ft_Susceptible : public Atomic {
  public:
    
    ft_Susceptible(const string &name = FT_SUSCEPTIBLE );
    virtual string className() const {  return FT_SUSCEPTIBLE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inMinus_Succumbing;
    Port &out;
    

    double val_inMinus_Succumbing;
    bool isSet_val_inMinus_Succumbing;
    //
};

#endif