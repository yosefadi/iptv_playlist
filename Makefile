#
# Makefile for GNU/UNIX
#

ARCH				?= arm64
CROSS_COMPILE		?=  ~/toolchains/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
CROSS_COMPILE_DIR	?=	~/toolchains/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/

AS					= $(CROSS_COMPILE)as
CPP					= ccache $(CROSS_COMPILE)g++
CC					= ccache $(CROSS_COMPILE)gcc
AR					= $(CROSS_COMPILE)ar
NM					= $(CROSS_COMPILE)nm
STRIP				= $(CROSS_COMPILE)strip
OBJCOPY				= $(CROSS_COMPILE)objcopy
OBJDUMP				= $(CROSS_COMPILE)objdump
RM					= rm -f

OBJ					= main.o
LIBKOBJ				= main.o
LIBS				= -L $(CROSS_COMPILE_DIR)/lib -static-libgcc
INCS				= -I $(CROSS_COMPILE_DIR)/include
CXXINCS				= -I $(CROSS_COMPILE_DIR)/include
CFLAGS				= $(INCS) -ansi -O3 --Wall -Wfatal-errors -Wundef  \
					  -Wstrict-prototypes -Wno-trigraphs \
					  -fno-strict-aliasing -fno-asm -fno-delete-null-pointer-checks \
					  -mcpu=cortex-a57.cortex-a53 -mtune=cortex-a57.cortex-a53
CXXFLAGS			= $(CXXINCS) -ansi -O3 --Wall -Wfatal-errors -Wundef  \
					  -Wstrict-prototypes -Wno-trigraphs \
					  -fno-strict-aliasing -fno-asm -fno-delete-null-pointer-checks \
					  -mcpu=cortex-a57.cortex-a53 -mtune=cortex-a57.cortex-a53

BIN					= autoupdate-iptv_$(ARCH)

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
		${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
		$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)
		
main.o:	main.cpp
		$(CPP) -c main.cpp -o main.o $(CXXFLAGS)
