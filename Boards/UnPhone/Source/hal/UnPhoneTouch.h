#pragma once

#include "hal/Touch.h"
#include "TactilityCore.h"
#include "esp_lcd_panel_io_interface.h"
#include "esp_lcd_touch.h"

class UnPhoneTouch : public tt::hal::Touch {

private:

    static UnPhoneTouch* instance;

    esp_lcd_panel_io_handle_t _Nullable ioHandle = nullptr;
    esp_lcd_touch_handle_t _Nullable touchHandle = nullptr;
    lv_indev_t* _Nullable deviceHandle = nullptr;
    void cleanup();

public:

    bool start(lv_display_t* display) override;
    bool stop() override;
    lv_indev_t* _Nullable getLvglIndev() override { return deviceHandle; }

    bool getVBat(float& outputVbat);

    /** Used for accessing getVBat() in Power driver */
    static UnPhoneTouch* getInstance() { return instance; }
};
