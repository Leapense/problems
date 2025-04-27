# ── Makefile ──

# 1) 컴파일러와 플래그
CXX      := g++
CXXFLAGS := -std=c++26 -O2 -Wall -Wextra \
			-isystem /usr/include/c++/15

# 2) 소스와 오브젝트 자동 수집
SRCS := solution.cpp
OBJS := $(SRCS:.cpp=.o)

# 3) 최종 실행파일 이름
TARGET := solution

# 4) 기본 타겟 (make 만 입력했을 때)
.PHONY: all
all: $(TARGET)

.PHONY: run
run: $(TARGET)
	./$(TARGET) < input.txt      # 예시: 표준 입력에 input.txt 주고 실행

# 5) 실행파일 빌드
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 6) 오브젝트 개별 컴파일
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 7) 정리 (clean)
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
