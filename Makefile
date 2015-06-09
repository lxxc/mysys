#sample Makefile

CC		:=gcc
OUTP	=-o $@
CFLAGS	:=-c


T_SRCD	:=mysys_src
C_SRCD	:=calljpg_src
OBJD	:=obj
BIND	:=bin

T_SRCF	:= $(wildcard $(T_SRCD)/*.c)
C_SRCF	:= $(wildcard $(C_SRCD)/*.c)
T_OBJF	:= $(patsubst $(T_SRCD)/%,$(OBJD)/%,$(patsubst %.c,%.o,$(wildcard $(T_SRCD)/*.c)))
C_OBJF	:= $(patsubst $(C_SRCD)/%,$(OBJD)/%,$(patsubst %.c,%.o,$(wildcard $(C_SRCD)/*.c)))


TAROT	:=$(BIND)/tarot.exe
CALL	:=$(BIND)/call.exe

TARGET	:=$(TAROT) $(CALL)
 
all:$(TARGET)
	

$(TAROT):$(T_OBJF)
	$(CC) $^ $(OUTP)
$(CALL):$(C_OBJF)
	$(CC) $^ $(OUTP)

###############################################
$(OBJD)/%.o:$(T_SRCD)/%.c
	$(CC) $(CFLAGS) $< $(OUTP)
$(OBJD)/%.o:$(C_SRCD)/%.c
	$(CC) $(CFLAGS) $< $(OUTP)


