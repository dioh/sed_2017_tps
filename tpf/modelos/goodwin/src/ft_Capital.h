#ifndef _ft_Capital_H_
#define _ft_Capital_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FT_CAPITAL "ft_Capital"

class ft_Capital : public Atomic {
  public:
    
    ft_Capital(const string &name = FT_CAPITAL );
    virtual string className() const {  return FT_CAPITAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_chgCapital;
    Port &out;
    

    double val_inPlus_chgCapital;
    bool isSet_val_inPlus_chgCapital;
    //
};

#endif