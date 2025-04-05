all:
	gcc -ggdb -Werror -pg -Wextra -std=gnu11 -Wno-unused-result -mglibc -Wuninitialized -march=x86-64 -Wpedantic -Wall -o cleiton_guilhermite_erros_dicotomia_newtonraphson_1_5 cleiton_guilhermite_erros_dicotomia_newtonraphson_1_5.c -lm
	gcc -ggdb -Werror -pg -Wextra -std=gnu11 -Wno-unused-result -mglibc -Wuninitialized -march=x86-64 -Wpedantic -Wall -o cleiton_guilhermite_erros_dicotomia_newtonraphson_6_8 cleiton_guilhermite_erros_dicotomia_newtonraphson_6_8.c -lm
clean:
	rm -vf cleiton_guilhermite_erros_dicotomia_newtonraphson_1_5 
	rm -vf cleiton_guilhermite_erros_dicotomia_newtonraphson_6_8