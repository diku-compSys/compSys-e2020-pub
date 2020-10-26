gcc=gcc -g -Werror -Wpedantic -Wall -o
src=tfgets.c
executable=tfgets


compile: $(executable)

run: compile
	./$(executable)

$(executable): $(src)
	$(gcc) $(executable) $(src)

clean:
	rm -f $(executable)
