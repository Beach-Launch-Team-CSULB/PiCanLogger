  # build an executable named myprog from myprog.c
  #default:
 	  #gcc cantransmit.c -o cantransmit
all: 
transmit:
	gcc CAN_Transmit_Pi.c -o canTransmit
receive:
	gcc CAN_Receive_Pi.c -o canReceive
time:
	gcc timeTest.c simple_pi_time.c -o timeTest
	./timeTest
speed_Test_Write:
	gcc Speed_Test_CAN_Write.c -o speedTestWrite
speed_Test_Read:
	gcc Speed_Test_CAN_Read.c can_pi.c simple_pi_time.c -o speedTestRead
	./speedTestRead
driver:
	gcc main.c can_pi.c simple_pi_time.c -o main



clean: 
	rm canreceive
	rm cantransmit 
	rm timeTest
