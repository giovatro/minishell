NAME			= minishell

PATH_SRC		= src
LIBFT			= libft/
LIBFT_A			= libft/libft.a

#HOME (MAC Silicon)
#INCLUDES_PATH	= -I/opt/homebrew/opt/readline/include
#LINK_PATH		= -L/opt/homebrew/opt/readline/lib

#SCHOOL (MAC Intel)
INCLUDES_PATH	= -I/usr/local/Cellar/readline/8.1.2/include
LINK_PATH		= -L/usr/local/Cellar/readline/8.1.2/lib

LINK_LIB		= -lreadline

SRCS			= $(shell find $(PATH_SRC) -name *.c)
INCS			= $(shell find $(PATH_SRC) -type d)

CC				= gcc

FLAGS			= -Wall -Wextra -Werror #-g #-fsanitize=address
FLAG_INC		= $(addprefix -I, $(INCS))

# Colour
RST				= "\033[0m"
R				= "\033[0;31m"
G				= "\033[0;32m"
Y				= "\033[0;33m"
B				= "\033[0;34m"
M				= "\033[0;35m"
C				= "\033[0;36m"
W				= "\033[0;37m"

.SILENT:

all:			$(NAME)

$(NAME):		
				make clean -C $(LIBFT)
				echo $(C)"Making Libft..."$(RST)
				make -C $(LIBFT)
				echo $(C)"Libft compiled"$(RST)
				echo $(C)"Making Minishell..."$(RST)
				gcc -o $(NAME) $(FLAGS) $(FLAG_INC) $(SRCS) $(LIBFT_A) $(INCLUDES_PATH) $(LINK_PATH) $(LINK_LIB)
				make clean -C $(LIBFT)
				echo $(C)"Minishell compiled"$(RST)
				echo $(G)"\nLauch: ./minishell\n"$(RST)

clean:
				echo $(R)"Cleaning..."$(RST)
				make -C $(LIBFT) clean
				echo $(R)"Cleaned"$(RST)

fclean:			clean
				rm -rf $(NAME)
				make -C $(LIBFT) fclean
				echo $(R)"Removed everything"$(RST)

re:				fclean all

.PHONY:			all clean fclean re
