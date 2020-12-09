## compiler
CXX = g++ -std=c++11
CXXFLAGS = -pedantic -g
ola7: main.o sList.o
	$(CXX) $(CXXFLAGS) main.o sList.o -o ola7
main.o: main.cpp sList.h
	$(CXX) $(CXXFLAGS) -c main.cpp
sList.o: sList.cpp sList.h
	$(CXX) $(CXXFLAGS) -c sList.cpp
clean:
	$(RM) ola7 *.o
