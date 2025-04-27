# ==== 기본 변수 ====
CXX      := g++
CXXFLAGS := -std=c++26 -Wall -Wextra -O2 -pipe -static
# 모든 .cpp 자동 탐색
SRCS     := $(wildcard *.cpp)
OBJS     := $(SRCS:.cpp=.o)
TARGET   := app

# ==== 기본 규칙 ====
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
