#include "action_layer.h"
#include "keymap_common.h"
#include "led.h"
#include "timer.h"

#define KEYMAP_TKG( \
    K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I, K0J, K0K, K0L, K0M, K0N, \
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M, K1N, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L,      K2N, \
    K3A,      K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L,      K3N, \
    K4A, K4B, K4C,           K4F,                     K4K, K4L, K4M, K4N  \
) { \
    { KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D, KC_##K0E, KC_##K0F, KC_##K0G, KC_##K0H, KC_##K0I, KC_##K0J, KC_##K0K, KC_##K0L, KC_##K0M, KC_##K0N }, \
    { KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_##K1E, KC_##K1F, KC_##K1G, KC_##K1H, KC_##K1I, KC_##K1J, KC_##K1K, KC_##K1L, KC_##K1M, KC_##K1N }, \
    { KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D, KC_##K2E, KC_##K2F, KC_##K2G, KC_##K2H, KC_##K2I, KC_##K2J, KC_##K2K, KC_##K2L, KC_NO,    KC_##K2N }, \
    { KC_##K3A, KC_NO,    KC_##K3C, KC_##K3D, KC_##K3E, KC_##K3F, KC_##K3G, KC_##K3H, KC_##K3I, KC_##K3J, KC_##K3K, KC_##K3L, KC_NO,    KC_##K3N }, \
    { KC_##K4A, KC_##K4B, KC_##K4C, KC_NO,    KC_NO,    KC_##K4F, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_##K4K, KC_##K4L, KC_##K4M, KC_##K4N }  \
}

#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    [0] = KEYMAP_TKG(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        FN5, A,   S,   D,   F,   G,   H,   J,   K,   L,   FN6, QUOT,     ENT,  \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT, \
        LCTL,LALT,LGUI,             SPC,                    FN5, LGUI,FN7, RCTL),
    [5] = KEYMAP_TKG(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,  \
        TRNS,HOME,UP,  END, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN23,FN24,TRNS, \
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,LEFT,DOWN,UP,  RGHT,FN21,FN22,     TRNS, \
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,PGDN,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,CAPS,FN7,TRNS),
    [6] = KEYMAP_TKG(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,WH_D,MS_U,WH_U,TRNS,TRNS,WSCH,WBAK,WFWD,WHOM,TRNS,TRNS,TRNS,TRNS, \
        TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,BTN1,BTN2,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,     VOLD,MUTE,VOLU,MRWD,MPLY,MSTP,MFFD,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,FN7,TRNS),
    [7] = KEYMAP_TKG(
        TRNS,FN31,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN30,TRNS,TRNS,TRNS, \
        TRNS,TRNS,FN13,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN14,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN15,TRNS,TRNS,     TRNS, \

        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN16,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,FN7,TRNS),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case 21:
            return (record->event.pressed ?
                    MACRO( I(10), D(LCTRL), T(N), U(LCTRL), T(P), END ) :
                    MACRO_NONE );
        case 22:
            return (record->event.pressed ?
                    MACRO( I(10), D(LCTRL), T(N), U(LCTRL), T(N), END ) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}

#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t PROGMEM fn_actions[] = {
#endif
    [5] = ACTION_LAYER_MOMENTARY(5),
    [6] = ACTION_LAYER_TAP_KEY(6, KC_SCOLON),
    [7] = ACTION_LAYER_MOMENTARY(7),
    // [13] = ACTION_LAYER_TOGGLE(3),                            // window layer
    // [14] = ACTION_LAYER_TOGGLE(4),                            // OSX layer
    // [15] = ACTION_LAYER_TOGGLE(5),                            // Linux layer
    [16] = ACTION_LAYER_TOGGLE(6),                            // mouse layer
    [13] = ACTION_FUNCTION(3),                            // window layer
    [14] = ACTION_FUNCTION(4),                            // OSX layer
    [15] = ACTION_FUNCTION(5),                            // Linux layer
    [21] = ACTION_MACRO(21),                                  // tmux  pre
    [22] = ACTION_MACRO(22),                                  // tmux next
    //[23] = ACTION_MODS_KEY(MOD_LCTL, KC_PGUP),                //  tab  pre in linux
    //[24] = ACTION_MODS_KEY(MOD_LCTL, KC_PGDOWN),              //  tab next in linux
    [23] = ACTION_FUNCTION(23),                                  // tmux  pre
    [24] = ACTION_FUNCTION(24),                                  // tmux next
    [30] = ACTION_BACKLIGHT_STEP(),
    [31] = ACTION_BACKLIGHT_TOGGLE()
};

bool my_led_status = 0;
uint16_t my_led_timer;
enum {
    LINUX,
    MACOS,
    WINDOWS,
};
int keyboard_env = LINUX;

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case 5:
            keyboard_env = LINUX;
            break;
        case 4:
            keyboard_env = MACOS;
            break;
        case 3:
            keyboard_env = WINDOWS;
            break;
        case 23:
            if (keyboard_env == LINUX) {
                if (record->event.pressed) {
                    add_mods(MOD_BIT(KC_LCTRL));
                    add_key(KC_PGUP);
                    send_keyboard_report();
                } else {
                    del_mods(MOD_BIT(KC_LCTRL));
                    del_key(KC_PGUP);
                    send_keyboard_report();
                }
            } else if (keyboard_env == MACOS) {
                if (record->event.pressed) {
                    add_mods(MOD_BIT(KC_LSHIFT));
                    add_mods(MOD_BIT(KC_LGUI));
                    add_key(KC_LBRACKET);
                    send_keyboard_report();
                } else {
                    del_mods(MOD_BIT(KC_LSHIFT));
                    del_mods(MOD_BIT(KC_LGUI));
                    del_key(KC_LBRACKET);
                    send_keyboard_report();
                }
            }
            break;
        case 24:
            if (keyboard_env == LINUX) {
                if (record->event.pressed) {
                    add_mods(MOD_BIT(KC_LCTRL));
                    add_key(KC_PGDOWN);
                    send_keyboard_report();
                } else {
                    del_mods(MOD_BIT(KC_LCTRL));
                    del_key(KC_PGDOWN);
                    send_keyboard_report();
                }
            } else if (keyboard_env == MACOS) {
                if (record->event.pressed) {
                    add_mods(MOD_BIT(KC_LSHIFT));
                    add_mods(MOD_BIT(KC_LGUI));
                    add_key(KC_RBRACKET);
                    send_keyboard_report();
                } else {
                    del_mods(MOD_BIT(KC_LSHIFT));
                    del_mods(MOD_BIT(KC_LGUI));
                    del_key(KC_RBRACKET);
                    send_keyboard_report();
                }
            }
            break;
    }
    //if (record->event.pressed) {
    //    add_key(KC_A);
    //    send_keyboard_report();
    //} else {
    //    del_key(KC_A);
    //    send_keyboard_report();
    //}
}

void hook_layer_change(uint32_t layer_state) {
    if (!layer_state) {
        led_set(host_keyboard_leds() & ~(1<<USB_LED_CAPS_LOCK));
    } else {
        my_led_timer = timer_read();
        my_led_status += 10;
        led_set(host_keyboard_leds() | (1<<USB_LED_CAPS_LOCK));
    }
}

void hook_matrix_change(keyevent_t event) {
    // only flash LED for key press events, not key release events.
    if (event.pressed)
    {
    }
}

void hook_keyboard_loop(void) {
}

