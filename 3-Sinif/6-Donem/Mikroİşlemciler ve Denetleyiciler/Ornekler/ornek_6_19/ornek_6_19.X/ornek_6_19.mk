#
# File: MCHP_dsPIC.tmf
#
#--------------------------------------------------------------
#   Embedded Coder for Microchip dsPIC30/dsPIC33/PIC24 family. |
#   Generate .c and .h files from your Matlab/simulink model   |
#   and compile the diagram to .hex / .elf or .coff file that  |
#   can be downloaded directly into the microcontroller        |
#                                                              |
#      The Microchip name PIC, dsPIC, and MPLAB are            |
#      registered trademarks of Microchip Technology Inc.      |
#      MATLAB, Simulink, and Real-Time Workshop are            |
#      registered trademarks of The MathWorks, Inc.            |
#                                                              |
#--------------------------------------------------------------
#------------------------ Macros read by make_rtw ------------------------------
MAKECMD          = "C:/Program Files/MATLAB/R2023b/bin/win64/gmake"
#SHELL            = cmd / sh for windows / linux
#HOST             = PC
HOST            = ANY
BUILD            = yes
BUILD_SUCCESS    = +++ Created
SYS_TARGET_FILE  = MCHP_dsPIC_stf.tlc
MAKEFILE_FILESEP = /
#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#
#  ---  ERT-only symbols:
#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done; if 0, the generated code runs indefinitely
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
#  ADD_MDL_NAME_TO_GLOBALS - Do we add the model name to global 
#                        identifiers (1/0)?
#  TERMFCN             - include terminate function
#  ONESTEPFCN          - include one-step function
#  --- Shared with ERT and GRT formats:
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of additional S-function modules.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link. 
#  HASCPPSFUNCTION     - Are we compiling any C++ S-Function as .obj(1/0)
#  NUMST               - Number of sample times
#  NCSTATES            - Number of continuous states
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  START_EXPAND_INCLUDES
#  EXPAND_DIR_NAME
#  END_EXPAND_INCLUDES

#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done,
#                        if 0, the generated code runs indefinitely
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
#  MODELREFS           - List of referenced models
#  TGT_FCN_LIB         - Target function (code replacement) library to use
#  SHRLIBTARGET        - Is this build intended for generation of a shared library instead 
#                        of executable (1/0)?
#  MAKEFILEBUILDER_TGT - Is this build performed by the MakefileBuilder class
#                        e.g. to create a PIL executable?
#  STANDALONE_SUPPRESS_EXE - Build the standalone target but only create object code modules 
#                            and do not build an executable



MODEL                   = ornek_6_19
MODULES                 = ornek_6_19_data.c ornek_6_19_main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c
#MODULES_OBJ            = ornek_6_19_data.obj ornek_6_19_main.obj rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj 
#PRODUCT                 = $(RELATIVE_PATH_TO_ANCHOR)/ornek_6_19.exe
MAKEFILE                = ornek_6_19.mk
MATLAB_ROOT             = C:/Program Files/MATLAB/R2023b
ALT_MATLAB_ROOT         = C:/PROGRA~1/MATLAB/R2023b
MASTER_ANCHOR_DIR       = 
START_DIR               = C:/Users/bugra/OneDrive/MASAST~1/Buðra/Dersler/üniversite/baun-ceng-notes/3-Sinif/6-Donem/MikroÝþlemciler ve Denetleyiciler/Ornekler/ornek_6_19
S_FUNCTIONS             = 
S_FUNCTIONS_LIB         = 
NUMST                   = 2
NCSTATES                = 0
COMPUTER                = PCWIN64
BUILDARGS               =  GENERATE_ASAP2=0 MCHP_AUTO_FLASH=0 MCHP_MULTITHREAD_COMPILATION=1 LinkWithMaster=0 OPTS="-DTID01EQ=0 -mdfp=C:/PROGRA~1/Microchip/MPLABX/v6.20/packs/Microchip/dsPIC33F-GP-MC_DFP/1.4.235/xc16"
MULTITASKING            = 1
INTEGER_CODE            = 0
MAT_FILE                = 0
ALLOCATIONFCN           = 0
ONESTEPFCN              = 1
TERMFCN                 = 1
B_ERTSFCN               = 0
MEXEXT                  = mexw64
EXT_MODE                = 0
TMW_EXTMODE_TESTING     = 0
EXTMODE_TRANSPORT       = 0
EXTMODE_STATIC          = 0
EXTMODE_STATIC_SIZE     = 500
MULTI_INSTANCE_CODE     = 0
CLASSIC_INTERFACE       = 0

