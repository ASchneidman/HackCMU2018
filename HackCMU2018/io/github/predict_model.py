from sys import argv
from functools import reduce
from ml import agent
from ml import parse_input

MAX = 2500
    
def runPredictML(agent_src, data):
    print ("Made it here")
    ml_agent = agent.Agent (agent_src, None)
    parser = parse_input.ParseInput(MAX)
    file_data = parser.parse_data (data)
    ml_agent.run_prediction(file_data)


if __name__ == "__main__":
    if len(argv) == 1: 
        raise ValueError ('usage: train_model.py path/to/agent path/to/data (optional)')
    else: 
        runPredictML(argv[1], argv[2])
