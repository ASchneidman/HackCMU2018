import os
import subprocess

if __name__ == "__main__":
    filelist = os.listdir("../crawler/cpp_files")
    #filelist = os.listdir(".")
    # newlist = []
    # for names in filelist:
    #     if names.endswith(".cpp"):
    #         newlist.append(names)
    for f in filelist:
        file = "../crawler/cpp_files/" + f
        subprocess.call(["./cpplint.py", "--verbose=2", file])
