gcc=gcc -g -Werror -Wpedantic -Wall -o
executable=illegal_activity_in_child_process
src=$(executable).c


compile: $(executable)

run: compile
	./$(executable)

$(executable): $(src)
	$(gcc) $(executable) $(src)


clean:
	rm -f $(executable)
