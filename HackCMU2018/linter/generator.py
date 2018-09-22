import os

if __name__ == "__main__":
    filelist = os.listdir("../../files")
    #filelist = os.listdir(".")
    newlist = []
    for names in filelist:
        if names.endswith(".cpp"):
            newlist.append(names)
    for f in newlist:
        subprocess.run("./cpplint.py", "--verbose=0", "f")
