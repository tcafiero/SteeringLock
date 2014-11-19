swig -ruby SteeringLock.i
gcc -fpic -c SteeringLock_wrap.c -I/usr/lib/ruby/1.8/i386-cygwin/
ruby extconf.rb
make
make install