GEN_SAMPLE_MAIN         = 0
TARGET_LANG_EXT         = c
PORTABLE_WORDSIZES      = 0
SHRLIBTARGET            = 0
MAKEFILEBUILDER_TGT     = 0
STANDALONE_SUPPRESS_EXE = 0
OPTIMIZATION_FLAGS      = 
ADDITIONAL_LDFLAGS      =  -mdfp=C:/PROGRA~1/Microchip/MPLABX/v6.20/packs/Microchip/dsPIC33F-GP-MC_DFP/1.4.235/xc16
INTERLEAVED_COMPLEX_FLAGS = -R2018a
DEFINES_CUSTOM          = 
DEFINES_OTHER           = -DHAVESTDIO
COMPILE_FLAGS_OTHER     = 
SYSTEM_LIBS             = 
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0

#--------------------------- Model and reference models -----------------------
MODELREFS                 = 
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = ornek_6_19_ref.rsp
MODELREF_INC_PATH         = 

TGT_FCN_LIB             = ISO_C
SHARED_SRC              = 
SHARED_SRC_DIR          = 
SHARED_BIN_DIR          = 
SHARED_LIB              = 

#--------------Simplify relative path -------------------------------
# xc16 might fail with path like ../../../../slprj/MCHP_dsPIC_stf/Microstick_II_PlusDevBoard_33EP128MC202_Temperature_PIL_Sub/Microstick_II_PlusDevBoard_33EP128MC202_Temperature_PIL_Sub_rtwlib_lib.a
MODELREF_LINK_LIBS := $(abspath  $(MODELREF_LINK_LIBS))


# warning: .. is different from MAtlab 2013a version (pointing to a folder beyong)
RELATIVE_PATH_TO_ANCHOR   = ..
MODELREF_TARGET_TYPE       = NONE

#-- For gcc, link model reference libraries as a group to resolve circular references ---
#   (NOTE: Clang does not recognize these switches but it already resolves circular references)
#MODELREF_LINK_LIBS_GROUP = 
#ifeq ($(COMPUTER),GLNXA64)
  MODELREF_LINK_LIBS_GROUP = -Wl,--start-group $(MODELREF_LINK_LIBS) -Wl,--end-group
#endif

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
	MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
# if MATLAB_ROOT has space (for system with no 8.3 compatibility mode, then any requirement of code from the matlab folder will fail to compile. That is the case for PIL or External Mode for ex.)


#--------------------------- Compatibility TRICKS -------------------------------

# Matlab R2020b: Instrumented code place makefile in the instrumented subfolder with no sources. Sources is one folder up.
# not OK if intrumenting the code ?
#ifeq (,$(wildcard $(MODULES)))	
#	MODULES := $(addprefix ../,$(MODULES))
#endif


#--------------------------- Backward Compabitility -------------------------------
# Declare variable that does not exist in older version with empty counterpart
STRING1 = |>SYSTEM_LIBS
STRING2 = <|
ifeq ($(SYSTEM_LIBS),$(STRING1)$(STRING2)) # split TMF variables for not beeing replaced
	SYSTEM_LIBS = 
