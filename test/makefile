FLAGS = -Wall -Wextra -pedantic -std=c++0x -MP -MMD
EXEC = pml-tests

TEST_SRC = $(wildcard *.cpp)
TEST_OBJ = $(TEST_SRC:.cpp=.o) 

all: $(EXEC)

$(TEST_OBJ): %.o : %.cpp

$(TEST_OBJ):
	$(CXX) $(FLAGS) -c $< -o $(<:.cpp=.o)

pml-tests: $(TEST_OBJ)
	$(CXX) -o $(EXEC) $(TEST_OBJ)

-include $(TEST_SRC:.cpp=.d)

clean:
	@$(RM) $(EXEC)
	@$(RM) *.o
	@$(RM) *.d
