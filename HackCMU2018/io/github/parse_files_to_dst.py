from sys import argv
from ml import parse_input
import pickle
import os

def parse_pls(src= '../../linter/outputfiles', 
              dst='../../res/parsed_inputs/parsed_files.bin'):
    if not os.path.isfile(dst):
        open(dst, 'r+').close()
    parser = parse_input.ParseInput(1000)
    data = parser.parse_data(src)
    with open(dst, "wb") as handle:
        pickle.dump(data, handle, protocol=pickle.HIGHEST_PROTOCOL)

if __name__ == "__main__":
    if (len (argv)) == 1: parse_pls()
    elif (len (argv)) == 2: parse_pls(argv[1])
    elif (len (argv)) == 3: parse_pls(argv[1], argv[2])
    else: raise ValueError("too many args")