endif
STRING1 = |>DEFINES_OTHER
STRING2 = <|
ifeq ($(DEFINES_OTHER),$(STRING1)$(STRING2)) # split TMF variables for not beeing replaced
	DEFINES_OTHER = 
endif
STRING1 = |>COMPILE_FLAGS_OTHER
STRING2 = <|
ifeq ($(COMPILE_FLAGS_OTHER),$(STRING1)$(STRING2)) # split TMF variables for not beeing replaced
	COMPILE_FLAGS_OTHER = 
endif

STRING1 = |>INTERLEAVED_COMPLEX_FLAGS
STRING2 = <|
ifeq ($(INTERLEAVED_COMPLEX_FLAGS),$(STRING1)$(STRING2)) # split TMF variables for not beeing replaced
	INTERLEAVED_COMPLEX_FLAGS = 0
endif

STRING1 = |>DEFINES_CUSTOM
STRING2 = <|
ifeq ($(DEFINES_CUSTOM),$(STRING1)$(STRING2)) # split TMF variables for not beeing replaced
	DEFINES_CUSTOM = 
endif

STRING1 = |>MODEL_HAS_DYNAMICALLY_LOADED_SFCNS
STRING2 = <|
ifeq ($(MODEL_HAS_DYNAMICALLY_LOADED_SFCNS),$(STRING1)$(STRING2)) # split TMF variables for not beeing replaced
	MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
endif

STRING1 = |>GENERATE_ALLOC_FCN
STRING2 = <|
ifeq ($(ALLOCATIONFCN),$(STRING1)$(STRING2)) # split TMF variables for not beeing replaced
	ALLOCATIONFCN = 
endif


#--------------------------- Tool Specifications -------------------------------

ifeq ($(COMPUTER),GLNXA64)
	S_FUNCTIONS_LIB := $(subst \,/,$(S_FUNCTIONS_LIB))
endif

AssemblyListing = 0
ProduceHexOutput = 1

GCC1    := xc16-gcc.exe
AR1     = xc16-ar
BIN2HEX1 = xc16-bin2hex
OBJDUMP1 = xc16-objdump

GCC1 :=  $(basename $(GCC1))

GCCPATH	:= C:/PROGRA~1/Microchip/xc16/v1.70/bin

ifeq ($(strip $(GCCPATH)),)
	CC   = $(GCC1)
	CPP  = $(GCC1)
	LD   = $(GCC1)
	AR   = $(AR1) -r -omf=$(OMF)
	BIN2HEX = $(BIN2HEX1)
	OBJDUMP = $(OBJDUMP1)	
else
	CC   = "$(GCCPATH)/$(GCC1)"
	CPP  = "$(GCCPATH)/$(GCC1)"
	LD   = "$(GCCPATH)/$(GCC1)"
	AR   = "$(GCCPATH)/$(AR1)" -r -omf=$(OMF)
	BIN2HEX = "$(GCCPATH)/$(BIN2HEX1)"
	OBJDUMP = "$(GCCPATH)/$(OBJDUMP1)"		
endif

# slave1_image
SECONDARYIMAGE = 

ifeq ($(COMPUTER),GLNXA64)
	DEL = rm -rf
	SHELL = sh
	COPY = cp
else
	DEL = del /Q
	SHELL = cmd
	COPY = copy /Y
endif

define DEL_IF_EXIST
	ifneq (,$(wildcard $1))		# if file exist	
		$(DEL) $1
	endif
endef


#------------------------------ Others dsPIC blockset parameters --------------
EXTMODE_DATA_UPLOAD = 0
OMF   	        = elf

OPTIM_GCC 		=  -O2 -mno-eds-warn -mconst-in-data -msmall-data
LDFLAGS 		= --report-mem,-Map=info.map,-cref,-lq-dsp,--memorysummary,memoryfile.xml
LINKER_SCRIPT 	= "p33FJ32MC204.gld"
PIC_LIB 		= 
PIC_INCLUDES 	= 
PIC_REF 		= 33FJ32MC204


