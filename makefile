CXX := g++
CC := g++
CXXFLAGS := -g -Wall

# list of all the object files that will be necessary
src_files := \
main.o \
Commands\pattern\pattern.o \
Commands\help\help.o \
Commands\callInfo\callInfo.o \

all: $(src_files)
	$(CXX) $(CXXFLAGS) -o main $(src_files) 
	main.exe -H
$(src_files): %.o : %.cpp

clean:
	del $(src_files)