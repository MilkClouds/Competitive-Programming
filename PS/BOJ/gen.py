import glob, os

for fileName in glob.glob("milkclouds/*"):
	with open("source code in milkclouds folder.txt", "w") as file:
		file.write(fileName)
	os.system("git add -A")
	os.system("git commit -m %d" % int(fileName[11:]))
	os.system("git push")
