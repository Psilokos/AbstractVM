##
## Makefile for abstractVM in /home/lecouv_v/rendu/abstractVM
##
## Made by Victorien LE COUVIOUR--TUFFET
## Login   <lecouv_v@epitech.eu>
##
## Started on  Thu Jul 14 17:27:34 2016 Victorien LE COUVIOUR--TUFFET
## Last update Mon Aug  1 19:03:22 2016 Victorien LE COUVIOUR--TUFFET
##

CXX			= g++

NAME			= abstractVM

CXXFLAGS		+= -W -Wall -Werror -Wextra
CXXFLAGS		+= -I inc/ -I inc/components/ -I inc/subroutines/ -I inc/operands/
CXXFLAGS		+= -std=c++11
LDFLAGS			=

DIR_SRC			= src/
DIR_SRC_COMPONENTS	= $(DIR_SRC)components/
DIR_SRC_SUBROUTINES	= $(DIR_SRC)subroutines/
DIR_SRC_OPERANDS	= $(DIR_SRC)operands/

SRCS			= $(DIR_SRC)main.cpp		\
			  $(DIR_SRC)App.cpp		\
			  $(DIR_SRC)AOperand.cpp	\
			  $(DIR_SRC)ASubroutine.cpp	\
			  $(DIR_SRC)Factory.cpp		\
			  $(DIR_SRC)Parse.cpp		\
			  $(DIR_SRC)ToolBox.cpp		\
			  $(DIR_SRC)VirtualMachine.cpp

SRCS_COMPONENTS		= $(DIR_SRC_COMPONENTS)Chipset.cpp	\
			  $(DIR_SRC_COMPONENTS)CPU.cpp		\
			  $(DIR_SRC_COMPONENTS)IO.cpp		\
			  $(DIR_SRC_COMPONENTS)MMU.cpp

SRCS_SUBROUTINES	= $(DIR_SRC_SUBROUTINES)Assert.cpp	\
			  $(DIR_SRC_SUBROUTINES)Clear.cpp	\
			  $(DIR_SRC_SUBROUTINES)Dump.cpp	\
			  $(DIR_SRC_SUBROUTINES)Dup.cpp		\
			  $(DIR_SRC_SUBROUTINES)Exit.cpp	\
			  $(DIR_SRC_SUBROUTINES)Load.cpp	\
			  $(DIR_SRC_SUBROUTINES)Operation.cpp	\
			  $(DIR_SRC_SUBROUTINES)Pop.cpp		\
			  $(DIR_SRC_SUBROUTINES)Print.cpp	\
			  $(DIR_SRC_SUBROUTINES)Push.cpp	\
			  $(DIR_SRC_SUBROUTINES)Store.cpp	\
			  $(DIR_SRC_SUBROUTINES)Swap.cpp

SRCS_OPERANDS		= $(DIR_SRC_OPERANDS)Int8.cpp		\
			  $(DIR_SRC_OPERANDS)Int16.cpp		\
			  $(DIR_SRC_OPERANDS)Int32.cpp		\
			  $(DIR_SRC_OPERANDS)Float.cpp		\
			  $(DIR_SRC_OPERANDS)Double.cpp		\
			  $(DIR_SRC_OPERANDS)BigDecimal.cpp	\


OBJS			= $(SRCS:.cpp=.o)
OBJS_COMPONENTS		= $(SRCS_COMPONENTS:.cpp=.o)
OBJS_SUBROUTINES	= $(SRCS_SUBROUTINES:.cpp=.o)
OBJS_OPERANDS		= $(SRCS_OPERANDS:.cpp=.o)

RM			= rm -f
PRINTF			= @printf

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJS_COMPONENTS) $(OBJS_SUBROUTINES) $(OBJS_OPERANDS)
		$(CXX) $(OBJS) $(OBJS_COMPONENTS) $(OBJS_SUBROUTINES) $(OBJS_OPERANDS) -o $@ $(LDFLAGS)
		$(PRINTF) '\033[1;32m> Compiled\033[0m\n'

clean:
		$(RM) $(OBJS) $(OBJS_COMPONENTS) $(OBJS_SUBROUTINES) $(OBJS_OPERANDS)
		$(PRINTF) '\033[1;35m> Directory cleaned\033[0m\n'

fclean:		clean
		$(RM) $(NAME)
		$(PRINTF) '\033[1;35m> Remove binary\033[0m\n'

re:		fclean all

.PHONY:		all clean fclean re
