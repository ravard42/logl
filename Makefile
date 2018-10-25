CC = g++
NAME = logl
FLAGS = -Wall -Wextra -Werror
SRC = lib/glad/src/glad.cpp\
		src/main.cpp\
		src/init.cpp\
		src/event.cpp\
		src/Shader.cpp\
		src/stb_image.cpp\

OBJ = $(SRC:.cpp=.opp)

INCL = -I lib/glfw3/include -I lib/glad/include -I include
LIB = -L ./lib/glfw3 -lglfw3 -framework AppKit -framework IOKit -framework CoreVideo

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(INCL) $(LIB)

%.opp : %.cpp
	$(CC) -o $@ -c $< $(FLAGS) $(INCL)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
