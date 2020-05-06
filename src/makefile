# What to do?
TARGET = main

# C compiler and linker flags
CC = g++
#

CPPFLAGS  = -g3 -pedantic -ansi -Wall -Werror -Wextra -std=c++03 -I../include/
LDFLAGS  =  -g3 -rdynamic -pthread -ldl 

VALFLAG = --tool=memcheck --leak-check=full  -s
VALFLAG2= --tool=helgrind
VALFILE = --log-file=mem.txt --leak-check=full --show-leak-kinds=all
VALFILE2= --log-file=hel.txt

.PHONY: all clear

all:  $(TARGET) 

# Linker built-in rule
%: %.o
	$(CC) $(LDFLAGS) -o $(@) $(^) $(LDLIBS) $(LDFLAGS)

main:main.o smarthome.o
main:publisher.o publisherrun.o subscriptor.o eventcontainer.o  event.o
main:uncopyable.o mutex.o condvar.o  thread.o
main:abcsensoragent.o abccontrolleragent.o abcsensorrunnable.o abccontrollerrunnable.o iagent.o
main:factory.o dlopen.o
main:parser_t.o tokenyzer_t.o analyzer_t.o
# main:firesensa.o tempsensa.o fireconta.o tempconta.o

# C compiler built-in rule
#%.o: %.c
#	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $(@) $(<)

main.o:main.cpp 
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

thread.o:thread.cpp ../include/thread.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

mutex.o:mutex.cpp ../include/mutex.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

condvar.o:condvar.cpp ../include/condvar.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

uncopyable.o:uncopyable.cpp ../include/uncopyable.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

event.o:event.cpp ../include/event.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

eventcontainer.o:eventcontainer.cpp  ../include/eventcontainer.h 
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

publisher.o:publisher.cpp  ../include/publisher.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

publisherrun.o:publisherrun.cpp  ../include/publisherrun.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

subscriptor.o:subscriptor.cpp  ../include/subscriptor.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

iagent.o:iagent.cpp ../include/iagent.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

abcsensoragent.o:abcsensoragent.cpp ../include/abcsensoragent.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

abccontrolleragent.o:abccontrolleragent.cpp ../include/abccontrolleragent.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

abcsensorrunnable.o:abcsensorrunnable.cpp  ../include/abcsensorrunnable.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

abccontrollerrunnable.o:abccontrollerrunnable.cpp ../include/abccontrollerrunnable.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

# firesensa.o:firesensa.cpp ../include/firesensa.h
# 	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

# tempsensa.o:tempsensa.cpp ../include/tempsensa.h
# 	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

# fireconta.o:fireconta.cpp ../include/fireconta.h
# 	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

# tempconta.o:tempconta.cpp ../include/tempconta.h
# 	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

factory.o:factory.cpp ../include/factory.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

dlopen.o:dlopen.cpp ../include/dlopen.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

smarthome.o:smarthome.cpp ../include/smarthome.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

parser_t.o:parser_t.cpp ../include/parser_t.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

tokenyzer_t.o:tokenyzer_t.cpp ../include/tokenyzer_t.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)

analyzer_t.o:analyzer_t.cpp ../include/analyzer_t.h
	$(CC) -c $(CPPFLAGS)  -o $(@) $(<)
	
valleak:
	valgrind  $(VALFILE) $(VALFLAG) ./$(TARGET) 	

valrace:
	valgrind  $(VALFILE2) $(VALFLAG2) ./$(TARGET) 


clean:
	rm -f ../lib/*.o $(TARGET)
	rm -f *.o $(TARGET)
	
test: $(TARGET)
	./$(TARGET) -v
	

