
CPPFLAGS = -g -I ../include

LIBS = -lgtest -lgtest_main

objects = mutex_test.o  common_test.o

gtest:$(objects)
	$(CXX) -g -o gtest $(objects) $(LIBS)

clean:
	rm -f *.o

