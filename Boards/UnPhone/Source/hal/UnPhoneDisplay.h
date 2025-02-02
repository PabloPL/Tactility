#pragma once

#include <esp_lcd_types.h>
#include "lvgl.h"
#include "hal/Display.h"

extern lv_disp_t* displayHandle;

class UnPhoneDisplay : public tt::hal::Display {

private:

    lv_display_t* displayHandle = nullptr;

public:

    bool start() override;

    bool stop() override;

    tt::hal::Touch* _Nullable createTouch() override;

    lv_display_t* _Nullable getLvglDisplay() const override { return displayHandle; }
};

tt::hal::Display* createDisplay();
