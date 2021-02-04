# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 18:39:56 by mqueguin          #+#    #+#              #
#    Updated: 2021/02/04 12:00:38 by mqueguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR 	=	obj/

SRC_DIR 	=

LIB_DIR 	=	libft/

PRINTF_H	=	-I ft_printf.h

LIBFT_H		= 	-I libft/libft.h

SRCS	 	=	ft_printf.c\
				ft_treat_char.c\
				ft_treat_string.c\
				ft_printf_utils.c\
				ft_printf_debug.c\
				ft_treat_width.c\
				ft_treat_flags.c\
				ft_strncat.c\
				ft_c_to_str.c

NAME 		=	libftprintf.a

LIBFT_A 	=	libft.a

CC			=	gcc  $(PRINTF_H) $(LIBFT_H) -c -o

CFIND		=	$(SRCS:%=$(SRC_DIR)%)

OFILE		=		$(SRCS:%.c=%.o)

OBJ			=		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory

$(NAME): $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(CC) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean flcean re
