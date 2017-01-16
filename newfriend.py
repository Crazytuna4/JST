#!/usr/bin/python

import cgi
import cgitb
cgitb.enable()

print "Content-type: text/html\n\n"
print "<head>"
print "<title> Adding friends... </title>"
print "<link rel='stylesheet' type='text/css' href='http://cs.mcgill.ca/~sjessa3/cgi-bin/ass4/style.css'>"
print "</head>"
print "<body>"
print "<h1>Just Succulent Tuna</h1>"

#get username
form = cgi.FieldStorage()
if form.has_key("username") and form["username"].value != "":
        username = form["username"].value
print "<br>%s</br>" %username



#for debugging: COMMENT THIS

#get friends to add: UNCOMMENT THIS
#if form["friend"].value != "":
#              print "<h2> Please select chefs to add. Redirecting now. </h2>"
#               print "<meta http-equiv='refresh' contentt='1;url=%s'/>" %url

#for debugging:
#print "<br>%s</br>" %form["friend"]
#print "<br> 1: %s </br>" %form["friend"][0]

#get all values stored in friend key in form
#hardcoded: COMMENT THIS
#friends = "jvibyhal GreaterTuna selin123"

friendpassed = form.getvalue("friend", "")
if type(friendpassed) is type([]):
    #if multiple, then append them with space sep
    friends = " ".join(friendpassed)
    friendlist = friends.split(" ")
else:
    #only one friend specified
    friendlist = friendpassed

#FOR DEBUGGING
#friendlist = friends.split(" ")

url = "http://cgi.cs.mcgill.ca/~sjessa3/cgi-bin/ass4/dashboard.py?username=%s" %username

#if friendlist empty, redirect
if friendlist ==  "":
               print "<h2> Please select chefs to add. Redirecting now. </h2>"
               print "<meta http-equiv='refresh' contentt='1;url=%s'/>" %url

#for debugging: COMMENT THIS
print "<br>%s</br>" %friendlist
#print "<br>%s</br>" %friendpassed

#currently this appends whatever is stored in newline to the file
toAppend = ""
newline = ""
f1 = open("/home/2015/sjessa3/public_html/cgi-bin/ass4/friends.txt","r")
lines = f1.readlines()
for i, line in enumerate(lines):
    if line.startswith(username):
	if type(friendlist) is type([]):
		for j in range(0, len(friendlist),1):
			if friendlist[j] not in line:
        		        #print "newfriend:" + friendlist[j]
               			toAppend = toAppend + friendlist[j]
        	       	 	if j != len(friendlist):
                	   		toAppend = toAppend + " "
	else: toAppend = friendlist
        newline = lines[i].rstrip('\n') + " " + toAppend + "\n"
f1.close()
    #f1.write(newline)
f2 = open("/home/2015/sjessa3/public_html/cgi-bin/ass4/friends.txt","w")
for line in lines:
        if not line.startswith(username):
                f2.write(line)
f2.write(newline)
f2.close()

#for debugging: COMMENT THIS
#print newline

#when done, display message and refresh? UNCOMMENT
#print "<h2> %s added successfully! </h2>" %friendpassed
print "<meta http-equiv='refresh' content='1;url=%s'/>" %url
print "</body>"
print "</html>"
