FROM gcc:4.9

COPY . /usr/src/http-server
WORKDIR /usr/src/http-server

RUN mkdir -p build/ && cd build/ && rm -rf * 
RUN cd build/ && gcc -I.. -o Http ../server.cpp ../http_tcpserver.cpp -lstdc++

EXPOSE 8080 