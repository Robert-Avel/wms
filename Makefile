CXX := g++
INCLUDE := \
-I./include/cargo \
-I./include/item \
-I./include/util \
-I./include/

CFLAGS := -Wall

VERSION := 0.0.0

SOURCE := $(shell find src -name "*.cpp")



wms:
	$(CXX) $(CFLAGS) $(INCLUDE) $(SOURCE) main-cli.cpp -o robert-wms

wms-debug:
	$(CXX) $(CFLAGS) $(INCLUDE) $(SOURCE) main-cli.cpp -o robert-wms -DDEBUG -g

test-wms:
	$(CXX) $(CFLAGS) $(INCLUDE) $(SOURCE) test.cpp -o test-wms -g
