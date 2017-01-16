#!/usr/bin/python

import cgi
import cgitb
cgitb.enable()

form = cgi.FieldStorage()

filename="/home/2015/sjessa3/public_html/cgi-bin/ass4/friends.txt"
with open('filename') as f:
	lines = [line.rstrip('\n') for line in open('filename')]
	
