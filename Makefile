# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 18:39:56 by mqueguin          #+#    #+#              #
#    Updated: 2021/02/12 19:40:02 by mqueguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
##############
##  COLORS  ##
##############
END		=	\x1b[0m
BOLD	=	\x1b[1m
UNDER	=	\x1b[4m
RED		=	\x1b[31m
GREEN	=	\x1b[32m
YELLOW	=	\x1b[33m
BLUE	=	\x1b[34m
PURPLE	=	\x1b[35m
CYAN	=	\x1b[36m
WHITE	=	\x1b[37m


OBJ_DIR 	=	obj/

SRC_DIR 	=	srcs/

LIB_DIR 	=	libft/

PRINTF_H	=	-I includes/ft_printf.h

LIBFT_H		= 	-I libft/libft.h

SRCS	 	=	ft_printf.c\
				ft_printf_utils.c\
				ft_treat_char.c\
				ft_treat_string.c\
				ft_treat_pointer.c\
				ft_itoa_base_ull.c\
				ft_treat_int.c\
				ft_treat_u_int.c\
				ft_treat_hexa.c\

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
		@echo "\t\t$(BOLD)====================== $(GREEN)LIBFT START $(END)$(BOLD)====================$(END)\t\t"
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@cat text.txt
		@echo "\033[33;32m\t\t\t\t\tFT_PRINTF COMPLETE"

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(CC) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo "Cleaned ft_printf object files"

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@cat text2.txt
		@echo "$(BOLD)$(RED)\t\t\t-_-_-_-_-_-_-_-_-_-_ Cleaned $(NAME) _-_-_-_-_-_-_-_-_-_-$(END)"

re: fclean all

.PHONY: all clean flcean re
