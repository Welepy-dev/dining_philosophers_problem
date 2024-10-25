# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 12:16:14 by marcsilv          #+#    #+#              #
#    Updated: 2024/10/25 17:07:14 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

# Set the output binary name
OUTPUT = program

# Find all .c files in the current directory and subdirectories
SRCS := $(shell find . -name '*.c')

# Default target: compile and link all .c files
all: $(OUTPUT)

# Compile target
$(OUTPUT): $(SRCS)
	@gcc -pthread $(SRCS) -o $(OUTPUT)
	@echo "Compilation finished! Use 'make run' to execute."

# Run target
run: $(OUTPUT)
	@./$(OUTPUT) 1 60 60 60 3 

# Clean up target
clean:
	@rm -f $(OUTPUT)
	@echo "Cleaned up!"

# Phony targets so they are always executed
.PHONY: all run clean
