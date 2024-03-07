BINDIR := ./Bin
SOURCE := ./Main.cpp ../Library/Client.cpp
BINARY := $(addprefix $(BINDIR)/, client)

$(BINARY): $(SOURCE)
	g++ -g -o $(BINARY) $(SOURCE)

$(BINARY): | $(BINDIR)

$(BINDIR):
	mkdir $(BINDIR)
