# ==============================================================================
# Makefile Functions
# ==============================================================================

RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
MAGENTA = \033[35m
CYAN    = \033[36m
B_RED   = \033[1;31m
B_GREEN = \033[1;32m
B_CYAN  = \033[1;36m

# A function for printing formatted build information
define print-var
	@printf "$(MAGENTA)| %-16s= $(GREEN)[ %-40s ]$(RESET)\n" "$1" "$2"
endef

define print
	@printf "$(B_CYAN)>>>$(RESET) $(MAGENTA)$1$(RESET)\n"
endef

# A function for logging colored status messages
define log
	@printf "$(B_CYAN)>>>$(RESET) $(B_GREEN)$1$(RESET)\n"
endef

# A function for logging colored warnings
define warn
	@printf "$(B_CYAN)>>>$(RESET) $(YELLOW)Warning: $1$(RESET)\n"
endef

# A function for logging colored errors
define error-log
	@printf "$(B_CYAN)>>>$(RESET) $(B_RED)Error: $1$(RESET)\n"
	@exit 1
endef