# clean settings from old model susceptible to cause issues with recent compiler or linker
# theses settings were written twice in the command line 
# remove -omf=xx definition from OPTIM_GCC, defined twice otherwise for old models, might cause issue with xc-dsc
OPTIM_GCC 		:= $(subst -omf=elf,,$(OPTIM_GCC))
OPTIM_GCC 		:= $(subst -omf=cof,,$(OPTIM_GCC))
OPTIM_GCC 		:= $(subst -omf=coff,,$(OPTIM_GCC))

# remove -omf=xx definition from LDFLAGS, defined twice otherwise for old models, might cause issue with xc-dsc
LDFLAGS 		:= $(subst -omf=elf,,$(LDFLAGS))
LDFLAGS 		:= $(subst -omf=cof,,$(LDFLAGS))
LDFLAGS 		:= $(subst -omf=coff,,$(LDFLAGS))


#-- always add one space just before -Xlinker solve possible ambiguity while using -Wl flag. Solve problem when LDFLAGS starts with -Xlinker (old style)
LDFLAGS := $(subst -Xlinker, -Xlinker,$(LDFLAGS))


MCPU  			   = -mcpu=$(PIC_REF)
PROGRAM_FILE_EXT   = .$(subst coff,cof,$(OMF))

T_LINKER_SCRIPT = -omf=$(OMF) -Wl,--script=$(LINKER_SCRIPT)

LDLIBPIC = $(PIC_LIB)


CC_OPTS 		= $(MCPU) -omf=$(OMF) $(OPTIM_GCC) $(OPTS)

ifeq ($(INTEGER_CODE),1)
	CC_OPTS 		+= -DINTEGER_CODE=1
endif

OBJ_EXT =.o
CCOUTPUTFLAG = -o


#----------------------------- External mode -----------------------------------
# added OPTS: from make file call, define MemUnit_T=uint8_T and MEM_UNIT_BYTES=, usefull for PIL or external mode
# EXTMODE_DISABLESIGNALMONITORING EXTMODE_DISABLE_ARGS_PROCESSING  MULTITASKING
# -DEXTMODE_DISABLESIGNALMONITORING=1

EXT_SRC = 

ifeq ($(EXT_MODE),1)
	#---Compiler and Linker settings---
    ifeq ($(MULTITASKING),1)
		LDFLAGS += -Wl,--wrap,_SetParam
    endif

	CC_OPTS += -DEXT_MODE=1 -DEXTMODE_DISABLEPRINTF=1 -DEXTMODE_DISABLETESTING=1 -DEXTMODE_DISABLE_ARGS_PROCESSING=1
    ifeq ($(EXTMODE_DATA_UPLOAD),0)
		CC_OPTS += -DEXTMODE_DISABLESIGNALMONITORING=1
    endif

	#---required files---

	#external mode sources
	EXT_SRC  += ext_svr.c updown.c ext_work.c 

	# static memory management (optional)
    ifeq ($(EXTMODE_STATIC),1)
	  EXT_SRC += mem_mgr.c
	  CC_OPTS +=  -DEXTMODE_STATIC=1 -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
    endif
	# add rtiostream_utils.c
	EXT_SRC += $(S_FUNCTIONS) # add rtiostream_utils.c from R2013 to ~R2018?     
