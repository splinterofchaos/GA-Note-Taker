
CPP = g++
out = noty

ifeq "${shell uname}" "Darwin"
	LDFLAGS = -framework SFML -framework sfml-audio -framework sfml-graphics -framework sfml-network -framework sfml-system -framework sfml-window -framework sndfile -framework OpenGL
else
	LDFLAGS = -lGL -lopenal -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
endif

obj = .Window.o .TextBox.o

link = ${CPP} -o ${out} 
compile = ${CPP} -c

${out} : main.cpp ${obj}
	${link} main.cpp ${obj} ${LDFLAGS}

.TextBox.o : TextBox.*
	${compile} TextBox.cpp -o .TextBox.o

.Window.o : Window.*
	${compile} Window.cpp -o .Window.o	
