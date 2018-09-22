from sys import argv
from glob import glob

def make_dictionary(source=None):
    files = None
    if source is not None:
        files = glob (source, recursive=True)
    else:
        files = glob ('../../linter/outputfiles/*.txt', recursive=True)
    
    

if __name__ == "__main__":
    if len(argv) == 1: make_dictionary()
    elif len(argv) == 2: make_dictionary(argv[1])
    else: raise ValueError ("Too many arguments")