endif
#------------------------------ parameter controlled from simulink ----------------
# Keep following line, help the Matlab programming tool to find the programmer.
# Additional info : PICREF{33FJ32MC204} PROGRAMMER{}
#------------------------------ Include Path -----------------------------------
#
# Additional includes 
ADD_INCLUDES += \
	-I"C:/Users/bugra/OneDrive/MASAST~1/Buðra/Dersler/üniversite/baun-ceng-notes/3-Sinif/6-Donem/MikroÝþlemciler ve Denetleyiciler/Ornekler/ornek_6_19" \
	-I"C:/Users/bugra/OneDrive/MASAST~1/Buðra/Dersler/üniversite/baun-ceng-notes/3-Sinif/6-Donem/MikroÝþlemciler ve Denetleyiciler/Ornekler/ornek_6_19/ornek_6_19.X" \
	-I"$(MATLAB_ROOT)/extern/include" \
	-I"$(MATLAB_ROOT)/simulink/include" \
	-I"$(MATLAB_ROOT)/rtw/c/src" \
	-I"$(MATLAB_ROOT)/rtw/c/src/ext_mode/common" \
	-I"$(MATLAB_ROOT)/rtw/c/ert" \

INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(USER_INCLUDES) \
	$(INSTRUMENT_INCLUDES) $(ADD_INCLUDES)
# MATLAB_INCLUDES = \
# 	-I"$(MATLAB_ROOT)/rtw/c/ert" \
# 	-I"$(MATLAB_ROOT)/extern/include" \
# 	-I"$(MATLAB_ROOT)/simulink/include" \
# 	-I"$(MATLAB_ROOT)/rtw/c/src" \
# 	-I"$(MATLAB_ROOT)/rtw/c/src/ext_mode/common"
# 
# # Additional includes
# #
# ADD_INCLUDES = \
# 	-I"C:/Users/bugra/OneDrive/MASAST~1/Buðra/Dersler/üniversite/baun-ceng-notes/3-Sinif/6-Donem/MikroÝþlemciler ve Denetleyiciler/Ornekler/ornek_6_19" \
# 	-I"C:/Users/bugra/OneDrive/MASAST~1/Buðra/Dersler/üniversite/baun-ceng-notes/3-Sinif/6-Donem/MikroÝþlemciler ve Denetleyiciler/Ornekler/ornek_6_19/ornek_6_19.X" \
# 	-I"$(MATLAB_ROOT)/extern/include" \
# 	-I"$(MATLAB_ROOT)/simulink/include" \
# 	-I"$(MATLAB_ROOT)/rtw/c/src" \
# 	-I"$(MATLAB_ROOT)/rtw/c/src/ext_mode/common" \
# 	-I"$(MATLAB_ROOT)/rtw/c/ert" \
# 
# 
# 
# SHARED_INCLUDES =
# ifneq ($(SHARED_SRC_DIR),)
# 	SHARED_INCLUDES = -I"$(SHARED_SRC_DIR)"
# endif
# 
# INCLUDES = -I. -I"$(RELATIVE_PATH_TO_ANCHOR)" $(MATLAB_INCLUDES) $(ADD_INCLUDES) \
# 			 $(PIC_INCLUDES) $(MODELREF_INC_PATH) \
# 			 $(SHARED_INCLUDES) \
# 			 $(USER_INCLUDES) $(INSTRUMENT_INCLUDES) $(USER_INCLUDES)
#--------------------------- Backward Compabitility -------------------------------
#ifeq ($(EXT_MODE),1)	
    ifeq (,$(findstring /simulink/include,$(ADD_INCLUDES)))  # apply to OLD matlab release only
		# add some required includes for external mode
		ADD_INCLUDES += \
			-I$(MATLAB_ROOT)/rtw/c/ert \
			-I$(MATLAB_ROOT)/extern/include \
			-I$(MATLAB_ROOT)/simulink/include \
			-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common \
			-I$(MATLAB_ROOT)/rtw/c/src 
		# required for PIl with R2012a
        ifneq ($(SHARED_SRC_DIR),)
			ADD_INCLUDES += -I"$(SHARED_SRC_DIR)"
        endif   
    endif
