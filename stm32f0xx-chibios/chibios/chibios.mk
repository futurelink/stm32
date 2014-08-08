CHIBIOS_INC += \
	-I$(CHIBIOS)/kernel/include \
	-I$(CHIBIOS)/hal/include \
	-I$(CHIBIOS)/hal/platforms/STM32 \
	-I$(CHIBIOS)/hal/platforms/STM32/GPIOv2 \
	-I$(CHIBIOS)/hal/platforms/STM32/I2Cv2 \
	-I$(CHIBIOS)/hal/platforms/STM32/USARTv2 \
	-I$(CHIBIOS)/hal/platforms/STM32F0xx \
	-I$(CHIBIOS)/ports/GCC/ARMCMx \
	-I$(CHIBIOS)/ports/GCC/ARMCMx/STM32F0xx \
	-I$(CHIBIOS)/ports/common/ARMCMx \
	-I$(CHIBIOS)/ports/common/ARMCMx/CMSIS/include \
	-I$(CHIBIOS)/boards/ST_STM32F0_DISCOVERY \
	-I$(CHIBIOS)/../src/conf \
	-I$(CHIBIOS)

CHIBIOS_LIB = chibios_stm32f0xx
