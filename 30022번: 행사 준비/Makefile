# ==== 기본 변수 ====
CXX      := g++
CXXFLAGS := -std=c++26 -Wall -Wextra -O2 -pipe -static
TARGET   := solution
SRCS     := solution.cpp
OBJS     := $(SRCS:.cpp=.o)

# ==== 기본 규칙 ====
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
