# Using Automatic Variables
# written by Stewart Weiss
# Feb. 4, 2012
# 
# make has a special feature called automatic variables. The values of automatic 
# variables are computed again for each rule that make executes, based on the 
# target and prerequisites of the rule. They are mostly used when you make your
# own "pattern rules" like the ones make uses as implicit rules, but they can
# also be useful in your ordinary rules.
# 
# Automatic variables only have values within the recipe of a rule, not within
# the target list or its prerequisites. They will expand to the empty string if
# used outside the recipe.
# 
# This makefile shows a few handy automatic variables and ways to use them.
# 
#   $@  is the full name of the current target. 
#   $?  is the list of prerequisites for the current target that are newer than
#       the target, with spaces between them.
#   $<  is the name of the first prerequisite. If the target got its recipe 
#       from an implicit rule, this is the first prerequisite added by the 
#       implicit rule. 

INSTALLDIR := ../bin
CC         := /usr/bin/gcc
CFLAGS     += -W -g
OBJECTS    := main.o utils.o interface.o

# This rule says to name the executable whatever the name of the target is,
# and to compile using all of the prerequisites. The second part of the recipe
# prints a list of the object files that forced demo to be rebuilt. The "@"
# preceding the echo command tells make to execute the command without
# echoing it, which is what make does by default.
demo: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
	@ echo Changed files: $?

main.o:  utils.h interface.h
utils.o: utils.h defs.h
interface.o: interface.h defs.h

.PHONY: clean 
clean:
	$(RM) $(OBJECTS) 

install: demo
	@ if [ ! -d $(INSTALLDIR) ] ; then mkdir $(INSTALLDIR) ; fi
	\cp demo $(INSTALLDIR)
	@ touch install

# This rule also uses the $? variable. It prints only those source files
# that have changed since the last time anything was printed. It uses the lpr
# command to send plain text to the default printer.
print: *.c *.h
	lpr -p $? 
	@ touch print

