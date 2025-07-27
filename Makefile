# To use this file, you will only need to setup the first three sections and simply run "make".

# Compiler and Flags
CXX ?= g++
CXXFLAGS = $(WARNINGS) -std=$(STANDARD) -O2
STANDARD = c++17
WARNINGS = -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2

# Directories
SRC_DIR = .
HDR_DIR = .
BUILD_DIR = build
INSTALLDIR = ~/bin/

# Executable name
TARGET = myProject

###############################
# END OF FIRST THREE SEGMENTS #
###############################

# Define pseudotargets
.PHONY: target install clean cleanall help

# Source, Header and Object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
HDRS = $(wildcard $(HDR_DIR)/*.hpp) $(wildcard $(HDR_DIR)/*.h)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Defaulttarget
target: $(TARGET)

# Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRS) | $(BUILD_DIR) msgcompile
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link
$(TARGET): $(OBJS)
	@echo "\n\033[1;36mLinking:\033[0m"
	$(CXX) $^ -o $@ $(LDFLAGS)
	@echo "\033[1;32mDONE BUILDING EXECUTABLE\033[0m"

# Make the build directory if needed
$(BUILD_DIR):
	@echo "\n\033[1;36mMaking build directory:\033[0m"
	mkdir -p $(BUILD_DIR)

# Install target
install: $(TARGET)
	@echo "\n\033[1;36mInstalling $(TARGET) at $(INSTALLDIR):\033[0m"
	@cp -fv $(TARGET) $(INSTALLDIR) || sudo mv -iv $(TARGET) $(INSTALLDIR)

# Clean Object files
clean:
	@echo "\n\033[1;36mRemoving object files and build directory:\033[0m"
	@rm -rfv $(BUILD_DIR)

# Clean out file and objects
cleanall: clean
	@echo "\n\033[1;36mRemoving executable:\033[0m"
	@rm -rfv $(TARGET)

# help target
help:
	@echo
	@echo "The following are the valid targets for this Makefile:"
	@echo "... \033[1mtarget\033[0m       make the executable"
	@echo "... \033[1minstall\033[0m      make and move the executable to $(INSTALLDIR)"
	@echo "... \033[1mclean\033[0m        removes the build directory and its contents like object files"
	@echo "... \033[1mcleanall\033[0m     removes all of the above and also the executable inside this folder"
	@echo
	@echo "also the following are valid targets:"
	@echo "\033[1m$(OBJS)\033[0m"


# Message targets
msgcompile:
	@echo "\n\033[1;36mCompiling:\033[0m"
.PHONY: msgcompile