// Autogenerated with StateSmith 0.9.12-alpha.
// Algorithm: Balanced1. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#pragma once
#include <stdint.h>

typedef enum LightSm_EventId
{
    LightSm_EventId_DO = 0, // The `do` event is special. State event handlers do not consume this event (ancestors all get it too) unless a transition occurs.
    LightSm_EventId_KEY_PRESS = 1,
} LightSm_EventId;

enum
{
    LightSm_EventIdCount = 2
};

typedef enum LightSm_StateId
{
    LightSm_StateId_ROOT = 0,
    LightSm_StateId_FAST_REVERSE = 1,
    LightSm_StateId_R1 = 2,
    LightSm_StateId_R2 = 3,
    LightSm_StateId_R3 = 4,
    LightSm_StateId_NORMAL = 5,
    LightSm_StateId_OFF = 6,
    LightSm_StateId_ON1 = 7,
    LightSm_StateId_ON2 = 8,
    LightSm_StateId_ON3 = 9,
} LightSm_StateId;

enum
{
    LightSm_StateIdCount = 10
};


// Generated state machine
// forward declaration
typedef struct LightSm LightSm;

// event handler type
typedef void (*LightSm_Func)(LightSm* sm);

// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void LightSm_ctor(LightSm* sm);

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void LightSm_start(LightSm* sm);

// Dispatches an event to the state machine. Not thread safe.
void LightSm_dispatch_event(LightSm* sm, LightSm_EventId event_id);

// Thread safe.
char const * LightSm_state_id_to_string(LightSm_StateId id);

// Thread safe.
char const * LightSm_event_id_to_string(LightSm_EventId id);

// Generated state machine
struct LightSm
{
    // Used internally by state machine. Feel free to inspect, but don't modify.
    LightSm_StateId state_id;
    
    // Used internally by state machine. Don't modify.
    LightSm_Func ancestor_event_handler;
    
    // Used internally by state machine. Don't modify.
    LightSm_Func current_event_handlers[LightSm_EventIdCount];
    
    // Used internally by state machine. Don't modify.
    LightSm_Func current_state_exit_handler;
};

