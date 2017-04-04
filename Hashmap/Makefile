build: tema1.exe 
	
tema1.exe: tema1.obj list.obj hash.lib
	cl hash.lib tema1.obj list.obj
	
tema1.obj:
	cl /c tema1.c

list.obj:
	cl /c list.c
	
clean:	
	del tema1.exe tema1.obj list.obj
