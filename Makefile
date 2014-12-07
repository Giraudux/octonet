#          Copyright Alexis Giraudet 2014.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

all: b2

b2:
ifeq ($(wildcard ./boost/.*),)
	./opt/get-boost.sh 1.57.0
endif
ifeq ($(wildcard ./boost/b2),)
	cd ./boost && ./bootstrap.sh
endif
	BOOST_ROOT=./boost ./boost/b2 toolset=gcc warnings=all

clean:
	-rm -r ./build
