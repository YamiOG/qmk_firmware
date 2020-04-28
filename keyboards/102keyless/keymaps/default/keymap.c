#include "102keyless.h"

enum{
	ST_OBS, YT_SEARCH,
	
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		ST_OBS, KC_F24, 
		KC_F23, YT_SEARCH, 
		KC_F22, KC_F21)

};
 
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode){
		case ST_OBS:
			if(!record->event.pressed){
				register_code(KC_LGUI);
				unregister_code(KC_LGUI);
				SEND_STRING("OBS");
				register_code(KC_ENTER);
				unregister_code(KC_ENTER);
				return false;
			}
			break;
		case YT_SEARCH:
			if(!record->event.pressed){
				register_code(KC_LGUI);
				unregister_code(KC_LGUI);
				SEND_STRING("https://youtu.be/Jsh7MSpuAi4");
				register_code(KC_ENTER);
				unregister_code(KC_ENTER);
				return false;
			}
			break;
	}
	return true;
}