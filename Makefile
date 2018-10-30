CC = /usr/bin/clang++
RM = /bin/rm
MAKE = /usr/bin/make
MKDIR = /bin/mkdir

NAME = logl

ROOT = 		$(shell /bin/pwd)
OBJPATH = 	$(ROOT)/obj
SRCPATH = 	$(ROOT)/src

FLAGS = -Wall -Wextra -Werror
INCL = -I lib/glfw3/include -I lib/glad -I lib/glm -I lib/stb_image -I include
LIB = -L ./lib/glfw3 -lglfw3 -framework AppKit -framework IOKit -framework CoreVideo

SRC = glad.cpp\
		stb_image.cpp\
		main.cpp\
		init.cpp\
		event.cpp\
		Shader.cpp\
		Camera.cpp\

OBJ = $(patsubst %.cpp, $(OBJPATH)/%.opp, $(SRC))


all: $(OBJPATH) $(NAME)

$(OBJPATH):
	@echo "Creating OBJ directory"
	@$(MKDIR) $@

$(NAME): $(OBJ)
	@echo "Creating OBJ files"
	@echo "Building $@"
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(INCL) $(LIB)
	@echo "\033[36mAll is done!\033[0m"

$(OBJPATH)/%.opp: $(SRCPATH)/%.cpp
	@$(CC) -c $< -o $@ $(FLAGS) $(INCL)

clean:
	@echo "Deleting OBJ files"
	@$(RM) -rf $(OBJPATH)

fclean : clean
	@echo "Deleting logl binary"
	@$(RM) -f $(NAME)

re : fclean all

# little memo
# $@ = rule's name
# $^ = all the rule dependecies
# $< = only the first dependence
# -j 8 => pour que la lib complie en multi thread ;)


# Color for c
#   reset	"\033[0m"
#   RED  	"\033[31m"
#   GRN  	"\033[32m"
#   YEL  	"\033[33m"
#   BLU  	"\033[34m"
#   MAG  	"\033[35m"
#   CYN  	"\033[36m"
#   WHT  	"\033[37m"
