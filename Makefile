CPP=g++    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=`pkg-config --cflags --libs opencv` #Linker
BOOSTFLAG=-lboost_unit_test_framework
all: ptt vtt eyet envt facet filtre filtreH filtreC clean

#################################

ptt : ptt.o
	${CPP} $(CFLAGS) -g -Wall -o ptt ptt.o ${LDFLAGS} ${BOOSTFLAG}
	
ptt.o : pt_test.cpp
	${CPP} $(CFLAGS) -g -Wall -o ptt.o -c pt_test.cpp ${LDFLAGS} ${BOOSTFLAG}
	
vtt : vtt.o
	${CPP} $(CFLAGS) -g -Wall -o vtt vtt.o ${LDFLAGS} ${BOOSTFLAG}
	
vtt.o : vtt.cpp
	${CPP} $(CFLAGS) -g -Wall -o vtt.o -c vtt.cpp ${LDFLAGS} ${BOOSTFLAG}
	
eyet : eyet.o
	${CPP} $(CFLAGS) -g -Wall -o eyet eyet.o ${LDFLAGS} ${BOOSTFLAG}
	
eyet.o : eyet.cpp
	${CPP} $(CFLAGS) -g -Wall -o eyet.o -c eyet.cpp ${LDFLAGS} ${BOOSTFLAG}
	
facet : facet.o Face.o
	${CPP} $(CFLAGS) -g -Wall -o facet facet.o Face.o ${LDFLAGS} ${BOOSTFLAG}
	
facet.o : facet.cpp
	${CPP} $(CFLAGS) -g -Wall -o facet.o -c facet.cpp ${LDFLAGS} ${BOOSTFLAG}
	
Face.o : Face.cpp
	${CPP} $(CFLAGS) -g -Wall -o Face.o -c Face.cpp ${LDFLAGS} ${BOOSTFLAG}
	
envt : envt.o Environement.o FiltreSobel.o DetecFace.o Face.o FiltreMedian.o FiltreInvert.o
	${CPP} $(CFLAGS) -g -Wall -o envt Environement.o DetecFace.o Face.o FiltreSobel.o FiltreInvert.o FiltreMedian.o envt.o ${LDFLAGS} ${BOOSTFLAG}
	
envt.o : envt.cpp FiltreSobel.o
	${CPP} $(CFLAGS) -g -Wall -o envt.o -c envt.cpp ${LDFLAGS} ${BOOSTFLAG}
	
Environement.o : Environement.cpp
	${CPP} $(CFLAGS) -g -Wall -o Environement.o -c Environement.cpp ${LDFLAGS} ${BOOSTFLAG}
	

filtre : filt.o FiltreSobel.o Environement.o Face.o
	${CPP} $(CFLAGS) -g -Wall -o filtre filt.o FiltreSobel.o Face.o Environement.o ${LDFLAGS} ${BOOSTFLAG}
	
filt.o : filtre.cpp 
	${CPP} $(CFLAGS) -g -Wall -o filt.o -c filtre.cpp ${LDFLAGS} ${BOOSTFLAG}

FiltreSobel.o : FiltreSobel.cpp
	${CPP} $(CFLAGS) -g -Wall -o FiltreSobel.o -c FiltreSobel.cpp ${LDFLAGS} ${BOOSTFLAG}

	
filtreH : filtH.o FiltreHough.o Environement.o Face.o
	${CPP} $(CFLAGS) -g -Wall -o filtreH filtH.o Face.o FiltreHough.o Environement.o ${LDFLAGS} ${BOOSTFLAG}
	
filtH.o : filtreH.cpp
	${CPP} $(CFLAGS) -g -Wall -o filtH.o -c filtreH.cpp ${LDFLAGS} ${BOOSTFLAG}
	
FiltreHough.o : FiltreHough.cpp
	${CPP} $(CFLAGS) -g -Wall -o FiltreHough.o -c FiltreHough.cpp ${LDFLAGS} ${BOOSTFLAG}
	
filtreC : filtC.o FiltreCouleur.o Environement.o Face.o
	${CPP} $(CFLAGS) -g -Wall -o filtreC filtC.o FiltreCouleur.o Face.o Environement.o ${LDFLAGS} ${BOOSTFLAG}
	
filtC.o : filtreC.cpp
	${CPP} $(CFLAGS) -g -Wall -o filtC.o -c filtreC.cpp ${LDFLAGS} ${BOOSTFLAG}
	
FiltreCouleur.o : FiltreCouleur.cpp
	${CPP} $(CFLAGS) -g -Wall -o FiltreCouleur.o -c FiltreCouleur.cpp ${LDFLAGS} ${BOOSTFLAG}
	
