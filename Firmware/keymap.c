#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE, KC_MPLY,
        KC_VOLD, KC_VOLU,
        KC_NO  
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS] = {
    [0] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_LEFT, KC_RGHT)
    },
};
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) 
    oled_write_P(PSTR("Hacky V1\n"), false);
    return false;
}
#endif
