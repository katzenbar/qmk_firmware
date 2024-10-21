// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "print.h"

enum layer_names {
    _BASE,
    _LTOG,
    _RTOG,
    _ALL_TOG,
    _UNLOCKED,
    _UNLOCKED_LTOG,
    _UNLOCKED_RTOG,
    _ARMED
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO
    ),
    [_LTOG] = LAYOUT(
        KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT,
        QK_REBOOT
    ),
    [_RTOG] = LAYOUT(
        KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT
    ),
    [_ALL_TOG] = LAYOUT(
        KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT
    ),
    [_UNLOCKED] = LAYOUT(
        KC_NO,
        KC_ESCAPE,
        KC_HOME,
        KC_BACKSPACE
    ),
    [_UNLOCKED_LTOG] = LAYOUT(
        KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT
    ),
    [_UNLOCKED_RTOG] = LAYOUT(
        KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT
    ),
    [_ARMED] = LAYOUT(
        KC_ENTER,         // launch
        KC_TRANSPARENT,   // button 1
        KC_TRANSPARENT,   // button 2
        KC_TRANSPARENT    // button 3
    )
};

#define DIP_SWITCH_LTOG (1UL << 0)
#define DIP_SWITCH_RTOG (1UL << 1)
#define DIP_SWITCH_KEY (1UL << 2)

#define LED_LTOG GP8
#define LED_RTOG GP9
#define LED_BUTTON_LG GP26
#define LED_BUTTON_SM GP27

void keyboard_post_init_user(void) {
    gpio_set_pin_output(LED_LTOG);
    gpio_set_pin_output(LED_RTOG);
    gpio_set_pin_output(LED_BUTTON_LG);
    gpio_set_pin_output(LED_BUTTON_SM);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    dprintf("process_record_user: %u\n", keycode);
    return true;
}

bool dip_switch_update_mask_user(uint32_t state) {
    if (state & DIP_SWITCH_KEY && state & DIP_SWITCH_LTOG && state & DIP_SWITCH_RTOG) {
        layer_on(_ARMED);
        gpio_write_pin_high(LED_BUTTON_LG);
    } else {
        layer_off(_ARMED);
        gpio_write_pin_low(LED_BUTTON_LG);
    }

    if (state & DIP_SWITCH_KEY && state & DIP_SWITCH_LTOG) {
        layer_on(_UNLOCKED_LTOG);
    } else {
        layer_off(_UNLOCKED_LTOG);
    }

    if (state & DIP_SWITCH_KEY && state & DIP_SWITCH_RTOG) {
        layer_on(_UNLOCKED_RTOG);
    } else {
        layer_off(_UNLOCKED_RTOG);
    }

    if (state & DIP_SWITCH_KEY) {
        layer_on(_UNLOCKED);
    } else {
        layer_off(_UNLOCKED);
    }

    if (state & DIP_SWITCH_LTOG) {
        layer_on(_LTOG);
    } else {
        layer_off(_LTOG);
    }

    if (state & DIP_SWITCH_RTOG) {
        layer_on(_RTOG);
    } else {
        layer_off(_RTOG);
    }

    if (state & DIP_SWITCH_KEY) {
        gpio_write_pin_high(LED_BUTTON_SM);
        gpio_write_pin_high(LED_LTOG);
        gpio_write_pin_high(LED_RTOG);
    } else {
        gpio_write_pin_low(LED_BUTTON_SM);
        gpio_write_pin_low(LED_LTOG);
        gpio_write_pin_low(LED_RTOG);
    }

    return true;
}
