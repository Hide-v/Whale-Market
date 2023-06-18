.PHONY: clean # 伪目标

# 自定义环境变量
CC = clang # 指定编译器

CFLAGS = -I include # 指定头文件目录
CFILE = $(shell find src -name "*.cpp") #搜索所有源文件
OBJS = $(CFILE:.cpp = .o) # 所有目标文件
TARGET = main
DATA = src/data/*.txt # 搜索所有数据文件

RM = rm -r -f # 删除方式

all = $(TARGET)

# 项目构建方式
$(TARGET) = $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%o : %c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS) $(DATA)