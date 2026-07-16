#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-Simulink.mk)" "nbproject/Makefile-local-Simulink.mk"
include nbproject/Makefile-local-Simulink.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Simulink
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Deney1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Deney1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C:/Users/bugra/Downloads/Deney1.X/Deney1.c C:/Users/bugra/Downloads/Deney1.X/Deney1_main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/648173853/Deney1.o ${OBJECTDIR}/_ext/648173853/Deney1_main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/648173853/Deney1.o.d ${OBJECTDIR}/_ext/648173853/Deney1_main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/648173853/Deney1.o ${OBJECTDIR}/_ext/648173853/Deney1_main.o

# Source Files
SOURCEFILES=C:/Users/bugra/Downloads/Deney1.X/Deney1.c C:/Users/bugra/Downloads/Deney1.X/Deney1_main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-Simulink.mk ${DISTDIR}/Deney1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ32MC204
MP_LINKER_FILE_OPTION=,--script=dsPIC33FJ32MC204.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/648173853/Deney1.o: C:/Users/bugra/Downloads/Deney1.X/Deney1.c  .generated_files/flags/Simulink/9674008de218aff2e1555dd4f190a4451f7a2b07 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/648173853" 
	@${RM} ${OBJECTDIR}/_ext/648173853/Deney1.o.d 
	@${RM} ${OBJECTDIR}/_ext/648173853/Deney1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/bugra/Downloads/Deney1.X/Deney1.c  -o ${OBJECTDIR}/_ext/648173853/Deney1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/648173853/Deney1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/Users/bugra/Downloads" -I"C:/Users/bugra/Downloads/Deney1.X" -I"C:/Program Files/MATLAB/R2023b/rtw/c/src" -I"C:/Program Files/MATLAB/R2023b/simulink/src" -I"C:/Program Files/MATLAB/R2023b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2023b/extern/include" -I"C:/Program Files/MATLAB/R2023b/simulink/include" -I"C:/Program Files/MATLAB/R2023b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2023b/rtw/c/ert" -DMODEL=Deney1 -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/648173853/Deney1_main.o: C:/Users/bugra/Downloads/Deney1.X/Deney1_main.c  .generated_files/flags/Simulink/a2816a5dc09d3053177f4cd3f8769cbc2252477d .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/648173853" 
	@${RM} ${OBJECTDIR}/_ext/648173853/Deney1_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/648173853/Deney1_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/bugra/Downloads/Deney1.X/Deney1_main.c  -o ${OBJECTDIR}/_ext/648173853/Deney1_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/648173853/Deney1_main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/Users/bugra/Downloads" -I"C:/Users/bugra/Downloads/Deney1.X" -I"C:/Program Files/MATLAB/R2023b/rtw/c/src" -I"C:/Program Files/MATLAB/R2023b/simulink/src" -I"C:/Program Files/MATLAB/R2023b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2023b/extern/include" -I"C:/Program Files/MATLAB/R2023b/simulink/include" -I"C:/Program Files/MATLAB/R2023b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2023b/rtw/c/ert" -DMODEL=Deney1 -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/648173853/Deney1.o: C:/Users/bugra/Downloads/Deney1.X/Deney1.c  .generated_files/flags/Simulink/874d3c08925b703a85d2c690d047b7c55ce99909 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/648173853" 
	@${RM} ${OBJECTDIR}/_ext/648173853/Deney1.o.d 
	@${RM} ${OBJECTDIR}/_ext/648173853/Deney1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/bugra/Downloads/Deney1.X/Deney1.c  -o ${OBJECTDIR}/_ext/648173853/Deney1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/648173853/Deney1.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/Users/bugra/Downloads" -I"C:/Users/bugra/Downloads/Deney1.X" -I"C:/Program Files/MATLAB/R2023b/rtw/c/src" -I"C:/Program Files/MATLAB/R2023b/simulink/src" -I"C:/Program Files/MATLAB/R2023b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2023b/extern/include" -I"C:/Program Files/MATLAB/R2023b/simulink/include" -I"C:/Program Files/MATLAB/R2023b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2023b/rtw/c/ert" -DMODEL=Deney1 -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/648173853/Deney1_main.o: C:/Users/bugra/Downloads/Deney1.X/Deney1_main.c  .generated_files/flags/Simulink/161748a1bd1f3c60d0e498abe4a31d96410951ad .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/648173853" 
	@${RM} ${OBJECTDIR}/_ext/648173853/Deney1_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/648173853/Deney1_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/bugra/Downloads/Deney1.X/Deney1_main.c  -o ${OBJECTDIR}/_ext/648173853/Deney1_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/648173853/Deney1_main.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/Users/bugra/Downloads" -I"C:/Users/bugra/Downloads/Deney1.X" -I"C:/Program Files/MATLAB/R2023b/rtw/c/src" -I"C:/Program Files/MATLAB/R2023b/simulink/src" -I"C:/Program Files/MATLAB/R2023b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2023b/extern/include" -I"C:/Program Files/MATLAB/R2023b/simulink/include" -I"C:/Program Files/MATLAB/R2023b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2023b/rtw/c/ert" -DMODEL=Deney1 -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Deney1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Deney1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--heap=0,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--stackguard=16,--library-path="C:/Users/bugra/Downloads",--library-path="C:/Users/bugra/Downloads/Deney1.X",--library-path="C:/Program Files/MATLAB/R2023b/rtw/c/src",--library-path="C:/Program Files/MATLAB/R2023b/simulink/src",--library-path="C:/Program Files/MATLAB/R2023b/toolbox/simulink/blocks/src",--library-path="C:/Program Files/MATLAB/R2023b/extern/include",--library-path="C:/Program Files/MATLAB/R2023b/simulink/include",--library-path="C:/Program Files/MATLAB/R2023b/rtw/c/src/ext_mode/common",--library-path="C:/Program Files/MATLAB/R2023b/rtw/c/ert",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml,"--report-mem,-Map=info.map,-cref,-lq-dsp,--memorysummary,memoryfile.xml"$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/Deney1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Deney1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=0,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--stackguard=16,--library-path="C:/Users/bugra/Downloads",--library-path="C:/Users/bugra/Downloads/Deney1.X",--library-path="C:/Program Files/MATLAB/R2023b/rtw/c/src",--library-path="C:/Program Files/MATLAB/R2023b/simulink/src",--library-path="C:/Program Files/MATLAB/R2023b/toolbox/simulink/blocks/src",--library-path="C:/Program Files/MATLAB/R2023b/extern/include",--library-path="C:/Program Files/MATLAB/R2023b/simulink/include",--library-path="C:/Program Files/MATLAB/R2023b/rtw/c/src/ext_mode/common",--library-path="C:/Program Files/MATLAB/R2023b/rtw/c/ert",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml,"--report-mem,-Map=info.map,-cref,-lq-dsp,--memorysummary,memoryfile.xml"$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/Deney1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
