CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 
PROJECT(Robot)
add_executable(Robot Robot.cc QTRSensors/QTRSensors.cc SPI/SPIUtils.cc Dagu/Dagu.cc)