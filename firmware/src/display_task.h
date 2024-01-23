#pragma once

#if SK_DISPLAY

#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>

// Default color definitions
#define lv_color_navy()         lv_color_make(0,   0,   128) 
#define lv_color_darkGreen()    lv_color_make(0,   128, 0) 
#define lv_color_darkCyan()     lv_color_make(0,   128, 128)
#define lv_color_maroon()       lv_color_make(128, 0,   0) 
#define lv_color_purple()       lv_color_make(128, 0,   128)     
#define lv_color_olive()        lv_color_make(128, 128, 0)     
#define lv_color_lightGrey()    lv_color_make(211, 211, 211) 
#define lv_color_darkGrey()     lv_color_make(128, 128, 128)  
#define lv_color_blue()         lv_color_make(0,   0,   255) 
#define lv_color_green()        lv_color_make(0,   255, 0) 
#define lv_color_cyan()         lv_color_make(0,   255, 255) 
#define lv_color_red()          lv_color_make(255, 0,   0) 
#define lv_color_magenta()      lv_color_make(255, 0,   255) 
#define lv_color_yellow()       lv_color_make(255, 255, 0) 
#define lv_color_orange()       lv_color_make(255, 180, 0) 
#define lv_color_greenYellow()  lv_color_make(180, 255, 0)
#define lv_color_pink()         lv_color_make(255, 192, 203)  
#define lv_color_brown()        lv_color_make(150, 75,  0) 
#define lv_color_gold()         lv_color_make(255, 215, 0) 
#define lv_color_silver()       lv_color_make(192, 192, 192) 
#define lv_color_skyBlue()      lv_color_make(135, 206, 235) 
// #define TFT_VIOLET      0x915C 

#include "logger.h"
#include "proto_gen/smartknob.pb.h"
#include "task.h"

class DisplayTask : public Task<DisplayTask> {
    friend class Task<DisplayTask>; // Allow base Task to invoke protected run()

    public:
        DisplayTask(const uint8_t task_core);
        ~DisplayTask();

        QueueHandle_t getKnobStateQueue();

        void setBrightness(uint16_t brightness);
        void setLogger(Logger* logger);

     protected:
        void run();

    private:
       // TFT_eSPI tft_ = TFT_eSPI();

       /** Full-size sprite used as a framebuffer */
       // TFT_eSprite spr_ = TFT_eSprite(&tft_);

        QueueHandle_t knob_state_queue_;

        PB_SmartKnobState state_;
        SemaphoreHandle_t mutex_;
        uint16_t brightness_;
        Logger* logger_;
        void log(const char* msg);
};

#else

class DisplayTask {};

#endif
