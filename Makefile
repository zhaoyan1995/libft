# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 18:06:51 by yanzhao           #+#    #+#              #
#    Updated: 2025/05/04 19:16:58 by yanzhao          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

PART_I=ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_isprint.c  ft_strlen.c  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_tolower.c ft_toupper.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c

PART_II=ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRCS=$(PART_I) $(PART_II)

SRCS_BONUS=$(BONUS)

OBJS=$(SRCS:.c=.o)

OBJS_BONUS=$(SRCS_BONUS:.c=.o)

CC=cc -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $^

bonus:$(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $^

%.o:%.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re bonus
