#ifndef _Cte_H_
#define _Cte_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CTE "Cte"


class Cte : public Atomic {
  public:
    
    Cte(const string &name = CTE );
    virtual string className() const {  return CTE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inValue;
    Port &out;

    double value;
};

#endif
