export PROJECT_DIR = $(shell "pwd")
export BUILD_DIR = $(PROJECT_DIR)/build
export TEST_DIR = $(PROJECT_DIR)/tests
export TEST_OBJ_DIR = $(PROJECT_DIR)/obj/tests
export SRC_DIR = $(PROJECT_DIR)/src
export SRC_OBJ_DIR = $(PROJECT_DIR)/obj/src

# extra flags to give to the C++ compiler
ifdef RELEASE
CXXFLAGS = -O2
else
CXXFLAGS = -g
endif

export CXXFLAGS += -Wall -Wextra -Wpedantic -std=c++11

# define any directories containing header files other than /usr/include
export INCLUDES  =

# extra flags to give to compilers when they are supposed to invoke the linker
export LDFLAGS =

# library flags or names given to compilers when they are supposed to invoke
# the linker
export LDLIBS = -lcurl

# define main file to be excluded by test
export MAIN_FILE = $(SRC_DIR)/main.cpp

# define the program source files
export SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# define the program object files
OBJECTS = $(addprefix $(SRC_OBJ_DIR)/, $(notdir $(SOURCES:.cpp=.o)))

# define the executable
EXECUTABLE = $(BUILD_DIR)/app

.PHONY: all test clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

test:
	@$(MAKE) -C tests

# this is a suffix replacement rule for buildings .o's from .cpp's
# it uses automatic variables:
# $< - the name of the prerequisite of the rule (a .cpp file)
# $@ - the name of the target of the rule (a .o file)
# (see the GNU make manual section about automatic variables)
$(SRC_OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean-all: clean clean-obj

clean:
	$(RM) -v $(EXECUTABLE)
	@$(MAKE) clean -C tests

clean-obj:
	$(RM) -v $(OBJECTS)
	@$(MAKE) clean-obj -C tests
