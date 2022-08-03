NAME		=	minishell

SRCS		=	main.c get_next_line.c \

# SRCS_BONUS	=	

BONUS_OBJS	=	$(SRCS_BONUS:.c=.o)

OBJS		=	$(SRCS:.c=.o)

HEADER		=	minishell.h 

CFLAGS		=	#-Werror -Wall -Wextra

CC			=	gcc

LIBFT		=	./libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'

%.o : %.c	$(HEADER)
			$(CC) $(CFLAGS) -lreadline -c $< -o ${<:.c=.o}

all: $(NAME)


$(NAME): $(OBJS) $(LIBFT)
		$(CC) -g $(OBJS) ${LIBFT} -lreadline -o  $(NAME)

$(LIBFT):
		make -C ./libft

clean:
	rm -rf $(OBJS) 

fclean: clean
	rm -rf $(NAME)

re: clean all 

bonus:  $(BONUS_OBJS) $(LIBFT)
		ar rc $(NAME) $(BONUS_OBJS)

.PHONY: all, clean, fclean, re

norm:
		@norminette ${SRCS} ${SRCS_BONUS} ${HEADER}
		@printf ${GREEN}${CURSIVE}"Norm ok\n"${NONE}