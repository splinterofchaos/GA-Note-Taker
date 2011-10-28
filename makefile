
CPP = g++
out = noty

LDFLAGS = -framework SFML -framework sfml-audio -framework sfml-graphics -framework sfml-network -framework sfml-system -framework sfml-window -framework sndfile -framework OpenGL

obj = .Window.o

link = ${CPP} -o ${out} 
compile = ${CPP} -c

${out} : main.cpp ${obj}
	${link} main.cpp ${obj} ${LDFLAGS}

.Window.o : Window.*
	${compile} Window.cpp -o .Window.o	
