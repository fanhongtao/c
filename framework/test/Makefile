
CPPFLAGS = -g -I ../include

LIBS = -lgtest -lgtest_main

objects = mutex_test.o

mutex_test:$(objects)
	$(CXX) -g -o mutex_test $(objects) $(LIBS)

clean:
	rm -f *.o

