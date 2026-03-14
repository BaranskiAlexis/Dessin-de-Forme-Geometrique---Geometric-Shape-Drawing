SRC_DIR = src
OUT_DIR = obj
NAME = Main.jar
MAIN_CLASS = src.Main

SRCS = $(wildcard $(SRC_DIR)/*.java)
CLS = $(SRCS:$(SRC_DIR)/%.java=$(OUT_DIR)/%.class)

JC = javac
JCFLAGS = -d $(OUT_DIR)/ -cp $(OUT_DIR):$(SRC_DIR)

.PHONY: all run clean jar stop

all: $(NAME)

$(NAME): $(CLS)
	jar cfe $(NAME) $(MAIN_CLASS) -C $(OUT_DIR) .

$(CLS): $(SRCS)
	@mkdir -p $(OUT_DIR)
	$(JC) $(JCFLAGS) $(SRCS)

run: $(NAME)
	java -Djava.net.preferIPv4Stack=true -jar $(NAME) > server.log 2>&1 & echo $$! > server.pid

clean:
	rm -rf $(OUT_DIR)
	rm -f $(NAME)

stop:
	kill `cat server.pid` && rm server.pid && rm server.log