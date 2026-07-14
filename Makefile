CXX := g++
INCLUDE := \
-I./include/cargo \
-I./include/item \
-I./include/util

VERSION := 0.0.0

SOURCE := $(shell find src -name "*.cpp")


wms:
	$(CXX) (INCLUDE) (SOURCE) -o robert-wms
