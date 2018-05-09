#include "pmodeladm.h"
#include "register.h"
#include "tuple_to_real.h"
#include "CharacteristicTimetop.h"
#include "RoomTemperaturetop.h"
#include "HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue.h"
#include "TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue.h"
#include "TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	//admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<tuple2real>(), TUPLE2REAL);
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<CharacteristicTimetop>(), CHARACTERISTICTIMETOP);
	admin.registerAtomic(NewAtomicFunction<RoomTemperaturetop>(), ROOMTEMPERATURETOP);
	admin.registerAtomic(NewAtomicFunction<HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue>(), HEATLOSSTOROOM_TEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE);
	admin.registerAtomic(NewAtomicFunction<TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue>(), TOTTEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE);
	admin.registerAtomic(NewAtomicFunction<TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue>(), TEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE);
	
}