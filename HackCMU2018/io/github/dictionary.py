from sys import argv
from glob import glob
from ml import parse_input
import pickle

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
        f_stream.readline()
        f_stream.readline()
        for line in f_stream.readlines():
            tokens = parse_input.parse_tokens(line)
            for token in tokens:
                if not (token in dict):
                    dict[token] = counter
                    counter = counter + 1
                    print(counter)
    
    with open('../../res/dictionaries/dictionary.bin', 'wb') as handle:
        pickle.dump(dict, handle, protocol=pickle.HIGHEST_PROTOCOL)
    
    return dict

if __name__ == "__main__":
    if len(argv) == 1: make_dictionary()
    elif len(argv) == 2: make_dictionary(argv[1])
    else: raise ValueError ("Too many arguments")
