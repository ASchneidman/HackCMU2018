from sys import argv
from glob import glob
from parse_input import parse_tokens

def make_dictionary(source=None):
    counter = 0
    files = None
    if source is not None:
        files = glob (source, recursive=True)
    else:
        files = glob ('../../linter/outputfiles/*.txt', recursive=True)
    dict = {}
    for f in files:
        f_stream = open(f, "r", encoding = "ISO-8859-1")
        f_stream.readline().readline()
        for line in f_stream.readlines():
            tokens = parse_tokens(line)
            for token in tokens:
                if not (token in dict):
                    dict[token] = counter
                    counter = counter + 1
    return dict

if __name__ == "__main__":
    if len(argv) == 1: make_dictionary()
    elif len(argv) == 2: make_dictionary(argv[1])
    else: raise ValueError ("Too many arguments")
