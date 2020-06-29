OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # ENables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB light
WPM_ENABLE = no
MOUSEKEY_ENABLE = no      # Mouse keys
<<<<<<< HEAD
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = WS2812  # Enable per-key coordinate based RGB effects. Do not enable with RGBlight
RGB_MATRIX_KEYPRESSES = no  # Enable reactive per-key effects.
SPLIT_TRANSPORT = mirror    # For split RGB Matrix support
=======
>>>>>>> my_keymap
# CONSOLE_ENABLE = yes 
SRC += oled.c encoder.c macros.c settings.c

# uncomment to the line to customize the setting
#define ENCODER_DIRECTION_FLIP # Switch encoder’s directions
#define ENCODER_RESOLUTION 4 # Tune encoder resolution
