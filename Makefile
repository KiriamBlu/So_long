NAME := so_long
LIBFT_NAME = libft.a

SRCS =  ./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		./sources/main.c \
		./sources/parser.c \
		./sources/parser2.c \
		./sources/drawmap.c \
		./sources/enemymoves.c

OBJS = ${SRCS:.c=.o}

LIBFT_DIR := ./libft/
INC_DIR := ./includes/

MINILIB	= -L mlx -l mlx -framework OpenGL -framework AppKit
CC := cc
GCC := gcc
CFLAGS := -Wall -Wextra #-Werror  
MV := mv -f
RM := rm -f

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -I $(INC_DIR) -o $@ 

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
	make -C ./mlx
	gcc $(OBJS) $(MINILIB) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME)

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re