from sys import argv
from ml import agent
from ml import parse_input

MAX = 1000

def runML(agent_src, data = '../../linter/outputfiles'):
    ml_agent = agent.Agent (agent_src)
    print ("Starting parser")
    parser = parse_input.ParseInput(MAX)
    data = parser.parse_data (data)
    print ("Ending parser, starting agent")
    #for i in range(100):
    #    ml_agent.load_model()
    #    ml_agent.mutate_model((i % 10) / 100.0)
        #fitness.append((ml_agent.get_model(), ml_agent.run_model(data, 100)))
    #(model, score) = reduce (lambda t1, t2: t1[0] if t1[1] >= t2[1] else t2[1], fitness)
    #ml_agent.set_model(model)
    fitness = ml_agent.run_model(data, 50, save=True)
    print ("Fitness: " + str(fitness))



if __name__ == "__main__":
    if len(argv) == 1: raise ValueError ('usage: train_model.py path/to/agent path/to/data (optional)')
    elif len(argv) == 2: runML(argv[1])
    else: runML(argv[1], argv[2])
