# MixingValveController

Authors:

    Peter Polidoro <polidorop@janelia.hhmi.org>

License:

    BSD

## Ancestors

[ModularServer](https://github.com/janelia-arduino/ModularServer)

[ModularDeviceBase](https://github.com/janelia-arduino/ModularDeviceBase)

[PowerSwitchController](https://github.com/janelia-arduino/PowerSwitchController)

## Clients

## Devices

[modular_device_base](https://github.com/janelia-modular-devices/modular_device_base.git)

[power_switch_controller](https://github.com/janelia-modular-devices/power_switch_controller.git)

## API NAMES

```json
{
  "id": "getApi",
  "result": {
    "firmware": [
      "MixingValveController"
    ],
    "verbosity": "NAMES",
    "functions": [
      "getMixTiming",
      "startMixing"
    ],
    "parameters": [
      "ratio"
    ],
    "properties": [
      "valveCount",
      "mixingVolume",
      "flowRate",
      "mixResolution",
      "mixDuration",
      "valveSwitchDuration",
      "valveOpenUnitDurationMin"
    ],
    "callbacks": [
      "stopMixing"
    ]
  }
}
```

## API GENERAL

[API GENERAL](./api/)

## More Detailed Modular Device Information

[modular-devices](https://github.com/janelia-modular-devices/modular-devices)

## Install Library Dependencies

[arduino-libraries](https://github.com/janelia-arduino/arduino-libraries)
