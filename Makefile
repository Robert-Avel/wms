CXX := g++
INCLUDE := \
-I./include/cargo \
-I./include/item \
-I./include/util

VERSION := 0.0.0

SOURCE := $(shell find src -name "*.cpp")


wms:
	$(CXX) $(INCLUDE) $(SOURCE) main.cpp -o robert-wms

test-wms:
	$(CXX) $(INCLUDE) $(SOURCE) test.cpp -o test-wms
