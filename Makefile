ifndef OBJDIR
OBJDIR=$(PWD)/obj
endif

all:
	@echo 'MAKE'
	@mkdir -p $(OBJDIR)
	@cd $(OBJDIR) && OBJDIR=$(OBJDIR) VERBOSE=1 cmake .. && make -j`nproc`

clean:
	@echo 'CLEAN'
	@rm -r -f $(OBJDIR)