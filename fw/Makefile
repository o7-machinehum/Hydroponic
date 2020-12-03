PROJECT = hydro
BUILD_DIR = bin

SRC := ./src
LBS := ./lib
CFILES = $(wildcard $(SRC)/*.c)
CFILES += $(wildcard $(LBS)/freertos/*.c)
INCLUDES += -I$(SRC)
INCLUDES += -I$(LBS)/freertos
# INCLUDES += -I$(LBS)/libopencm3

# TODO - you will need to edit these two lines!
DEVICE=stm32f103c8t6
OOCD_FILE = interface/stlink.cfg 

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=lib/libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
