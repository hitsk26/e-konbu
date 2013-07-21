# Target specific macros
TARGET = Strange_Lovers

NXTOSEK_ROOT = /cygdrive/c/cygwin/nxtOSEK

# nxtway_gs_balancer library desiged for NXTway-GS two wheeled self-balancing robot
USER_INC_PATH= $(NXTOSEK_ROOT)/ecrobot/nxtway_gs_balancer
USER_LIB = nxtway_gs_balancer

# using NXT standard tires (not Motorcycle tires)
#USER_DEF = NXT_STD_TIRE
DRIVENPART_SOURCES := 
# User application source
TARGET_SOURCES := \
	balancer_param.c \
	TargetValue.c \
	Runner.c \
	Calibration.c \
	Display.c \
	logSend.c \
	./DrivenPart/PID_Tail.c \
	./HardwareWrapper/TouchSensor.c \
	./HardwareWrapper/Motor.c \
	./HardwareWrapper/SystemTimer.c \
	./HardwareWrapper/GyroSensor.c \
	./HardwareWrapper/LightSensor.c \
	./UI/PushButton.c \
	./DetectorPart/Timer.c \
	./DetectorPart/DistanceEncoder.c \
	./DetectorPart/SpeedEncoder.c \
	./DetectorPart/InclinationEncoder.c \
	./DetectorPart/BrightnessEncoder.c \
	./DetectorPart/DirectionEncoder.c \
	./DrivenPart/WheelMotor.c \
	./DrivenPart/TailMotor.c \
	./DrivenPart/Balancer.c \
	./DrivenPart/PID_Brightness.c \
	./DrivenPart/TargetSpeedControl/SpeedCtrl.c \
	./DrivenPart/TargetSpeedControl/Speed.c \
	./DrivenPart/TargetSpeedControl/PIDSpeedCtrl.c \
	./DrivenPart/TargetSpeedControl/PIDSpeedCtrlParm.c \
	model_impl.c \
	Factory.c

TOPPERS_OSEK_OIL_SOURCE := ./prog.oil

O_PATH ?= build

include $(NXTOSEK_ROOT)/ecrobot/lejos_osek.tmf