filtreI : filtI.o FiltreInvert.o Environement.o Face.o
	${CPP} $(CFLAGS) -g -Wall -o filtreI filtI.o FiltreInvert.o Face.o Environement.o ${LDFLAGS} ${BOOSTFLAG}
	
filtI.o : filtreI.cpp
	${CPP} $(CFLAGS) -g -Wall -o filtI.o -c filtreI.cpp ${LDFLAGS} ${BOOSTFLAG}
	
FiltreInvert.o : FiltreInvert.cpp
	${CPP} $(CFLAGS) -g -Wall -o FiltreInvert.o -c FiltreInvert.cpp ${LDFLAGS} ${BOOSTFLAG}
	
filtreM : filtM.o FiltreMedian.o Environement.o Face.o
	${CPP} $(CFLAGS) -g -Wall -o filtreM filtM.o FiltreMedian.o Face.o Environement.o ${LDFLAGS} ${BOOSTFLAG}
	
filtM.o : filtreM.cpp
	${CPP} $(CFLAGS) -g -Wall -o filtM.o -c filtreM.cpp ${LDFLAGS} ${BOOSTFLAG}
	
FiltreMedian.o : FiltreMedian.cpp
	${CPP} $(CFLAGS) -g -Wall -o FiltreMedian.o -c FiltreMedian.cpp ${LDFLAGS} ${BOOSTFLAG}
	
eliptest : eliptest.o FiltreElip.o
	${CPP} $(CFLAGS) -g -Wall -o eliptest eliptest.o FiltreElip.o ${LDFLAGS} ${BOOSTFLAG}
	
eliptest.o : eliptest.cpp
	${CPP} $(CFLAGS) -g -Wall -o eliptest.o -c eliptest.cpp ${LDFLAGS} ${BOOSTFLAG}
	
FiltreElip.o : FiltreElip.cpp
	${CPP} $(CFLAGS) -g -Wall -o FiltreElip.o -c FiltreElip.cpp ${LDFLAGS} ${BOOSTFLAG}
	
	
	################################ALL FILTER
allfil : allfil.o FiltreInvert.o FiltreHough.o FiltreSobel.o Environement.o FiltreCouleur.o FiltreMedian.o Face.o
	${CPP} $(CFLAGS) -g -Wall -o allfil allfil.o FiltreInvert.o FiltreCouleur.o FiltreHough.o FiltreSobel.o FiltreMedian.o Face.o Environement.o ${LDFLAGS} ${BOOSTFLAG}
	
allfil.o : allfil.cpp
	${CPP} $(CFLAGS) -g -Wall -o allfil.o -c allfil.cpp ${LDFLAGS} ${BOOSTFLAG}
	
	
	################################"FACE#####################
	
dfe : df.o Environement.o Face.o FiltreMedian.o FiltreInvert.o FiltreHough.o FiltreSobel.o FiltreCouleur.o DetecFace.o
	${CPP} $(CFLAGS) -g -Wall -o dfe Environement.o Face.o FiltreMedian.o FiltreInvert.o FiltreHough.o FiltreSobel.o DetecFace.o FiltreCouleur.o df.o ${LDFLAGS} ${BOOSTFLAG}
	
df.o : df.cpp
	${CPP} $(CFLAGS) -g -Wall -o df.o -c df.cpp ${LDFLAGS} ${BOOSTFLAG}
	
dgaze : dgaze.o Environement.o Face.o FiltreMedian.o FiltreInvert.o FiltreHough.o FiltreSobel.o FiltreCouleur.o DetecFace.o DetecGaze.o FiltreElip.o
	${CPP} $(CFLAGS) -g -Wall -o dgaze Environement.o Face.o FiltreElip.o FiltreMedian.o FiltreInvert.o FiltreHough.o FiltreSobel.o FiltreCouleur.o DetecGaze.o DetecFace.o dgaze.o ${LDFLAGS} ${BOOSTFLAG}

dgaze.o : dgaze.cpp
	${CPP} $(CFLAGS) -g -Wall -o dgaze.o -c dgaze.cpp ${LDFLAGS} ${BOOSTFLAG}

DetecFace.o : DetecFace.cpp
	${CPP} $(CFLAGS) -g -Wall -o DetecFace.o -c DetecFace.cpp ${LDFLAGS} ${BOOSTFLAG}
	
DetecGaze.o : DetecGaze.cpp
	${CPP} $(CFLAGS) -g -Wall -o DetecGaze.o -c DetecGaze.cpp ${LDFLAGS} ${BOOSTFLAG}


##################VARIABLES GLOBAL##########################"	
	
Global.o : Global.cpp
	${CPP} $(CFLAGS) -g -Wall -o Global.o -c Global.cpp ${LDFLAGS} ${BOOSTFLAG}
	
	
clean:
	rm -f *.o
	rm -f *~
