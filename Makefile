CXX := g++
INCLUDE := \
-Iinclude/component \
-Iinclude/systens \
-Iinclude/util \
-Iinclude/data \
-Iinclude/


CFLAGS := -Wall


SOURCE := $(shell find src -name "*.cpp")

DEPENDENCE := -lsqlite3

dbuild:
	mkdir -p build

wms: dbuild
	$(CXX) $(CFLAGS) $(INCLUDE) $(SOURCE) $(DEPENDENCE) main-cli.cpp -o build/robert-wms

wms-debug: dbuild
	$(CXX) $(CFLAGS) $(INCLUDE) $(SOURCE) $(DEPENDENCE) main-cli.cpp -o build/robert-wms -DDEBUG -g

test-wms: dbuild
	$(CXX) $(CFLAGS) $(INCLUDE) $(SOURCE) $(DEPENDENCE) test.cpp -o build/test-wms -g
