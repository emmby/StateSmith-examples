#include "WaterCannon.h"
#include "WaterCannonSm.h"
#include "DebugLog.h"

static WaterCannonSm sm;
static bool is_calibrated = false;

void WaterCannon_init()
{
    // normally not needed, but required for unit tests as they run multiple times.
    // sometimes helpful to wrap all vars in a struct and then memset to zero instead of having a bunch of loose vars.
    is_calibrated = false;

    WaterCannonSm_ctor(&sm);
    WaterCannonSm_start(&sm);
}

void WaterCannon_handle_event(int event)
{
    // TODO should verify that event is valid
    WaterCannonSm_dispatch_event(&sm, event);
}

bool WaterCannon_is_calibrated(void)
{
    return is_calibrated;
}

void WaterCannon_capture_lowered_position(void)
{
    // do stuff... would normally store height in a variable
    is_calibrated = false;
    DebugLog_info("Calibration started...");
}

void WaterCannon_capture_raised_position(void)
{
    // do stuff... would normally store height in a variable
    is_calibrated = true;
    DebugLog_info("Calibration finished!");
}

int WaterCannon_get_current_state(void)
{
    return sm.state_id;
}