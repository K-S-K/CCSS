BINDIR := ./Bin
SOURCE := ./Main.cpp ../Library/Server.cpp
BINARY := $(addprefix $(BINDIR)/, server)

$(BINARY): $(SOURCE)
	g++ -g -o $(BINARY) $(SOURCE)

$(BINARY): | $(BINDIR)

$(BINDIR):
	mkdir $(BINDIR)
