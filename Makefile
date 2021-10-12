  # build an executable named myprog from myprog.c
  #default:
 	  #gcc cantransmit.c -o cantransmit
all: transmit receive
transmit:
	gcc cantransmit.c -o cantransmit
receive:
	gcc canreceive.c -o canreceive

clean: 
	rm canreceive
	rm cantransmit 