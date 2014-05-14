#!/bin/python

#--------------------------------------------------------------------------------#
# The purpose of this script is to extract required lines from a file
#--------------------------------------------------------------------------------#

import sys
import string
import re

if ( len(sys.argv) == 1 ):
	print "Usage: extract-lines.py <input_file> <line_no_list_file>"
	sys.exit()
	
#---- this is the file from which the sentences are to be extracted ----#
input_file_lines = open(sys.argv[1]).readlines()

#---- this is the file with the list of lines numbers that are to be extracted from the input file ----#
lines_list       = open(sys.argv[2]).readlines()


for i in range(0, len(lines_list)):
	line = string.strip(input_file_lines[string.atoi(lines_list[i])])

	#--- replace slash and underscore back ---#
	line = re.sub(r"-SLASH-", r"/", line)
	line = re.sub(r"-UNDERSCORE-", r"_", line)

	print line