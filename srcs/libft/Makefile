SRC_FILES		=	ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_putstr_fd.c \
					ft_isinstring.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstadd_back.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \
					get_next_line.c \
					get_next_line_utils.c \
					ft_printf.c \
					ft_printfuncs.c \
					ft_printfuncs_2.c \
					ft_fprintf.c \
					ft_fprintfuncs.c \
					ft_fprintfuncs_2.c \
					ft_uitoa.c \

SRC_DIR			=	srcs/

SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES		=	$(SRC_FILES:.c=.o)

OBJ_DIR			=	objects/

OBJS			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

INCS			=	-Iincludes/

PLAIN			=	\033[0m
GREEN_B			=	\033[1;32m

CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -c
AR				=	ar -rcs

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(AR) $(NAME) $(OBJS)
				@echo "$(GREEN_B)libft created$(PLAIN)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(INCS) -o $@ $<

$(OBJ_DIR):
				@mkdir $@

clean:
				@$(RM) $(OBJ_DIR)

fclean:			clean
				@$(RM) $(NAME)

re:			fclean $(OBJ_DIR) all

.PHONY:			all clean fclean re
