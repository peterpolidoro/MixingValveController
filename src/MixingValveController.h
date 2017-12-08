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
#include <Watchdog.h>

#include <SPI.h>
#include <TLE72X.h>
#include <EventController.h>

#include <ModularClient.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>
#include <PowerSwitchController.h>

#include "MixingValveController/Constants.h"


class MixingValveController : public PowerSwitchController
{
public:
  MixingValveController();
  virtual void setup();

  typedef Array<size_t,mixing_valve_controller::constants::VALVE_COUNT_MAX> Ratio;

  Ratio startMixing(Ratio ratio);
  void stopMixing();

  long getMixingVolumeFillDuration();
  long getValveOpenUnitDuration();

  long setMixDurationToFactorOfDuration(const long duration);

protected:
  virtual bool finishMix();

private:
  modular_server::Property properties_[mixing_valve_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[mixing_valve_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[mixing_valve_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[mixing_valve_controller::constants::CALLBACK_COUNT_MAX];

  mixing_valve_controller::constants::MixInfo mix_info_;

  // Mix Timing
  long mixing_volume_fill_duration_;
  long valve_open_unit_duration_;
  long mix_duration_min_;
  long mix_duration_max_;

  Ratio normalizeRatio(Ratio ratio);
  size_t ratioSum(Ratio ratio);
  size_t ratioMaxIndex(Ratio ratio);
  long constrainMixDuration(const long mix_duration,
                            const long mix_duration_min,
                            const long mix_duration_max);

  // Handlers
  void setValveCountHandler();
  void updateMixPropertiesHandler();
  void getMixInfoHandler();
  void startMixingHandler();
  void setMixDurationToFactorOfDurationHandler();
  void stopMixingHandler(modular_server::Interrupt * interrupt_ptr);
  void mixHandler(int arg);

};

#endif
