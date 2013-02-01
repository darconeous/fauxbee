

#include "pin.h"
#include <contiki.h>

#if __AVR__
#include <avr/io.h>
#endif

struct pin_definition_s {
	char name[6];
	uint8_t features;
#if __AVR__
	struct {
		volatile uint8_t *pin_ptr;
		volatile uint8_t *port_ptr;
		volatile uint8_t *ddr_ptr;
		uint8_t mask;
		uint8_t adc_mask;
	} avr;
#endif
};

struct pin_config_s {
	char localname[12];
	uint8_t mode;
	uint16_t last_adc;
};

const static struct pin_definition_s pin_def[] = {

#define AVR_PIN_DEF(port, pin) { .name = "P" ##port ##pin, .features = PIN_INPUT|PIN_OUTPUT, .avr = { &PIN # port, &PORT # port, &DDR # port, pin } }

#ifdef PORTA
	AVR_PIN_DEF(A,0),
	AVR_PIN_DEF(A,1),
	AVR_PIN_DEF(A,2),
	AVR_PIN_DEF(A,3),
	AVR_PIN_DEF(A,4),
	AVR_PIN_DEF(A,5),
	AVR_PIN_DEF(A,6),
	AVR_PIN_DEF(A,7),
#endif

#ifdef PORTB
	AVR_PIN_DEF(B,0),
	AVR_PIN_DEF(B,1),
	AVR_PIN_DEF(B,2),
	AVR_PIN_DEF(B,3),
	AVR_PIN_DEF(B,4),
	AVR_PIN_DEF(B,5),
	AVR_PIN_DEF(B,6),
	AVR_PIN_DEF(B,7),
#endif

#ifdef PORTC
	AVR_PIN_DEF(C,0),
	AVR_PIN_DEF(C,1),
	AVR_PIN_DEF(C,2),
	AVR_PIN_DEF(C,3),
	AVR_PIN_DEF(C,4),
	AVR_PIN_DEF(C,5),
	AVR_PIN_DEF(C,6),
	AVR_PIN_DEF(C,7),
#endif

#ifdef PORTD
	AVR_PIN_DEF(D,0),
	AVR_PIN_DEF(D,1),
	AVR_PIN_DEF(D,2),
	AVR_PIN_DEF(D,3),
	AVR_PIN_DEF(D,4),
	AVR_PIN_DEF(D,5),
	AVR_PIN_DEF(D,6),
	AVR_PIN_DEF(D,7),
#endif

#ifdef PORTE
	AVR_PIN_DEF(E,0),
	AVR_PIN_DEF(E,1),
	AVR_PIN_DEF(E,2),
	AVR_PIN_DEF(E,3),
	AVR_PIN_DEF(E,4),
	AVR_PIN_DEF(E,5),
	AVR_PIN_DEF(E,6),
	AVR_PIN_DEF(E,7),
#endif

#ifdef PORTF
	AVR_PIN_DEF(F,0),
	AVR_PIN_DEF(F,1),
	AVR_PIN_DEF(F,2),
	AVR_PIN_DEF(F,3),
	AVR_PIN_DEF(F,4),
	AVR_PIN_DEF(F,5),
	AVR_PIN_DEF(F,6),
	AVR_PIN_DEF(F,7),
#endif

};

static struct pin_config_s pin_config[sizeof(pin_def)/sizeof(pin_def[0])];

void
pin_init()
{
	memset(pin_config,0,sizeof(pin_config));
}

uint8_t
pin_count()
{
	return sizeof(pin_def)/sizeof(pin_def[0]);
}

uint8_t
pin_features_get(int8_t i)
{
	return pin_def[i].features;
}

const char*
pin_name_get(uint8_t i)
{
	return pin_def[i].name;
}

const char* pin_localname_get(uint8_t i)
{
	if(pin_config[i].localname[0])
		return pin_config[i].localname;
	return pin_def[i].name;
}

void pin_localname_set(uint8_t i, const char* localname)
{
	if(localname) {
		strlcpy(pin_config[i].localname,localname,sizeof(pin_config[i].localname));
	} else {
		pin_config[i].localname[0] = 0;
	}
}

uint8_t pin_mode_get(int8_t i)
{
	return pin_config[i].mode;
}

#if __AVR__
void pin_mode_set(int8_t i, uint8_t mode)
{
	pin_config[i].mode = mode;
}

uint8_t pin_state_get(uint8_t i)
{
	return (*pin_config[i].avr.port_ptr) & pin_config[i].avr.mask;
}

void pin_state_set(uint8_t i, uint8_t state)
{
	if(state) {
		(*pin_config[i].avr.port_ptr) |= pin_config[i].avr.mask;
	} else {
		(*pin_config[i].avr.port_ptr) &= ~pin_config[i].avr.mask;
	}
}

void pin_state_toggle(uint8_t i)
{
	(*pin_config[i].avr.pin_ptr) = pin_config[i].avr.mask;
}
#endif

