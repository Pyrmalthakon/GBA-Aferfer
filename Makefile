lben.gba : alif.elf
	arm-none-eabi-objcopy -O binary alif.elf lben.gba
	gbafix lben.gba
alif.elf : alif.o
	arm-none-eabi-gcc -specs=gba.specs -mthumb alif.o -o alif.elf
alif.o : boot.c
	arm-none-eabi-gcc -mthumb -mthumb-interwork -c boot.c -o alif.o

