// ----------------------------------------------------------------------------
// MixingValveController.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef MIXING_VALVE_CONTROLLER_H
#define MIXING_VALVE_CONTROLLER_H
#include <Flash.h>
#include <EEPROM.h>
#include <Streaming.h>
#include <ArduinoJson.h>
#include <JsonSanitizer.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <MemoryFree.h>
#include <ConstantVariable.h>
#include <SavedVariable.h>
#include <Functor.h>
#include <IndexedContainer.h>
#include <FunctorCallbacks.h>

#include <EventController.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>
#include <PowerSwitchController.h>

#include "MixingValveController/Constants.h"


class MixingValveController : public PowerSwitchController
{
public:
  MixingValveController();
  virtual void setup();

  int mix(Array<size_t,mixing_valve_controller::constants::VALVE_COUNT_MAX> ratio);

private:
  modular_server::Property properties_[mixing_valve_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[mixing_valve_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[mixing_valve_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[mixing_valve_controller::constants::CALLBACK_COUNT_MAX];

  IndexedContainer<mixing_valve_controller::constants::MixInfo,
                   mixing_valve_controller::constants::MIX_COUNT_MAX> indexed_mix_info_;

  // Handlers
  void mixHandler();
  void mixHandler(int index);

};

#endif