#endif
#-------------------------------- C Flags --------------------------------------
# General User Options
# New : to support Continuous States ? find in "Upgrading from V3.2.1 or V3.2"
#removed -DHAVESTDIO as we do not use STDIO input/output
# not added: -DADD_MDL_NAME_TO_GLOBALS=$(ADD_MDL_NAME_TO_GLOBALS)
CPP_REQ_DEFINES1 = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
		  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		  -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE)\
		  -DALLOCATIONFCN=$(ALLOCATIONFCN)\
		  
#!if "$(MODELREF_TARGET_TYPE)" == "SIM"
#CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) $(MDLREF_FLAG)
#!else
#CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) -DMT=$(MULTITASKING)
#!endif		
ifneq ($(ENABLE_SLEXEC_SSBRIDGE), 0)
    ifeq ($(MODELREF_TARGET_TYPE),SIM)
        CPP_REQ_DEFINES1 += -DENABLE_SLEXEC_SSBRIDGE=$(ENABLE_SLEXEC_SSBRIDGE)
    endif
endif
CPP_REQ_DEFINES = $(CPP_REQ_DEFINES1)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
	CPP_REQ_DEFINES += -DMDL_REF_SIM_TGT=1 
else
	CPP_REQ_DEFINES += -DMT=$(MULTITASKING)
endif
CPP_REQ_DEFINES += -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=$(MODEL_HAS_DYNAMICALLY_LOADED_SFCNS)
CFLAGS    =$(CC_OPTS)  $(INCLUDES)
CPPFLAGS = $(CC_OPTS)  $(INCLUDES)
DEFINES = $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(DEFINES_OTHER)
CFLAGS = $(ANSI_OPTS) $(DBG_FLAG) $(CC_OPTS) $(DEFINES) $(INCLUDES)
CPPFLAGS = $(CPP_ANSI_OPTS) $(DBG_FLAG) $(CPP_OPTS) $(CC_OPTS) $(DEFINES) $(INCLUDES)
#-------------------------- Additional Libraries ------------------------------
#LIBS =
#
#
#LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)
SYSTEM_LIBS += -lm
LIBS =
 
LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)
#-------------------------------- Target application --------------------------------------
# Define the target file

ifeq ($(MODELREF_TARGET_TYPE), NONE)
    ifeq ($(SHRLIBTARGET), 1)
		-@echo "Shared Lib Targer: do nothing"
    endif
    ifeq ($(MAKEFILEBUILDER_TGT), 0)
        ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
            # Build object code only for top level model (preliminary step for building
            # PIL application)
            BUILD_MODE=pil_prebuild
            PRODUCT=ObjectModules
            BUILD_PRODUCT_TYPE = object modules

            # BUILD_MODE= pil_prebuild
            # PRODUCT = $(MODELLIB)
            # BUILD_PRODUCT_TYPE = library
            
            else
            # Building executable for real-time deployment
            BUILD_MODE=real_time
            # remove MODELLIB from linker
            # MODELLIB =
            PRODUCT = $(MODEL)$(PROGRAM_FILE_EXT)
            BUILD_PRODUCT_TYPE = executable
        endif
    else
        # Building executable for deployment as PIL application (non-real-time
        # simulation)
        BUILD_MODE= pil_application
        PRODUCT = $(MODEL)$(PROGRAM_FILE_EXT)
        BUILD_PRODUCT_TYPE = executable
    endif
else
    # Building a library for a referenced model
    BUILD_MODE = model_reference
    PRODUCT = $(MODELLIB)
    BUILD_PRODUCT_TYPE = library
endif


#-------------- Source Files, Object Files and Dependency Files -----------

# #wildcard does not support slash, must be replaced with backslash at least for SHARED_SRC
SHARED_SRC := $(subst \,/,$(SHARED_SRC))

# SHARED_SRC source file required with R2012a for PIL
SHARED_SRC := $(wildcard $(SHARED_SRC))
SHARED_OBJS = $(addsuffix $(OBJ_EXT), $(basename $(SHARED_SRC)))

ADD_SRCS = $(SHARED_SRC)

