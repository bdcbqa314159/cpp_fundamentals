dependency:
	cd build && cmake .. && make

prepare:
	rm -rf build
	mkdir build

first_exe:
	cd build/app && ./first_exec