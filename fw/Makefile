PROJECT = hydro
BUILD_DIR = bin

SRC := ./src
INC := ./inc
LBS := ./lib

# C Source Files
CFILES = $(wildcard $(SRC)/*.c)
CFILES += $(wildcard $(LBS)/freertos/*.c)

# Cpp Source Files
CPPFILES = $(wildcard $(SRC)/*.cpp)

# Inclues
INCLUDES += -I$(SRC)
INCLUDES += -I$(LBS)/freertos
INCLUDES += -I$(INC)

DEVICE=stm32f103c8t6
OPENCM3_DEFS+=-DSTM32F1
OOCD_FILE = interface/stlink.cfg 

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=lib/libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
