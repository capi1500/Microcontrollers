CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
FLAGS = -mthumb -mcpu=cortex-m4
CPPFLAGS = -DSTM32F411xE
CFLAGS = $(FLAGS) -Wall -g \
	-O2 -ffunction-sections -fdata-sections \
	-I../stm32/inc \
	-I../stm32/CMSIS/Include \
	-I../stm32/CMSIS/Device/ST/STM32F4xx/Include

LDFLAGS = $(FLAGS) -Wl,--gc-sections -nostartfiles \
	-L../stm32/lds -Tstm32f411re.lds

vpath %.c ../stm32/src

OBJECTS = src/main.o src/controller/leds.o src/controller/usart2.o src/controller/buttons.o src/data/cyclic_buffer.o src/data/buffer.o startup_stm32.o delay.o gpio.o
TARGET = leds

.SECONDARY: $(TARGET).elf $(OBJECTS)

all: $(TARGET).bin

%.elf : $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

%.bin : %.elf
	$(OBJCOPY) $< $@ -O binary

clean :
	rm -f *.bin *.elf *.hex *.d *.o */*.o */*/*.o *.bak *~
