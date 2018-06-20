#
# AUTO-GENERATED Makefile; do not edit, changes will be lost
#

# Define target type
TARGET:=wp85

# Custom makefile include: initialization
-include ../customInit.mk

# Only when not cleaning
ifneq ($(MAKECMDGOALS),clean)
# Load default PA definitions from main Legato Makefile
$(shell grep 'export PA_DIR .*' $(LEGATO_ROOT)/Makefile > legatoDefs.mk)
$(shell grep 'export .*_PA_.* .*' $(LEGATO_ROOT)/Makefile >> legatoDefs.mk)
-include legatoDefs.mk

# Default targets definitions from Framework
-include targetDefs.$(TARGET)
endif

# Target artifact.*
TARGET_ARTIFACT:=COW.$(TARGET).update

# Clean command
CLEANCOMMAND:=find -maxdepth 1 -mindepth 1 ! -name Makefile ! -name .rsync-rules -exec rm -R {} \;

# MK command
MKCOMMAND:=cd ..;mkapp -t $(TARGET) -o Target_Legato_Debug -w Target_Legato_Debug -i "$(LEGATO_ROOT)/interfaces/modemServices" -i "$(LEGATO_ROOT)/interfaces/supervisor" -i "$(LEGATO_ROOT)/interfaces/airVantage" -i "$(LEGATO_ROOT)/interfaces/secureStorage" -i "$(LEGATO_ROOT)/interfaces/logDaemon" -i "COWComponent/curl" -i "$(LEGATO_ROOT)/interfaces" -i "$(LEGATO_ROOT)/interfaces/atServices" -i "$(LEGATO_ROOT)/interfaces/positioning" -i "$(LEGATO_ROOT)/interfaces/wifi" -s "$(LEGATO_ROOT)/components/fwupdate/platformAdaptor/default" -s "$(LEGATO_ROOT)/modules/WiFi/service" -s "$(LEGATO_ROOT)/components/airVantage/platformAdaptor/default" -s "$(LEGATO_ROOT)/components/fwupdate" -s "$(LEGATO_ROOT)/components/airVantage" -s "$(LEGATO_ROOT)/modules/WiFi/apps/tools/wifi" -s "$(LEGATO_ROOT)/components/positioning/platformAdaptor/default" -s "$(LEGATO_ROOT)/components/positioning" -s "$(LEGATO_ROOT)/components/devMode" -s "$(LEGATO_ROOT)/components/secStore/platformAdaptor/default" -s "$(LEGATO_ROOT)/components/secStore" -s "." -s "$(LEGATO_ROOT)/components/uartMode/platformAdaptor/default" -s "$(LEGATO_ROOT)/components/modemServices/platformAdaptor/default" -s "$(LEGATO_ROOT)/components/modemServices" -s "$(LEGATO_ROOT)/components/atServices" -s "$(LEGATO_ROOT)/components" -s "$(LEGATO_ROOT)/components/uartMode" -s "$(LEGATO_ROOT)/components/audio/platformAdaptor/default" -s "$(LEGATO_ROOT)/apps/tools" -C -g -X -g -L -g -L -Wl,-rpath=/COW/COWComponent/libcurl -L -L/COW/COWComponent/libcurl -L -l:libcurl.so.5 COW.adef

# Custom makefile include: definitions
-include ../customDefs.mk

.PHONY: all target clean codegen mkCodegen  airvantage

all: target

codegen: mkCodegen

mkCodegen:
	$(MKCOMMAND) --generate-code

target:
	$(MKCOMMAND)



clean:
	$(CLEANCOMMAND)


# Custom makefile include: targets
-include ../customTargets.mk
