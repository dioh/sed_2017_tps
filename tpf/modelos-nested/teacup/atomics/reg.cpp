#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "RoomTemperaturetop.h"
#include "CharacteristicTimetop.h"
#include "HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue.h"
#include "TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<RoomTemperaturetop>(), ROOMTEMPERATURETOP);
	admin.registerAtomic(NewAtomicFunction<CharacteristicTimetop>(), CHARACTERISTICTIMETOP);
	admin.registerAtomic(NewAtomicFunction<HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue>(), HEATLOSSTOROOM_TEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE);
	admin.registerAtomic(NewAtomicFunction<TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue>(), TOTTEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE);
	
}