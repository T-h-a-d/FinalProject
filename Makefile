##########################################################################################
## Final Project: Jail Escape
## Author: Thad Sauter
## Date: 12/5/17
## Description: Makefile for CS 162 Final Project. Use ./JailEscape to run
##########################################################################################

CC := g++ 
SRCDIR := src
BUILDDIR := build
TARGET := JailEscape

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT)) 
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -std=c++11
INC := -I include 

$(TARGET): $(OBJECTS)
		$(CC) $(CFLAGS) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) 
		@mkdir -p $(BUILDDIR)
		$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
		$(RM) -r $(BUILDDIR) $(TARGET)




##JailEscape: Item.o Guard_Radio.o Gun.o Backpack.o Jail_Escape_Main.o  Menu.o Utility_Functions.o 
#		g++ -std=c++11 Item.o Guard_Radio.o Gun.o Backpack.o Jail_Escape_Main.o Menu.o Utility_Functions.o -o JailEscape

#Item.o:
#		g++ -std=c++11 -c Item.hpp Item.cpp

#Guard_Radio.o:
#		g++ -std=c++11 -c Guard_Radio.hpp Guard_Radio.cpp

#Gun.o:
	#	g++ -std=c++11 -c Gun.hpp Gun.cpp

#Backpack.o:
		#g++ -std=c++11 -c Backpack.hpp Backpack.cpp

#Jail_Escape_Main.o:
		#g++ -std=c++11 -c  Jail_Escape_Main.cpp

#Menu.o:
		#g++ -std=c++11 -c Menu.hpp Menu.cpp

#Utility_Functions.o:
		#g++ -std=c++11 -c Utility_Functions.hpp Utility_Functions.cpp

#clean: 
		#rm *.o *.gch JailEscape
