CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

CHIBIOS = .

vpath %.c \
	hal/src hal/platforms/STM32F0xx \
	hal/platforms/STM32 hal/platforms/STM32/I2Cv2 \
	hal/platforms/STM32/GPIOv2 hal/platforms/STM32/USARTv2 \
	hal/platforms/STM32/TIMv1 hal/platforms/STM32/SPIv2 \
	kernel/src ports/GCC/ARMCMx ports/GCC/ARMCMx/STM32F0xx ports/common/ARMCMx \
	boards/ST_STM32F0_DISCOVERY

PORT_SRCS = \
	chcore.c chcore_v6m.c nvic.c

HAL_SRCS = \
	adc.c can.c ext.c gpt.c hal.c i2c.c \
	icu.c mac.c mmc_spi.c mmcsd.c pal.c pwm.c \
	rtc.c sdc.c serial.c serial_usb.c spi.c tm.c \
	uart.c usb.c \
	hal_lld.c adc_lld.c i2c_lld.c pal_lld.c serial_lld.c uart_lld.c \
	can_lld.c ext_lld.c mac_lld.c sdc_lld.c gpt_lld.c icu_lld.c pwm_lld.c spi_lld.c \
	stm32_dma.c board.c

KERNEL_SRCS = \
	chcond.c chdebug.c chdynamic.c chevents.c chheap.c chlists.c chmboxes.c \
	chmemcore.c chmempools.c chmsg.c chmtx.c chqueues.c chregistry.c chschd.c \
	chsem.c chsys.c chthreads.c chvt.c

include chibios.mk

CFLAGS = -mcpu=cortex-m0 -O2 -ggdb -fomit-frame-pointer -falign-functions=16 -ffunction-sections -fdata-sections -fno-common  -Wall -Wextra -Wstrict-prototypes
CFLAGS += -DCORTEX_USE_FPU=FALSE  -DTHUMB_PRESENT -mno-thumb-interwork -DTHUMB_NO_INTERWORKING
CFLAGS += -MD -MP -mthumb -DTHUMB
CFLAGS += $(CHIBIOS_INC)

TARGETDIR = ../build/lib

SRCS = \
	$(PORT_SRCS) \
	$(KERNEL_SRCS) \
	$(HAL_SRCS)

OBJS = $(addprefix $(TARGETDIR)/,$(SRCS:.c=.o))

.PHONY: lib$(CHIBIOS_LIB).a

all: lib$(CHIBIOS_LIB).a

$(TARGETDIR)/%.o : %.c
	$(CC)  -c $(CFLAGS) -o $@ $<

$(OBJS): | $(TARGETDIR)

$(TARGETDIR):
	mkdir -p $(TARGETDIR)
    
libchibios_stm32f0xx.a: $(OBJS)
	$(AR) -r $(TARGETDIR)/$@ $(OBJS)

clean:
	rm -rf $(OBJS) $(TARGETDIR)/