SRCS = $(ADD_SRCS) $(MODULES) $(EXT_SRC)

ifeq ($(BUILD_MODE), real_time)
   SRCS += $(MODEL).$(TARGET_LANG_EXT) 
endif

ifeq ($(BUILD_MODE), pil_prebuild)
   SRCS += $(MODEL).$(TARGET_LANG_EXT) 
endif

USER_SRCS =

USER_OBJS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

OBJS      = $(addsuffix .o, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJS)

ADDITIONAL_LDFLAGS += $(ARCH_SPECIFIC_LDFLAGS)

#------------------------------- Delete target on error ------------------------

.DELETE_ON_ERROR :



#------------------------------- Libraries -------------------------------------





#-------------- Default target -----------
TARGETS = $(PRODUCT)

all: $(TARGETS)

# Need a rule to generate the build success string if product was already up to date
.PHONY : all
all : $(PRODUCT)
	-@echo "### Created $(PRODUCT) successfully (or it was already up to date)"





##-------------------------- Support for building modules ----------------------
ifeq ($(BUILD_MODE), pil_prebuild)
.PHONY: $(PRODUCT)
$(PRODUCT) : $(OBJS) $(LIBS) 
	-@echo "### BUILD_MODE $(BUILD_MODE)"
	-@echo "+++ Created object modules: $@"
endif


ifeq ($(BUILD_MODE), model_reference)
$(PRODUCT) : $(OBJS) 	
	-@echo "### BUILD_MODE $(BUILD_MODE)"
	@$(DEL_IF_EXIST,$(MODELLIB))
	-@echo "+++ Creating library ..."
	$(AR) $(MODELLIB) $(LINK_OBJS)
	-@echo "$(BUILD_SUCCESS) $(BUILD_PRODUCT_TYPE): $@"
endif


ifeq ($(BUILD_MODE), pil_application)
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELLIB) $(MODELREF_LINK_LIBS)
	-@echo "### BUILD_MODE $(BUILD_MODE)"
	-@echo "LDLIBPIC $(LDLIBPIC)"
	-@echo "LINK_OBJS $(LINK_OBJS)"
	-@echo "MODELLIB $(MODELLIB)"
	-@echo "MODELREF_LINK_LIBS_GROUP $(MODELREF_LINK_LIBS_GROUP)"
	-@echo "LIBS $(LIBS)"
	-@echo "SYSTEM_LIBS $(SYSTEM_LIBS)"	
    ifeq ($(ProduceHexOutput),1)
		$(DEL_IF_EXIST,$(MODEL).hex)
    endif
    ifeq ($(AssemblyListing),1)
		$(DEL_IF_EXIST,$(MODEL).lst)
    endif		
	$(LD) $(MCPU) $(LDLIBPIC) $(LINK_OBJS) $(MODELLIB) $(MODELREF_LINK_LIBS_GROUP) $(LIBS) $(SYSTEM_LIBS) -o $(MODEL)$(PROGRAM_FILE_EXT) $(T_LINKER_SCRIPT),$(LDFLAGS) $(ADDITIONAL_LDFLAGS)
	-@echo "$(BUILD_SUCCESS) $(BUILD_PRODUCT_TYPE): $@  [$(PIC_REF)]"
    ifeq ($(ProduceHexOutput),1)
		$(BIN2HEX) -omf=$(OMF) $(PRODUCT)
		-@echo "+++ Converted $(MODEL)$(PROGRAM_FILE_EXT) to $(MODEL).hex"
    endif
    ifeq ($(AssemblyListing),1)
		$(OBJDUMP) -omf=$(OMF) -S -f -Msymbolic $(PRODUCT) > $(MODEL).lst
		-@echo "+++ Created Assembly list file $(MODEL).lst"
    endif
endif

