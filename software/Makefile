CONTIKI_PROJECT = fauxbee

CONTIKI := ../../contiki
SMCP_ROOT := ../../smcp

include $(SMCP_ROOT)/contiki-src/Makefile.smcp

CLEAN += *.hex *.elf symbols.c symbols.h

ifdef VERBOSE_DEBUG
CFLAGS+=-DVERBOSE_DEBUG=$(VERBOSE_DEBUG)
endif

ifeq ($(DEBUG),1)
CFLAGS += -O0 -g
CFLAGS += -DDEBUG=1
#CFLAGS += -DUIP_CONF_LOGGING=1
endif

UIP_CONF_IPV6 = 1

all: $(CONTIKI_PROJECT)

include $(CONTIKI)/Makefile.include

ifeq ($(CC),sdcc)
CFLAGS += --disable-warning 115
endif

burn: $(CONTIKI_PROJECT).u

burn-eeprom: $(CONTIKI_PROJECT).u-eep
