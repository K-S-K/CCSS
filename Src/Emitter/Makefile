BINDIR := ./Bin
SOURCE := ./Main.cpp ../Library/Client.cpp
BINARY := $(addprefix $(BINDIR)/, emitter)

$(BINARY): $(SOURCE)
	g++ -g -o $(BINARY) $(SOURCE)

$(BINARY): | $(BINDIR)

$(BINDIR):
	mkdir $(BINDIR)
