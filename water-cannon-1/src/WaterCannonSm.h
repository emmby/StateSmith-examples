// Autogenerated with StateSmith 0.9.6-alpha.
// Algorithm: Balanced1. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#include "WaterCannon.h"
#include "Screens.h"
#pragma once
#include <stdint.h>

typedef enum WaterCannonSm_EventId
{
    WaterCannonSm_EventId_AUTO_PRESS = 0,
    WaterCannonSm_EventId_BACK_PRESS = 1,
    WaterCannonSm_EventId_CAL_PRESS = 2,
    WaterCannonSm_EventId_OK_PRESS = 3,
} WaterCannonSm_EventId;

enum
{
    WaterCannonSm_EventIdCount = 4
};

typedef enum WaterCannonSm_StateId
{
    WaterCannonSm_StateId_ROOT = 0,
    WaterCannonSm_StateId_AUTO_GROUP = 1,
    WaterCannonSm_StateId_AUTO = 2,
    WaterCannonSm_StateId_CALIBRATION_REQUIRED = 3,
    WaterCannonSm_StateId_CAL_GROUP = 4,
    WaterCannonSm_StateId_CANCELLABLE = 5,
    WaterCannonSm_StateId_LOWER = 6,
    WaterCannonSm_StateId_RAISE = 7,
    WaterCannonSm_StateId_CANCELLED = 8,
    WaterCannonSm_StateId_CONFIRMATION = 9,
    WaterCannonSm_StateId_HOME = 10,
    WaterCannonSm_StateId_SPLASH_SCREEN = 11,
} WaterCannonSm_StateId;

enum
{
    WaterCannonSm_StateIdCount = 12
};


// Generated state machine
// forward declaration
typedef struct WaterCannonSm WaterCannonSm;

// event handler type
typedef void (*WaterCannonSm_Func)(WaterCannonSm* sm);

// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void WaterCannonSm_ctor(WaterCannonSm* sm);

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void WaterCannonSm_start(WaterCannonSm* sm);

// Dispatches an event to the state machine. Not thread safe.
void WaterCannonSm_dispatch_event(WaterCannonSm* sm, WaterCannonSm_EventId event_id);

// Thread safe.
char const * WaterCannonSm_state_id_to_string(WaterCannonSm_StateId id);

// Thread safe.
char const * WaterCannonSm_event_id_to_string(WaterCannonSm_EventId id);

// Generated state machine
struct WaterCannonSm
{
    // Used internally by state machine. Feel free to inspect, but don't modify.
    WaterCannonSm_StateId state_id;
    
    // Used internally by state machine. Don't modify.
    WaterCannonSm_Func ancestor_event_handler;
    
    // Used internally by state machine. Don't modify.
    WaterCannonSm_Func current_event_handlers[WaterCannonSm_EventIdCount];
    
    // Used internally by state machine. Don't modify.
    WaterCannonSm_Func current_state_exit_handler;
};

