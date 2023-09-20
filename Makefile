all: 
	$(MAKE) clean
	$(MAKE) fifo
	$(MAKE) sfj
	$(MAKE) rr


fifo: 
	@echo making fifo...
	g++ -Wall -Werror -std=c++20 -g ./FIFO/*.cpp -o fifo
	@echo "done"

sfj:
	@echo making sfj...
	g++ -Wall -Werror -std=c++20 -g ./ShortestFirstJob/*.cpp -o sfj
	@echo "done"

rr:
	@echo making rr...
	g++ -Wall -Werror -std=c++20 -g ./RoundRobin/*.cpp -o rr
	@echo "done" 


#clean by going into each directory and running make clean
clean: 
	@echo "cleaning up..."
	@rm -rf fifo sfj rr *.dSYM
	@echo "done"

all:
	$(MAKE) clean
	$(MAKE) fifo
	$(MAKE) sfj
	$(MAKE) rr