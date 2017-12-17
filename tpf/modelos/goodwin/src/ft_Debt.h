#ifndef _ft_Debt_H_
#define _ft_Debt_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FT_DEBT "ft_Debt"

class ft_Debt : public Atomic {
  public:
    
    ft_Debt(const string &name = FT_DEBT );
    virtual string className() const {  return FT_DEBT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_chgDebt;
    Port &out;
    

    double val_inPlus_chgDebt;
    bool isSet_val_inPlus_chgDebt;
    //
};

#endif