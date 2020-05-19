################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cliente.c \
../src/clientepublicacion.c \
../src/main.c \
../src/publicacion.c \
../src/userinteractions.c 

OBJS += \
./src/cliente.o \
./src/clientepublicacion.o \
./src/main.o \
./src/publicacion.o \
./src/userinteractions.o 

C_DEPS += \
./src/cliente.d \
./src/clientepublicacion.d \
./src/main.d \
./src/publicacion.d \
./src/userinteractions.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


