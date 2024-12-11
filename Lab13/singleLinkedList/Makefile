CC = gcc
CFLAGS = -Wall -Iinclude -IUnity/src -fprofile-arcs -ftest-coverage
LDFLAGS = -L. -fprofile-arcs -ftest-coverage
SRC_DIR = src
TEST_DIR = test
UNITY_SRC = Unity/src/unity.c

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

EXECUTABLE = main
TEST_EXECUTABLE = run_tests

.PHONY: all clean test

all: $(EXECUTABLE)

$(EXECUTABLE): main.o libproject.a
	$(CC) $(CFLAGS) -o $@ $^

libproject.a: $(OBJ_FILES)
	ar rcs $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_FILES) libproject.a
	$(CC) $(CFLAGS) -o $@ $(UNITY_SRC) $^

coverage: test
	# Generate .gcda and .gcno files
	gcov $(SRC_DIR)/*.c

coverage_report: coverage
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '/usr/*' 'test/*' 'Unity/*' --output-file coverage.info --ignore-errors unused
	genhtml coverage.info --output-directory coverage_report

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE) $(TEST_EXECUTABLE) *.o libproject.a *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage_report
