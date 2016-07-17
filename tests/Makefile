include wrappers.mk

# extra flags to give to the C++ compiler
CXXFLAGS += --coverage -fprofile-arcs -ftest-coverage -fPIC -O0

# define any directories containing header files other than /usr/include
#INCLUDES  =

# extra flags to give to compilers when they are supposed to invoke the linker
#LDFLAGS =

# library flags or names given to compilers when they are supposed to invoke
# the linker
LDLIBS += -lgmock -lgtest -lpthread

LDFLAGS += $(WRAP_FLAGS)

TEST_SOURCES  = $(filter-out $(MAIN_FILE),$(SOURCES))
TEST_SOURCES += $(wildcard $(TEST_DIR)/*.cpp)

# define the program object files
OBJECTS = $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SOURCES:.cpp=.o)))

# define the executable
EXECUTABLE = $(BUILD_DIR)/app_test

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

# this is a suffix replacement rule for buildings .o's from .cpp's
# it uses automatic variables:
# $< - the name of the prerequisite of the rule (a .cpp file)
# $@ - the name of the target of the rule (a .o file)
# (see the GNU make manual section about automatic variables)
$(TEST_OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_OBJ_DIR)/%.o:$(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -v $(EXECUTABLE)
	$(RM) -v $(TEST_OBJ_DIR)/*.gcda

clean-obj:
	$(RM) -v $(OBJECTS)
