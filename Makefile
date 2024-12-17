TARGET = main #name of finall file

CXX = g++ #compilator
CXXFLAGS = -std=c++17 -Wall #parameters

INCLUDE_DIR = include
LIB_DIR = "C:/Program Files/MySQL/MySQL Connector C 6.1/lib" #directory to include and lib

LIBS = -lmysql #lib

SRC_FILES = src/main.cpp src/users.cpp src/books.cpp #cpp files

all: $(TARGET)

$(TARGET): #template
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $(SRC_FILES) -L$(LIB_DIR) $(LIBS) 

# clean
clean:
	del /f /q "src\main.o" main
	del /f /q "src\login.o" main
	del /f /q "main.exe" main
