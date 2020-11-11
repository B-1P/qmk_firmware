#ifndef KEYMAP_USER_H
#define KEYMAP_USER_H

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layers {
	_QWERTY = 0,
	_LOWER,
	_RAISE,
	_ADJUST
};

enum custom_keycodes {
	TOG_DK = SAFE_RANGE,  // Toggle dead keys
  TOG_SCE,  // Toggle switch caps lock and escape
  DO_REISUB,  // Do magic reisub resquence automatically

  U_AE = SAFE_RANGE + 'a',  // Umlaute
  U_UE = SAFE_RANGE + 'u',
  U_OE = SAFE_RANGE + 'o',
  U_SS,
};

extern const uint32_t PROGMEM unicode_map[];
#endif
