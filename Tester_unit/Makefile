# https://misc.flogisoft.com/bash/tip_colors_and_formatting
_BOLD      =\e[1m
_DIM       =\e[2m
_UNDERLINE =\e[4m
_BLINK     =\e[5m
_REVERSE   =\e[7m
_HIDDEN    =\e[8m

# RESET list
_R          =\e[0m
_RBOLD      =\e[21m
_RDIM       =\e[22m
_RUNDERLINE =\e[24m
_RBLINK     =\e[25m
_RREVERSE   =\e[27m
_RHIDDEN    =\e[28m

# Colors
_RED      =\e[91m
_GREEN    =\e[92m
_YELLOW   =\e[93m
_BLUE     =\e[94m
_MAGENTA  =\e[35m
_CYAN     =\e[96m
_WHITE    =\e[97m

# Inverted, i.e. colored backgrounds
_IRED     =\e[101m
_IGREEN   =\e[102m
_IYELLOW  =\e[103m
_IBLUE    =\e[104m
_IMAGENTA =\e[45m
_ICYAN    =\e[106m
_IWHITE   =\e[107m

UNAME := $(shell uname)

NAME = tests

SRC_DIR = ./src 
BUILD_DIR = ./build
INC_DIR = $(shell find . -type d -name "includes")
INC_DIR+= $(shell find ../vector -type d)
INC_DIR+= $(shell find ../utils -type d )
INC_DIR+= $(shell find ../stack -type d )
INC_DIR+= $(shell find ../map -type d )

OBJ_DIR = obj

SRCS_DIR = $(shell find $(SRC_DIR) -type d)

vpath %.hpp $(INC_DIR)

# Unit test framework source code
SRC = main.cpp

# Our tests
SRC+= TestsVector.cpp TestsStack.cpp TestsMap.cpp


OBJ = $(addprefix  $(OBJ_DIR)/,$(SRC:%.cpp=%.o))
vpath %.cpp $(SRCS_DIR)

DEP = $(addprefix  $(OBJ_DIR)/,$(SRC:%.cpp=%.d))


LDFLAGS = $(foreach lib, $(LIB_DIR),-L$(lib))  $(foreach lib, $(LIB),-l$(lib))

CXX = clang++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++17 -MMD -MP -g -fstandalone-debug #-fsanitize=address  -fsanitize=undefined -fstack-protector  
IFLAGS  = $(foreach inc, $(INC_DIR),-I$(inc))

#OS specific
ifeq ($(UNAME), Darwin)
	# mac
	CXXFLAGS += -D DARWIN
else
	#Linus and others...
	CXXFLAGS += -D LINUX
endif

ifeq ($(strip $(NS_NAME)),)
NS_NAME := ft
endif
CXXFLAGS += -D NS_NAME=$(NS_NAME)

all:  $(BUILD_DIR)/$(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

$(BUILD_DIR)/$(NAME): $(OBJ)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(IFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf "$(_GREEN)Compiled : $(_MAGENTA)$(NAME)$(_R)\n"

run:  $(BUILD_DIR)/$(NAME)
	@./$(NAME)

clean:
	@rm -rf $(OBJ_DIR) output_valgrind
	@printf "$(_RED)Removed :$(_MAGENTA) $(OBJ_DIR)/$(_MAGENTA)\n"

fclean: clean
	@rm -fr $(BUILD_DIR)/ $(NAME).dSYM/
	@printf "$(_RED)Removed : $(_MAGENTA)./$(NAME), $(NAME).dSYM/$(_R)\n"

check: $(BUILD_DIR)/$(NAME)
	@$(BUILD_DIR)/$(NAME) $(ARGS)

re: fclean all

-include $(DEP)

.PHONY: all run debug valgrind show clean fclean check re