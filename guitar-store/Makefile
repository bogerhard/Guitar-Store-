CXX = g++
CXXFLAGS = -std=c++11 -g -fprofile-arcs -ftest-coverage

LINKFLAGS = -lgtest

TEST_DIR = test

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

SRC_DIR = src

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

PROGRAM_TEST = testInventory

DOCS_DIR = docs

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

.PHONY: all
all: $(PROGRAM_TEST) coverage memcheck static style docs

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o \
	$(PROGRAM_TEST) \
	$(DOCS_DIR) obj bin *.gc* \
	$(COVERAGE_RESULTS) $(COVERAGE_DIR)

$(PROGRAM_TEST): $(TEST_DIR) $(SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) \
	$(SRC_DIR)/*.cpp $(TEST_DIR)/*.cpp $(LINKFLAGS)

tests: $(PROGRAM_TEST)
	$(PROGRAM_TEST)

memcheck: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM_TEST)

static: ${SRC_DIR} ${TEST_DIR} ${SRC_INCLUDE}
	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} ${TEST_DIR} ${SRC_INCLUDE} --suppress=missingInclude

style: ${TEST_DIR} ${SRC_INCLUDE}
	${STYLE_CHECK} $(SRC_INCLUDE)/* ${TEST_DIR}/*

docs: ${SRC_INCLUDE}/*.h
	doxygen doxyfile

coverage: tests
		# Determine code coverage
		$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS) --rc lcov_branch_coverage=1
		# Only show code coverage for the source code files (not library files)
		$(LCOV) --extract $(COVERAGE_RESULTS) "*/src/*" -o $(COVERAGE_RESULTS) --rc lcov_branch_coverage=1
		$(LCOV) --remove $(COVERAGE_RESULTS) "*/test/*" -o $(COVERAGE_RESULTS) --rc lcov_branch_coverage=1
		#Generate the HTML reports
		genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR) --rc lcov_branch_coverage=1
		#Remove all of the generated files from gcov
		rm -f *.gc*
