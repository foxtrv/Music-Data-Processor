JI = JSONDataItem
JO = JSONDataObject
JA = JSONArray
A = Artist
A2 = Artists
AL = Album
AL2 = Albums
T = Track
T2 = Tracks
AI = ArtistImage
AI2 = ArtistImages
ALI = AlbumImage
M = main

all: $(JI).o $(JO).o $(A).o $(M).o $(AL).o $(T).o $(A2).o $(AL2).o $(JA).o $(T2).o
	g++ -std=c++11 -ggdb $(JA).o $(JI).o $(JO).o $(A).o $(AL).o $(T).o $(A2).o $(AL2).o $(T2).o $(M).o -o $(M).x
	./$(M).x

# dependencies for JSONArray
$(JA).o: $(JA).hpp $(JA).cpp
	g++ -std=c++11 -ggdb -c -o $(JA).o $(JA).cpp

# dependencies for JSONDataObject
$(JO).o: $(JO).hpp $(JO).cpp
	g++ -std=c++11 -ggdb -c -o $(JO).o $(JO).cpp

# dependencies for JSONDataItem
$(JI).o: $(JI).hpp $(JI).cpp
	g++ -std=c++11 -ggdb -c -o $(JI).o $(JI).cpp

# dependencies for Artist
$(A).o: $(A).hpp $(A).cpp
	g++ -std=c++11 -ggdb -c -o $(A).o $(A).cpp

# dependencies for Artists
$(A2).o: $(A2).hpp $(A2).cpp $(JO).hpp $(JO).cpp
	g++ -std=c++11 -ggdb -c -o $(A2).o $(A2).cpp

# dependencies for Album
$(AL).o: $(AL).hpp $(AL).cpp
	g++ -std=c++11 -ggdb -c -o $(AL).o $(AL).cpp

# dependencies for Albums
$(AL2).o: $(AL2).hpp $(AL2).cpp $(JO).hpp $(JO).cpp
	g++ -std=c++11 -ggdb -c -o $(AL2).o $(AL2).cpp

# dependencies for Track
$(T).o: $(T).hpp $(T).cpp
	g++ -std=c++11 -ggdb -c -o $(T).o $(T).cpp

# dependencies for Tracks
$(T2).o: $(T2).hpp $(T2).cpp $(JO).hpp $(JO).cpp
	g++ -std=c++11 -ggdb -c -o $(T2).o $(T2).cpp

# dependencies for main (testing program)
$(M).o: $(M).cpp $(JI).hpp $(JO).hpp $(A).hpp $(AL).hpp $(T).hpp $(A2).hpp $(AL2).hpp $(JA).hpp $(T2).hpp
	g++ -std=c++11 -ggdb -c -o $(M).o $(M).cpp

# clean
clean:
	rm -f *.o *.x *~

# submit
submit: $(A).hpp $(A).cpp $(AL).hpp $(AL).cpp $(T).hpp $(T).cpp $(M).cpp $(JI).hpp $(JI).cpp $(JO).hpp $(JO).cpp $(A2).hpp $(A2).cpp $(AL2).hpp $(AL2).cpp $(T2).hpp $(T2).cpp $(M).cpp $(JA).hpp $(JA).cpp $(AI).hpp $(AI).cpp $(AI2).hpp $(AI2).cpp $(ALI).hpp $(ALI).cpp makefile README.txt html_albums
	rm -r P3
	mkdir P3
	cp README.txt P3
	cp -r html_albums P3
	cp $(A).hpp P3
	cp $(A).cpp P3
	cp $(A2).hpp P3
	cp $(A2).cpp P3
	cp $(AL).hpp P3
	cp $(AL).cpp P3
	cp $(AL2).hpp P3
	cp $(AL2).cpp P3
	cp $(T).hpp P3
	cp $(T).cpp P3
	cp $(T2).hpp P3
	cp $(T2).cpp P3
	cp $(JI).hpp P3
	cp $(JI).cpp P3
	cp $(JO).hpp P3
	cp $(JO).cpp P3
	cp $(JA).hpp P3
	cp $(JA).cpp P3
	cp $(M).cpp P3
	cp $(AI).cpp P3
	cp $(AI).hpp P3
	cp $(AI2).cpp P3
	cp $(AI2).hpp P3
	cp $(ALI).cpp P3
	cp $(ALI).hpp P3
	cp makefile P3
	tar cfvz proj3.tar P3
	#~srivoire/bin/submit 315
