CXX := g++
INCLUDE := \
-I./include/cargo \
-I./include/item \
-I./include/util \
-I./include/

VERSION := 0.0.0

SOURCE := $(shell find src -name "*.cpp")


wms:
	$(CXX) $(INCLUDE) $(SOURCE) main-cli.cpp -o robert-wms

test-wms:
	$(CXX) $(INCLUDE) $(SOURCE) test.cpp -o test-wms
