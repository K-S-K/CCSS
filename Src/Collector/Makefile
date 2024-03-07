BINDIR := ./Bin
SOURCE := ./Main.cpp ../Library/Server.cpp
BINARY := $(addprefix $(BINDIR)/, collector)

$(BINARY): $(SOURCE)
	g++ -g -o $(BINARY) $(SOURCE)

$(BINARY): | $(BINDIR)

$(BINDIR):
	mkdir $(BINDIR)
