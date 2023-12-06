.PHONY: 1 2 3 4

TEST ?= test_00

1:
	g++ -std=c++17 project_02_01/main.cpp -o project_02_01/main.exe
	project_02_01/main.exe project_02_01/$(TEST).inp
2:
	g++ -std=c++17 project_02_02/main.cpp -o project_02_02/main.exe
	project_02_02/main.exe project_02_02/$(TEST).inp
3:
	g++ -std=c++17 project_02_03/main.cpp -o project_02_03/main.exe
	project_02_03/main.exe project_02_03/$(TEST).inp
4:
	g++ -std=c++17 project_02_04/main.cpp -o project_02_04/main.exe
	project_02_04/main.exe project_02_04/$(TEST).inp

test1: 1
	py test.py project_02_01
	
test2: 2
	py test.py project_02_02

test3: 3
	py test.py project_02_03

test4: 4
	py test.py project_02_04
