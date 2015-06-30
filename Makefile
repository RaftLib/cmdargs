CC  ?= clang
CXX ?= clang++
AR  ?= ar
CFLAGS = -std=c99 -O2 -mtune=native
CXXFLAGS = -std=c++11 -O2 -mtune=native
PREFIX=/usr/local

#STATIC = -static -static-libgcc -static-libstdc++

CXXOBJS = command_arguments command_option_base 

CXXFILES = $(addsuffix .cpp, $(CXXOBJS))

OBJS = $(addsuffix .o, $(CXXOBJS))

compile: $(CXXFILES)
	$(MAKE) $(OBJS)
	$(AR) $(STATIC) rvs libcmdargs.a $(OBJS)

.PHONY:install
install:
	cp libcmdargs.a $(PREFIX)/lib/
	cp cmd $(PREFIX)/include/cmd
	mkdir -p $(PREFIX)/include/cmdargs/
	cp *.hpp $(PREFIX)/include/cmdargs/
	cp *.h   $(PREFIX)/include/cmdargs/
	cp *.tcc $(PREFIX)/include/cmdargs/
	echo "Install complete!"

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INCS) -o $@ $<

.PHONY:clean
clean:
	rm -rf libcmdargs.a $(OBJS) intelremotemonfifo.*
