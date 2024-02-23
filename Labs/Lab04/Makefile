CXX = g++
CXXFLAGS = -std=c++11 -Wall -I.
TESTFLAGS = -DDOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
SRC_DIR =.# If your .cpp files are in a separate directory, change this

# Source files for the application
APP_SRCS = $(SRC_DIR)/fisher_yates.cpp $(SRC_DIR)/gen_permutation.cpp $(SRC_DIR)/prefix_sum.cpp $(SRC_DIR)/wellFormedSymbols_Generator.cpp $(SRC_DIR)/main_gen_valid_parents.cpp

# Test source files
TEST_FISHER_YATES = $(SRC_DIR)/unit_test_fisherYates.cpp
TEST_GEN_PERMUTATION = $(SRC_DIR)/unit_test_genPermutation.cpp
TEST_PREFIX_SUM = $(SRC_DIR)/unit_test_prefixSum.cpp
TEST_WELL_FORMED_GENERATOR = $(SRC_DIR)/unit_test_wellFormedGenerator.cpp

# Executable name for the main application
MAIN = wellFormedSymbols

# Executable names for the tests
TEST_EXECUTABLES = fisherYates_test genPermutation_test prefixSum_test wellFormedGenerator_test

.PHONY: all clean run tests check

all: $(MAIN) tests

$(MAIN): 
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(APP_SRCS)


tests: $(TEST_EXECUTABLES)

fisherYates_test:
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) -o fisherYates_test $(TEST_FISHER_YATES) $(filter-out $(SRC_DIR)/main_gen_valid_parents.cpp, $(APP_SRCS))

genPermutation_test:
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) -o genPermutation_test $(TEST_GEN_PERMUTATION) $(filter-out $(SRC_DIR)/main_gen_valid_parents.cpp, $(APP_SRCS))

prefixSum_test:
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) -o prefixSum_test $(TEST_PREFIX_SUM) $(filter-out $(SRC_DIR)/main_gen_valid_parents.cpp, $(APP_SRCS))

wellFormedGenerator_test:
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) -o wellFormedGenerator_test $(TEST_WELL_FORMED_GENERATOR) $(filter-out $(SRC_DIR)/main_gen_valid_parents.cpp, $(APP_SRCS))

clean:
	rm -f $(MAIN) $(TEST_EXECUTABLES)

run: $(MAIN)
	./$(MAIN)

check: tests
	@echo "Running tests..."
	@for test in $(TEST_EXECUTABLES); do \
		echo "Running $$test"; \
		./$$test || exit 1; \
	done
