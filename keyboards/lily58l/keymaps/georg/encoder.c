#include QMK_KEYBOARD_H
#include "keymap.h"

#ifdef RGBLIGHT_ENABLE 
#  define STEP_HUE RGBLIGHT_HUE_STEP
#  define STEP_VAL RGBLIGHT_VAL_STEP
#elif RGB_MATRIX_ENABLE
#  define STEP_HUE RGB_MATRIX_HUE_STEP
#  define STEP_VAL RGB_MATRIX_VAL_STEP
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    HSV hsv;
    bool shifted = get_mods() & MOD_MASK_SHIFT;  // precision steps
#endif
    switch (get_highest_layer(layer_state)) {
        case _RAISE:  // brightness control
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
            hsv = rgblight_get_hsv();
            if (get_mods() & MOD_MASK_CTRL) {
                hsv.h = hsv.h + (clockwise ? 1 : -1) * (shifted ? 1 : STEP_HUE);
            } else {
                int16_t v = hsv.v + (clockwise ? 1 : -1) * (shifted ? 1 : STEP_VAL);
                if (v <= 0) {
                    rgblight_disable();
                    v = 0;
                } else if (!rgblight_is_enabled())
                    rgblight_enable();
                hsv.v = v;
            } 
            rgblight_sethsv(hsv.h, hsv.s, hsv.v);
            break;
#endif
        case _LOWER:
            tap_code(clockwise ? KC_BRIU : KC_BRID);
            break;
        default:  // Volume control
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
}
    }
#endif