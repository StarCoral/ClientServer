FROM ubuntu:16.04
MAINTAINER Riya

RUN apt-get update && apt-get upgrade -y

RUN apt-get install vim -y && \
    apt-get install gcc -y && \
    apt-get install make -y && \
    apt-get install ssh -y 
RUN /etc/init.d/ssh restart

#install unp library
ADD ./unpv13e.tar.gz ./
 
RUN mv ./unpv13e ./src  && \
    cd src && \
    chmod 777 configure && \
    ./configure && \
    cd lib && \
    make && \
    cd ~

#client-server
ADD ./client.c ./
ADD ./server.c ./

RUN gcc -o client client.c && \
    gcc -o server server.c 
    
    
CMD ["bash"]