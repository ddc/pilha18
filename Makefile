#  Makefile for building C/C++ Daniel applications
#	Author: Daniel Dourado da Costa
#	e-mail: danieldouradocosta@gmail.com
#	UFG - Universidade Federal de Goias
#	May 2015
#	Copyright 2015 Daniel Dourado da Costa. All rights reserved.
###### flags
# -std=c99 = variable decorations inside loops (only on c)
# When you need to debug, use -O0 (and -g to generate debugging symbols.)
# When you are preparing to ship it, use -O2.
# When you use gentoo, use -O3...!
# When you need to put it on an embedded system, use -Os (optimize for size, not for efficiency.)

TARGETS=main

CROSS_TOOL =
CC_PP = $(CROSS_TOOL)g++
CC_C = $(CROSS_TOOL)gcc

CFLAGS = -Wall -Werror -g -std=c99
CPPFLAGSOPT = -Wall -Werror -g -O2
CPPFLAGS = -Wall -Werror -g

all: clean $(TARGETS)

$(TARGETS):
		#$(CC_C) $(CFLAGS) $@.c -o $@
		#$(CC_PP) $(CPPFLAGSOPT) $@.cpp -o $@
		$(CC_PP) $(CPPFLAGS) *.cpp -o $@
		
clean:
		rm -rf $(TARGETS)


