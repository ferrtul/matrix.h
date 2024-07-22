CC=gcc
FLAGS  = -Wall -Werror -Wextra -std=c11
SOURCE = *.c

ifeq ($(shell uname -s),Linux)
	LIBS=-lm -lrt -lpthread -lcheck -lsubunit
endif

ifeq ($(shell uname -s),Darwin)
	LIBS=-lcheck
endif

all: s21_matrix.a

s21_matrix.a:
	$(CC) $(FLAGS) -c $(SOURCE) -lm
	ar rcs s21_matrix.a *.o
	rm -rf *.o

test : clean s21_matrix.a
	$(CC) tests/*.c $(SOURCE) $(LIBS) -lm -o s21_test
	./s21_test

clean :
	rm -rf s21_test
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda *.o
	rm -rf *.html
	rm -rf *.info
	rm -rf *.css
	rm -rf report
	rm -rf report_files
	rm -rf s21_test.dSYM
	rm -rf a.out
	rm -rf *.gcov

gcov_report: clean
	gcc --coverage $(SOURCE) tests/tests.c tests/test_*.c -o s21_test $(LIBS)
	./s21_test
	gcov $(SOURCE)
	lcov -t "cooverage" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

clang_format:
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -i  tests/*.c tests/*.h

style:
	clang-format -style=Google -n s21_*.c
	clang-format -style=Google -n  tests/*.c


lcov:
	brew install lcov

brew:
	cd
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

.PHONY: clean

