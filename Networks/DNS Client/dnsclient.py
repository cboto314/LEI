#|/usr/bin/python3
from socket import *

#Servidor de DNS
dnsserver = "x.x.x.x" #put your DNS server here
portnumber = 53

#Query
query = bytearray()

#Identification
#An arbitrary 16 bit request identifier. The same ID is used in the response to the query so we can match them up.
query.append(0x01)
query.append(0x01)

#Flags
#
query.append(0x01)  #0x01 = don't truncate, use recursion
query.append(0x00)  #standard query

#Number of questions
query.append(0x00)
query.append(0x01) #1 question

#Nr of answers RRs
query.append(0x00)
query.append(0x00) #no answers

#Number of authority RRs
query.append(0x00)
query.append(0x00) #no authority records

#Nr of additional RRs
query.append(0x00)
query.append(0x00) #no additional records

#Request for ualg.pt
query.append(0x04)	#len("ualg") = 4
query.append(0x75)		#u
query.append(0x61)		#a
query.append(0x6C)		#l
query.append(0x67)		#g

query.append(0x02)	#len("pt") = 2
query.append(0x70)		#p
query.append(0x74)		#t

query.append(0x00)

query.append(0x00)
query.append(0x01)#QTYPE
query.append(0x00)
query.append(0x01)#QCLASS


address = (dnsserver, portnumber) 
client = socket(AF_INET, SOCK_DGRAM) # Internet, UDP.

client.sendto(query, address) # Send the DNS packet to the server using the port
data, address = client.recvfrom(1024)
print(data)
