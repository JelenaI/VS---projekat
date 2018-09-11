CLANG_FLAGS=-I ~/klee/klee/include -emit-llvm -c -g
CLANG=~/klee/llvm/Release/bin/clang

default: ex011-2.bc ex015-1.bc ex005-v.bc ex010-1.bc ex011-v.bc ex015-2.bc ex002-1.bc ex010-2.bc ex012-1.bc ex015-v.bc ex002-2.bc ex010-v.bc ex012-2.bc ex002-v.bc 	ex005-1.bc ex011-1.bc ex012-v.bc ex005-2.bc ex020-even.bc ex021-inverse.bc ex022-maze.bc ex023-password.bc ex024-pointer.bc ex025-armstrong.bc ex026-guess_game.bc ex027-misionari.bc ex028-solution.bc ex029-pozdrav.bc

ex002-1.bc: ex002-1.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex002-2.bc: ex002-2.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex002-v.bc: ex002-v.c
	$(CLANG) $(CLANG_FLAGS) $< 


ex005-1.bc: ex005-1.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex005-2.bc: ex005-2.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex005-v.bc: ex005-v.c
	$(CLANG) $(CLANG_FLAGS) $< 


ex010-1.bc: ex010-1.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex010-2.bc: ex010-2.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex010-v.bc: ex010-v.c
	$(CLANG) $(CLANG_FLAGS) $< 


ex011-1.bc: ex011-1.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex011-2.bc: ex011-2.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex011-v.bc: ex011-v.c
	$(CLANG) $(CLANG_FLAGS) $< 


ex012-1.bc: ex012-1.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex012-2.bc: ex012-2.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex012-v.bc: ex012-v.c
	$(CLANG) $(CLANG_FLAGS) $< 


ex015-1.bc: ex015-1.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex015-2.bc: ex015-2.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex015-v.bc: ex015-v.c
	$(CLANG) $(CLANG_FLAGS) $< 


ex020-even.bc: ex020-even.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex021-inverse.bc: ex021-inverse.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex022-maze.bc: ex022-maze.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex023-password.bc: ex023-password.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex024-pointer.bc: ex024-pointer.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex025-armstrong.bc: ex025-armstrong.c
	$(CLANG) $(CLANG_FLAGS) $< 
	
ex026-guess_game.bc: ex026-guess_game.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex027-misionari.bc: ex027-misionari.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex028-solution.bc: ex028-solution.c
	$(CLANG) $(CLANG_FLAGS) $< 

ex029-pozdrav.bc: ex029-pozdrav.c
	$(CLANG) $(CLANG_FLAGS) $< 


clean:
	$(RM) *.bc *.*~	 
	$(RM) -r  klee-*
	
