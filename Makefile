configure_release:
	rm -rf ./build
	mkdir -p ./build
	cd build && cmake -DCMAKE_BUILD_TYPE=Release ..

configure_debug:
	rm -rf ./build
	mkdir -p ./build
	cd build && cmake .. -DDEBUG=ON

flex:
	@echo "Compiling the Yacc and Lex files"
	@flex --outfile=./src/observer/sql/parser/lex.yy.c  --header-file=./src/observer/sql/parser/lex.yy.h ./src/observer/sql/parser/lex_sql.l 
	@bison -o ./src/observer/sql/parser/yacc_sql.tab.c --defines=./src/observer/sql/parser/yacc_sql.tab.h ./src/observer/sql/parser/yacc_sql.y

build:
	# rm -rf ./miniob
	cd build && make -j4

run_server:
	rm -f observer.log.*
	./build/bin/observer -f ./etc/observer.ini

run_client:
	./build/bin/obclient

clean:
	rm -rf build/

.PHONY: build clean
