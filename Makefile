###############
## Variables ##
###############

NAME		=	libunit.a

VPATH		=	src
OBJDIR		=	obj
INCLDIR		=	incld

SRC			=	print.c \
				register.c \
				assert.c \
				flag.c \
				memory.c \
				suite.c \
				utils.c \
				run.c \
				time.c
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCFLAGS	=	-I./$(INCLDIR)
RM			=	/bin/rm -rf
AR			=	ar
ARFLAGS		=	rcs
UNAME		:=	$(shell uname -s)


###########
## Rules ##
###########

.PHONY:			all clean debug fclean re

all:			$(NAME)

$(OBJDIR)/%.o:	%.c | $(OBJDIR)
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
				$(AR) $(ARFLAGS) $@ $^

$(OBJDIR):
				mkdir $(OBJDIR)

debug:			CFLAGS += -fsanitize=address -g3
debug:			re

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME) $(OBJDIR)

re:				fclean all