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
	g++ -Wall -Werror -std=c++20 -g handledata.cpp -o ./SFJ/*.cpp -o sfj
	@echo "done"

rr:
	@echo making rr...
	g++ -Wall -Werror -std=c++20 -g handledata.cpp -o ./RR/*.cpp -o rr
	@echo "done" 


#clean by going into each directory and running make clean
clean: 
	@echo "cleaning up..."
	@rm -rf fifo *.dSYM
	@echo "done"

all:
	$(MAKE) clean
	$(MAKE) fifo
	$(MAKE) sfj
	$(MAKE) rr