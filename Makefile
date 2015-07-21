ifndef OBJDIR
OBJDIR=$(PWD)/obj
endif

ifndef J
J=`nproc`
endif

all:
	@echo 'MAKE'
	@mkdir -p $(OBJDIR)
	@cd $(OBJDIR) && \
		OBJDIR=${OBJDIR} \
		J=${J} \
		DEBUG=${DEBUG} \
		OPT=${OPT}  \
		cmake .. \
	&& make -j$J

test: all
	@echo 'TEST'
	@cd $(OBJDIR) && ctest -j$J

build-and-test: clean test

clean:
	@echo 'CLEAN'
	@rm -r -f $(OBJDIR)
