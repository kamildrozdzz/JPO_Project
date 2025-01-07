TARGET = main # name of final file

CXX = g++ # compilator
CXXFLAGS = -std=c++17 -Wall # parameters

INCLUDE_DIR = include
SRC_FILES = src/main.cpp src/user.cpp src/book.cpp src/database.cpp # cpp files

LIB_DIR = lib
LIBS = -lmysql

# Default target
all: $(SUBMODULE_LIB) $(TARGET)

# Build main target
$(TARGET):
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -I$(LIB_DIR)/include -o $@ $(SRC_FILES) -L$(LIB_DIR) $(LIBS)

# Clean
clean:
	del /f /q "main.exe" main
