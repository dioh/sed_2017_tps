[top]
components : teacup-temperature-integrator@QSS1 teacup-temperature-flows-adder@TeacupTemperatureFlowsAdder heat-loss-to-room@HeatLosstoRoomFunction room-temperature@ConstantFunction characteristic-time@ConstantFunction
in : inRoomTemperature inCharacteristicTime
out : output
link : inRoomTemperature value@room-temperature
link : inCharacteristicTime value@characteristic-time
link : out@room-temperature roomTemperature@heat-loss-to-room
link : out@characteristic-time characteristicTime@heat-loss-to-room
link : out@heat-loss-to-room heatLossToRoom@teacup-temperature-flows-adder
link : out@teacup-temperature-flows-adder in@teacup-temperature-integrator
link : out@teacup-temperature-integrator teacupTemperature@heat-loss-to-room 
link : out@teacup-temperature-integrator output

[characteristic-time]
default_value : 10

[room-temperature]
default_value : 70

[teacup-temperature-integrator]
x0 : 80
dQRel : 1e-2
dQMin : 1e-4