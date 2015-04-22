ALTERNATE_CORE   = sparkfun
BOARD_TAG        = promicro16
USER_LIB_PATH    = $(realpath libraries)
ARDUINO_LIBS     = Adafruit_GFX Adafruit_PCD8544 Timer SPI

ifndef ARDMK_DIR
	ARDMK_DIR = $(realpath libraries/Arduino-Makefile)
endif

include $(ARDMK_DIR)/Arduino.mk
