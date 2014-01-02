CC      = gcc
FILES   = log.c bounded_buffer.c supporting_functions.c server.c stimer.c
OUT_EXE = http_server
LDFLAGS = -pthread -lrt
build:
	$(CC) $(FILES) -o $(OUT_EXE) $(LDFLAGS)

clean:
	rm $(OUT_EXE) 

rebuild: clean build
