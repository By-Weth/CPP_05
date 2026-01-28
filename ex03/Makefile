# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 11:05:48 by mpascoal          #+#    #+#              #
#    Updated: 2026/01/20 11:05:49 by mpascoal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
      Bureaucrat.cpp \
      AForm.cpp \
      ShrubberyCreationForm.cpp \
      RobotomyRequestForm.cpp \
      PresidentialPardonForm.cpp \
      Intern.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = Bureaucrat.hpp \
         AForm.hpp \
         ShrubberyCreationForm.hpp \
         RobotomyRequestForm.hpp \
         PresidentialPardonForm.hpp \
         Intern.hpp

all: $(NAME)

$(OBJ): $(HEADER)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re