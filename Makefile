ALTERNATE_CORE   = sparkfun
BOARD_TAG        = promicro16

ifndef ARDMK_DIR
	ARDMK_DIR = $(realpath libraries/Arduino-Makefile)
endif

include $(ARDMK_DIR)/Arduino.mk
