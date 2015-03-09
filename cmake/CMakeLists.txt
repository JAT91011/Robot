CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 
PROJECT(Robot)
add_executable(Robot Robot.cc QTRSensors/QTRSensors.cc SPI/SPIUtils.cc Chassis/Chassis.cc)