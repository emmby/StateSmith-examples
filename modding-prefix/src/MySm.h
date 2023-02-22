// Autogenerated with StateSmith
#pragma once
#include <stdint.h>

enum MySm_EventId
{
    MySm_EventId_EV1 = 0,
    MySm_EventId_EV2 = 1,
    MySm_EventId_EV3 = 2,
};

enum
{
    MySm_EventIdCount = 3
};

enum MySm_StateId
{
    MySm_StateId_ROOT = 0,
    MySm_StateId_ORDER_MENU = 1,
    MySm_StateId_OM__BEVERAGE = 2,
    MySm_StateId_OM__BEV__NONE = 3,
    MySm_StateId_OM__BEV__TEA = 4,
    MySm_StateId_OM__BEV__WATER = 5,
    MySm_StateId_OM__DESERT = 6,
    MySm_StateId_DSRT__CAKE = 7,
    MySm_StateId_OM__FOOD = 8,
    MySm_StateId_OM__FOOD__NONE = 9,
    MySm_StateId_OM__FOOD__POTATO = 10,
    MySm_StateId_OM__FOOD__SUSHI = 11,
    MySm_StateId_WAITING = 12,
};

enum
{
    MySm_StateIdCount = 13
};

typedef struct MySm MySm;
typedef void (*MySm_Func)(MySm* sm);

struct MySm
{
    // Used internally by state machine. Feel free to inspect, but don't modify.
    enum MySm_StateId state_id;
    
    // Used internally by state machine. Don't modify.
    MySm_Func ancestor_event_handler;
    
    // Used internally by state machine. Don't modify.
    MySm_Func current_event_handlers[MySm_EventIdCount];
    
    // Used internally by state machine. Don't modify.
    MySm_Func current_state_exit_handler;
};

// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void MySm_ctor(MySm* self);

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void MySm_start(MySm* self);

// Dispatches an event to the state machine. Not thread safe.
void MySm_dispatch_event(MySm* self, enum MySm_EventId event_id);

// Converts a state id to a string. Thread safe.
const char* MySm_state_id_to_string(const enum MySm_StateId id);
