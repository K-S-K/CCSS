BINDIR := ./Bin
SOURCE := ./Main.cpp ./Server.cpp
BINARY := $(addprefix $(BINDIR)/, server)

$(BINARY): $(SOURCE)
	g++ -o $(BINARY) $(SOURCE)

$(BINARY): | $(BINDIR)

$(BINDIR):
	mkdir $(BINDIR)
