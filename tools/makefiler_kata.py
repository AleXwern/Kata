# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefiler_kata.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 09:09:34 by alexwern          #+#    #+#              #
#    Updated: 2022/09/16 13:18:06 by alexwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import os

sub = open(sys.path[0] + "/katasub").read()
top = open(sys.path[0] + "/katatop").read()
projects = open(sys.path[0] + "/folders.conf").read().splitlines()

def create_main_makefile():
	tests = ''
	for test in projects:
		tests += test + '_test.exe '
	srcs = ''
	for src in projects:
		srcs += src + '_test.cpp '
	includes = ''
	for include in projects:
		includes += '-I ' + include + '/includes '
	subprojects = ''
	for subproject in projects:
		subprojects += '	@make -C ' + subproject + ' all\n'
	builds = ''
	for build in projects:
		builds += '	@g++ $(FLAG) -o build/{0}_test.exe $(INCLS) obj/{0}_test.o {0}/obj/{0}.o $(CATCH) $(LIBFT)\n'.format(build)
	cleans = ''
	for clean in projects:
		cleans += '	@make -C {0} clean\n'.format(clean)
	fcleans = ''
	for fclean in projects:
		fcleans += '	@make -C {0} fclean\n'.format(fclean)
	makefile = open(sys.path[0] + "/../Makefile", "w")
	makefile.write(top.format(tests, srcs, includes, subprojects, builds, cleans, fcleans))
	makefile.close()

def create_sub_makefile(name):
	if '.cpp' in os.walk('./{}/src'.format(name)).next()[2][0]:
		ext = '.cpp'
	else:
		ext = '.c'
	files = ''
	for src in os.walk('./{}/src'.format(name)).next()[2]:
		files += src + ' '
	makefile = open("{0}/../{1}/Makefile".format(sys.path[0], name), "w")
	makefile.write(sub.format(name, files, ext))
	makefile.close()

def	main():
	create_main_makefile()
	for name in projects:
		create_sub_makefile(name)

if __name__ == "__main__":
	main()