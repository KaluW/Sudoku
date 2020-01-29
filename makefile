# ----------------------------
# Set NAME to the program name
# Set ICON to the png icon file name
# Set DESCRIPTION to display within a compatible shell
# Set COMPRESSED to "YES" to create a compressed program
# ----------------------------

NAME        ?= SUDOKU
COMPRESSED  ?= NO
ICON        ?= iconc.png
DESCRIPTION ?= "Sudoku"

# ----------------------------

include $(CEDEV)/include/.makefile

$(OBJDIR)/font/font.src: $(SRCDIR)/font/font20.inc

$(SRCDIR)/font/font20.inc: $(SRCDIR)/font/Sudoku20.fnt
	convfont -o carray -f $(SRCDIR)/font/Sudoku20.fnt $(SRCDIR)/font/font20.inc