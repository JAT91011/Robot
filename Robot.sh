#!/bin/bash
echo "Compiling..."
g++ -o Robot Robot.cc Chassis/Chassis.cc QTRSensors/QTRSensors.cc SPI/SPIUtils.cc -lwiringPi -std=c++11
echo "Compilation finished!"