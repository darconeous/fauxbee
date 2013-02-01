
#ifndef __FAUXBEE_PIN_H__
#define __FAUXBEE_PIN_H__ 1

#include <stdint.h>

enum {
	PIN_INPUT = (1<<0),
	PIN_OUTPUT = (1<<1),
	PIN_ADC = (1<<2),
	PIN_PWM = (1<<3),

};

void pin_init();

uint8_t pin_count();

uint8_t pin_features_get(int8_t i);

const char* pin_name_get(uint8_t i);

const char* pin_localname_get(uint8_t i);
void pin_localname_set(uint8_t i, const char* localname);

uint8_t pin_mode_get(int8_t i);
void pin_mode_set(int8_t i, uint8_t mode);

uint8_t pin_state_get(uint8_t i);
void pin_state_set(uint8_t i, uint8_t state);
uint8_t pin_state_toggle(uint8_t i);

#endif
