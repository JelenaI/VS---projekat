# VS---projekat

U ovom projektu je napravljen novi algoritam pretrage u KLEE-u.
Prevodjenje i pokretanje:
  Da bi projekat mogao da se pokrene neophodno je da se na računaru nalazi već skinut i izbildovan KLEE. Ukoliko to nije slučaj,    detaljan postupak se može naći na: https://github.com/tum-i22/klee-install.
  Nakon uspešnog bildovanja KLEE-a, neophodno je zameniti postojeće fajlove u klee direktorijumu sa fajlovima koji se nalaze u ovom repozitorijumu. Fajlove UserSearcher.cpp, Searcher.cpp, Searcher.h i ExecutionState.cpp potrebno je zameniti u direktorijumu /klee/lib/Core, a fajl ExecutionState.h u direktorijumu /klee/include/klee. Nakon toga je potrebno opet bildovati klee, tj. ponovo odraditi:
  
    BUILDDIR=`pwd`
    cd klee
    ./configure \
     LDFLAGS="-L$BUILDDIR/minisat/build/release/lib/" \
     --with-llvm=$BUILDDIR/llvm/ \
     --with-llvmcc=$BUILDDIR/llvm/Release/bin/clang \
     --with-llvmcxx=$BUILDDIR/llvm/Release/bin/clang++ \
     --with-stp=$BUILDDIR/stp/build/ \
     --with-uclibc=$BUILDDIR/klee-uclibc \
     --with-z3=$BUILDDIR/z3/build/ \
     --enable-cxx11 \
     --enable-posix-runtime
     
    make -j `nproc` ENABLE_OPTIMIZED=1
    
    # Copy Z3 libraries to a place, where klee can find them
    cp ../z3/build/lib/libz3.so ./Release+Asserts/lib/
    
    make -j `nproc` check

  Da bismo pokrenuli neki program sa klee alatom potrebno je prvo da pripremimo program za simboličko izvršavanje, tj. potrebno je da uradimo:
  1.  uključiti zaglavlje klee/klee.h
  2.  umesto učitavanja vrednosti promenljive koja nas zanima, označiti je simboličkom pomoću funkcije klee_make_symbolic
  3.  umesto korišćenja eksterne funkcije za ispis koju naš alat ne može da proveri, povratnu vrednost funkcija ćemo vraćati preko povratne vrednosti funkcije main
  Argumenti funkcije klee_make_symbolic, redom:
  1.  adresa promenljive
  2.  veličina promenljive
  3.  naziv promenljive (proizvoljna niska karaktera)
  
  Pomoću alata clang za koji je uveden alias myclang se generiše llvm kod pod nazivom ime.bc sa kojim radi klee alat:
  
    myclang -I ∼/klee/klee/include/ -emit-llvm -c -g ime.c
  
  Nakon ovoga pokrećemo klee preko aliasa myklee:
    
    myklee ime.bc
  
  Statističke informacije u vezi sa izvršavanjem klee alata nad nekim bitkodom, kao što su broj izvršenih instrukcija, pokrivenost instukcija bitkoda, pokrivenost grana bitkoda i slično, možemo dobiti pomoću Python skripta klee-stats (alias koji koristimo je myklee-stats). Informacije se prikazuju u tabelarnoj formi.  Ovaj alat se poziva nad direktorijumom koji je generisao klee. Da bismo bili sigurni da je to najnovija verzija direktorijuma, najjednostavnije je alat pozvati sa argumentom klee-last.
  
    myklee-stats klee-last

Korišćenje:
  Upotrebu klee alata u našem projektu smo automatizovali upotrebom skripta measure_time.sh. Skript koristimo na primer na sledeći način (detaljnije o načinu upotrebe i značenju promenljivih se može naći u zaglavlju skripta):
  
    ./measure_time.sh nas yes 15

Test primeri i skript se mogu naći u direktorijumu primeri.

Primeri:
  Primeri koje smo mi koristili se mogu naći u direktorijumu primeri, detaljnije o njima se može naći u fajlu SystemDescription.pdf u sekciji primeri. Uopšteno se može koristiti bilo koji c kod uz primenu prethodo opisanih instrukcija za pripremu pokreatanja programa sa klee alatom.
