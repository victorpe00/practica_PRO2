OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o especie.o cjt_especies.o cjt_clusters.o
	g++ -o program.exe *.o 

especie.o: especie.cc especie.hh
	g++ -c especie.cc $(OPCIONS) 

cjt_especies.o: cjt_especies.cc cjt_especies.hh especie.hh taula_distancies.hh
	g++ -c cjt_especies.cc $(OPCIONS) 

cjt_clusters.o: cjt_clusters.cc cjt_clusters.hh cluster.hh BinTree.hh
	g++ -c cjt_clusters.cc $(OPCIONS)

taula_distancies.o: taula_distancies.cc taula_distancies.hh
	g++ -c taula_distancies.cc $(OPCIONS)

program.o: program.cc cjt_clusters.hh especie.hh cluster.hh cjt_especies.hh taula_distancies.hh 
	g++ -c program.cc $(OPCIONS) 

clean:
	rm -f *.o
	rm -f *.exe
