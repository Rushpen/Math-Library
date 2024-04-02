CC = gcc
CFLAGS = -Wall -Werror -Wextra 
SF = -fsanitize=leak,address 

ifeq ($(shell uname), Linux)
    all: s21_math.a test gcov_report

    s21_math.a: s21_math.c s21_math.h
		$(CC) $(CFLAGS) -c s21_math.c -o s21_math.o
		ar rcs s21_math.a s21_math.o
		ranlib s21_math.a

    test: s21_math.a
		$(CC) -g $(CFLAGS) -fprofile-arcs -ftest-coverage -o ./test ./tests.c ./s21_math.c ./s21_math.h -lcheck -lm -lsubunit

    gcov_report: test
		./test
		mkdir -p gcov-report
		gcov -r ./tests.c
		gcovr -r . --html --html-details -o gcov-report/index.html
		open ./gcov-report/index.html
else ifeq ($(shell uname), Darwin)
    all: s21_math.a gcov_report
		
    s21_math.a: s21_math.c s21_math.h
		$(CC) $(CFLAGS) -c s21_math.c -o s21_math.o
		ar rc s21_math.a s21_math.o
		ranlib s21_math.a

    test: s21_math.a
		$(CC) -g $(CFLAGS) -fprofile-arcs -ftest-coverage -o ./test ./tests.c ./s21_math.c ./s21_math.h -lcheck -lm

    gcov_report: s21_math.a
		gcc --coverage ./s21_math.a tests.c -o s21test -lcheck
		./s21test
		lcov -t "s21test" -o s21test.info -c -d .
		genhtml -o gcov-report s21test.info
		open ./gcov-report/index.html

    lib:
		brew install check
		brew install lcov
endif

clean:
	rm -rf *.o *.a *.gcno *.gcda test
	rm -r gcov-report

rebuild: clean all