ifeq ($(BUILD_MODE), real_time)
#$(MODEL)$(PROGRAM_FILE_EXT) : $(OBJS) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBS)
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	-@echo "### BUILD_MODE $(BUILD_MODE)"
    ifeq ($(ProduceHexOutput),1)
		$(DEL_IF_EXIST,$(MODEL).hex)
    endif
    ifeq ($(AssemblyListing),1)
		$(DEL_IF_EXIST,$(MODEL).lst)
    endif	
	$(LD) $(MCPU) $(LDLIBPIC) $(LINK_OBJS) $(MODELREF_LINK_LIBS_GROUP) $(LIBS) $(SYSTEM_LIBS) -o $(MODEL)$(PROGRAM_FILE_EXT) $(T_LINKER_SCRIPT),$(LDFLAGS)	$(ADDITIONAL_LDFLAGS)
	-@echo "$(BUILD_SUCCESS) $(BUILD_PRODUCT_TYPE): $@"
    ifeq ($(ProduceHexOutput),1)
		$(BIN2HEX) -omf=$(OMF) $(PRODUCT)
		-@echo "+++ Converted $(PRODUCT) to $(MODEL).hex"
    endif
    ifeq ($(AssemblyListing),1)
		$(OBJDUMP) -omf=$(OMF) -S -f -Msymbolic $(PRODUCT) > $(MODEL).lst
		-@echo "+++ Created Assembly list file $(MODEL).lst"
    endif
    ifneq ($(strip $(SECONDARYIMAGE)),)
		-@echo "### Write secondary core Image and header to integrate in Main core project."
        ifeq (,$(wildcard $(SECONDARYIMAGE)/.*))
	mkdir $(SECONDARYIMAGE)
        endif
        ifneq (,$(wildcard Secondary_FuseConfig.h))
	$(COPY) Secondary_FuseConfig.h $(SECONDARYIMAGE)
        endif
	$(BIN2HEX) $(PRODUCT) --image $(SECONDARYIMAGE)/$(SECONDARYIMAGE)
		-@echo "+++ Created secondary core Image $(SECONDARYIMAGE).s and $(SECONDARYIMAGE).h header definition file"
    endif
endif


#-------------------------- Clean up ----------------------


ifeq ($(OMF),elf)
	$(DEL_IF_EXIST,$(MODEL).cof)
endif

ifeq ($(OMF),coff)
	$(DEL_IF_EXIST,$(MODEL).elf)
endif

ifeq ($(ProduceHexOutput),0)
	$(DEL_IF_EXIST,$(MODEL).hex)
endif

ifeq ($(AssemblyListing),0)
	$(DEL_IF_EXIST,$(MODEL).lst)
endif

#-------------------------- Support for building modules ----------------------

mem_mgr.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/mem_mgr.c
	@$(DEL_IF_EXIST,$@)
	$(CC) -c -fno-strict-aliasing $(CFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CPPFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : %.c
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : %.cpp
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CPPFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : %.s
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g $(CCOUTPUTFLAG) $@

# required ? (for PIL with some matlab releases)
%$(OBJ_EXT) : ../%.c
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(MATLAB_ROOT)/rtw/c/src/%.c
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(MATLAB_ROOT)/simulink/src/%.c
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CFLAGS) $< $(CCOUTPUTFLAG) $@



%$(OBJ_EXT) : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CPPFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(MATLAB_ROOT)/simulink/src/%.cpp
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CPPFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c $(CPPFLAGS) $< $(CCOUTPUTFLAG) $@



%$(OBJ_EXT) : $(MATLAB_ROOT)/rtw/c/src/%.s
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(MATLAB_ROOT)/simulink/src/%.s
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.s
	@$(DEL_IF_EXIST,$@)
	-@echo Compiling: $<
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g $(CCOUTPUTFLAG) $@




# Libraries:





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

#$(SHARED_LIB) : $(SHARED_OBJS)
#	-@echo ### Creating $@
#	$(AR) $@ $(SHARED_OBJS)
#	-@echo ### $@ Created
